#include <windows.h>
#include <tchar.h>
#include <strsafe.h>

#define BUF_SIZE 255
#define  MAX_COUNTER 25
#define  MAX_THREADS 2

DWORD WINAPI IncrementerFunction(LPVOID lpParam);
DWORD WINAPI WriterFunction(LPVOID lpParam);

CRITICAL_SECTION cs = {};
CONDITION_VARIABLE IncrementerVar;
CONDITION_VARIABLE WriterVar;

int counter = 0;

struct CSHelper
{
	CSHelper()
	{
		EnterCriticalSection(&cs);
	}
	~CSHelper()
	{
		LeaveCriticalSection(&cs);
	}
};


int _tmain()
{
	auto start_time = GetTickCount();
	HANDLE  hThread[MAX_THREADS];

	InitializeCriticalSection(&cs);
	InitializeConditionVariable(&IncrementerVar);
	InitializeConditionVariable(&WriterVar);

	for (int i = 0; i < MAX_THREADS; ++i)
	{
		hThread[i] = CreateThread(NULL, 0, ((i == 0) ? IncrementerFunction : WriterFunction),
			NULL, NULL, NULL);
		if (hThread[i] == NULL)
		{
			return 1;
		}
		::Sleep(100);
	}

	WaitForMultipleObjects(MAX_THREADS, hThread, TRUE, INFINITE);

	for (int i = 0; i < MAX_THREADS; ++i)
	{
		CloseHandle(hThread[i]);
	}
	DeleteCriticalSection(&cs);

	printf("\nElapsed Time = %d MilliSeconds\n", (GetTickCount() - start_time));
	return 0;
}

DWORD WINAPI IncrementerFunction(LPVOID lpParam)
{
	while (true)
	{
		CSHelper csh;
		if (counter > MAX_COUNTER)
		{
			WakeConditionVariable(&WriterVar);
			break;
		}
		++counter;
		WakeConditionVariable(&WriterVar);
		SleepConditionVariableCS(&IncrementerVar, &cs, INFINITE);
	}
	return 0;
}


DWORD WINAPI WriterFunction(LPVOID lpParam)
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
		CSHelper csh;
		if (counter > MAX_COUNTER)
		{
			WakeConditionVariable(&IncrementerVar);
			break;
		}

		if (counter != 0)
		{
			HRESULT hr = StringCchPrintf(msgBuf, BUF_SIZE, Format, tid, counter);

			StringCchLength(msgBuf, BUF_SIZE, &cchStringSize);
			WriteConsole(hStdout, msgBuf, (DWORD)cchStringSize, &dwChars, NULL);
		}
		WakeConditionVariable(&IncrementerVar);
		SleepConditionVariableCS(&WriterVar, &cs, INFINITE);
	}
	return 0;
}