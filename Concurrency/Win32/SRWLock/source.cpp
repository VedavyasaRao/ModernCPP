#include <windows.h>
#include <tchar.h>
#include <strsafe.h>

#define BUF_SIZE 255
#define  MAX_COUNTER 25
#define  MAX_THREADS 2

DWORD WINAPI IncrementerFunction(LPVOID lpParam);
DWORD WINAPI ConsoleWriterFunction(LPVOID lpParam);

SRWLOCK  srw = {};
int	wcounter = { 1 };
int rcounter = { 1 };

struct SharedSRWHelper
{
	SharedSRWHelper()
	{
		AcquireSRWLockShared(&srw);
	}
	~SharedSRWHelper()
	{
		ReleaseSRWLockShared(&srw);
	}
};

struct ExclusiveSRWHelper
{
	ExclusiveSRWHelper()
	{
		AcquireSRWLockExclusive(&srw);
	}
	~ExclusiveSRWHelper()
	{
		ReleaseSRWLockExclusive(&srw);
	}
};

int _tmain()
{
	auto start_time = GetTickCount();
	HANDLE  hThread[MAX_THREADS];
	InitializeSRWLock(&srw);

	for (int i = 0; i < MAX_THREADS; ++i)
	{
		hThread[i] = CreateThread(NULL, 0, ((i == 0) ? IncrementerFunction : ConsoleWriterFunction),
			NULL, NULL, NULL);
		if (hThread[i] == NULL)
		{
			return 1;
		}
	}

	WaitForMultipleObjects(MAX_THREADS, hThread, TRUE, INFINITE);

	for (int i = 0; i < MAX_THREADS; ++i)
	{
		CloseHandle(hThread[i]);
	}

	printf("\nElapsed Time = %d MilliSeconds\n", (GetTickCount() - start_time));
	return 0;
}


DWORD WINAPI IncrementerFunction(LPVOID lpParam)
{
	DWORD tid = GetCurrentThreadId();
	while (true)
	{
		ExclusiveSRWHelper csh;
		if (wcounter > MAX_COUNTER)
			break;
		++wcounter;
		::Sleep(5);
	}
	return 0;
}

DWORD WINAPI ConsoleWriterFunction(LPVOID lpParam)
{
	HANDLE hStdout;
	DWORD tid = GetCurrentThreadId();
	TCHAR Format[] = TEXT("Thread Id %6ld: Value=%02d\n");
	TCHAR msgBuf[BUF_SIZE];
	size_t cchStringSize;
	DWORD dwChars;

	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdout == INVALID_HANDLE_VALUE)
		return 1;

	while (true)
	{
		SharedSRWHelper csh;
		if (rcounter > MAX_COUNTER)
			break;

		if (rcounter != wcounter)
		{
			HRESULT hr = StringCchPrintf(msgBuf, BUF_SIZE, Format, tid, rcounter++);
			StringCchLength(msgBuf, BUF_SIZE, &cchStringSize);
			WriteConsole(hStdout, msgBuf, (DWORD)cchStringSize, &dwChars, NULL);
		}
	}
	return 0;
}