#include <windows.h>
#include <tchar.h>
#include <strsafe.h>

#define  MAX_COUNTER 25
#define  MAX_THREADS 2

BOOL CALLBACK InitHandleFunction(PINIT_ONCE InitOnce, PVOID Parameter, PVOID *lpContext);
DWORD WINAPI ConsoleWriterFunction(LPVOID lpParam);
HANDLE hMutex = {};
int counter = 1;

struct MutexHelper
{
	MutexHelper()
	{
		WaitForSingleObject(hMutex, INFINITE);
	}
	~MutexHelper()
	{
		ReleaseMutex(hMutex);
	}
};

int _tmain()
{
	auto start_time = GetTickCount();
	HANDLE  hThread[MAX_THREADS];

	hMutex = CreateMutex(NULL, FALSE, NULL);
	if (hMutex == NULL)
	{
		return FALSE;
	}

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

	CloseHandle(hMutex);
	printf("\nElapsed Time = %d MilliSeconds\n", (GetTickCount() - start_time));
	return 0;

}


DWORD WINAPI ConsoleWriterFunction(LPVOID lpParam)
{
	DWORD tid = GetCurrentThreadId();

	while (true)
	{
		{
			MutexHelper mh;

			if (counter > MAX_COUNTER)
				break;

			printf("Thread Id %6ld: Value=%02d\n", tid, counter++);

		}
		::Sleep(5);
	}
	return 0;
}