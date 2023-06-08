#include <windows.h>
#include <tchar.h>
#include <strsafe.h>

#define  MAX_COUNTER 25
#define  MAX_THREADS 2

DWORD WINAPI ConsoleWriterFunction(LPVOID lpParam);
CRITICAL_SECTION cs = {};
int counter = 1;

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

	for (int i = 0; i < MAX_THREADS; ++i)
	{
		hThread[i] = CreateThread(NULL, 0, ConsoleWriterFunction, NULL, NULL, NULL);
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
	DeleteCriticalSection(&cs);

	printf("\nElapsed Time = %d MilliSeconds\n", (GetTickCount() - start_time));
	return 0;
}

DWORD WINAPI ConsoleWriterFunction(LPVOID lpParam)
{
	DWORD tid = GetCurrentThreadId();
	TCHAR Format[] = TEXT("Thread Id %6ld: Value=%02d\n");

	while (true)
	{
		{
			CSHelper csh;

			if (counter > MAX_COUNTER)
				break;

			printf("Thread Id %6ld: Value=%02d\n",tid,counter++);

		}
		::Sleep(5);
	}
	return 0;
}
