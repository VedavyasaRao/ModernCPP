#include <windows.h>
#include <tchar.h>
#include <strsafe.h>

#define  MAX_COUNTER 25
#define  MAX_THREADS 2

DWORD WINAPI ConsoleWriterFunction(LPVOID lpParam);
HANDLE hSemaphore = {};
int counter = 1;

struct SemaphoreHelper
{
	SemaphoreHelper()
	{
		WaitForSingleObject(hSemaphore, INFINITE);
	}
	~SemaphoreHelper()
	{
		ReleaseSemaphore(hSemaphore, 1, NULL);
	}
};

int _tmain()
{
	auto start_time = GetTickCount();
	HANDLE  hThread[MAX_THREADS];

	hSemaphore = CreateSemaphore(NULL, 1, MAX_THREADS, NULL);
	if (hSemaphore == NULL)
	{
		return 1;
	}

	for (int i = 0; i < MAX_THREADS; ++i)
	{
		hThread[i] = CreateThread(NULL, 0, ConsoleWriterFunction, NULL, NULL, NULL);
		if (hThread[i] == NULL)
		{
			return 2;
		}
	}

	WaitForMultipleObjects(MAX_THREADS, hThread, TRUE, INFINITE);

	for (int i = 0; i < MAX_THREADS; ++i)
	{
		CloseHandle(hThread[i]);
	}

	CloseHandle(hSemaphore);

	printf("\nElapsed Time = %d MilliSeconds\n", (GetTickCount() - start_time));
	return 0;

}
DWORD WINAPI ConsoleWriterFunction(LPVOID lpParam)
{
	DWORD tid = GetCurrentThreadId();

	while (true)
	{
		{
			SemaphoreHelper eh;

			if (counter > MAX_COUNTER)
				break;

			printf("Thread Id %6ld: Value=%02d\n", tid, counter++);

		}
		::Sleep(5);
	}
	return 0;
}

