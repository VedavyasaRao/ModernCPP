#include <windows.h>
#include <tchar.h>
#include <strsafe.h>

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
	DWORD tid = GetCurrentThreadId();

	while (true)
	{
		SharedSRWHelper csh;
		if (rcounter > MAX_COUNTER)
			break;

		if (rcounter != wcounter)
		{
			printf("Thread Id %6ld: Value=%02d\n", tid, rcounter++);

		}
	}
	return 0;
}