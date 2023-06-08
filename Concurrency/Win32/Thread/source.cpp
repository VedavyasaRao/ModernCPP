#include <windows.h>
#include <tchar.h>
#include <strsafe.h>
#include <ctime>

#define  MAX_COUNTER 25
#define  MAX_THREADS 1

DWORD WINAPI ConsoleWriterFunction(LPVOID lpParam);
int counter = 1;

int _tmain()
{
	auto start_time = GetTickCount();

	HANDLE  hThread[MAX_THREADS];

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
	printf("\nElapsed Time = %d MilliSeconds\n", (GetTickCount() - start_time));

	return 0;
}

DWORD WINAPI ConsoleWriterFunction(LPVOID lpParam)
{
	DWORD tid = GetCurrentThreadId();

	while (true)
	{
		if (counter > MAX_COUNTER)
			break;

		printf("Thread Id %6ld: Value=%02d\n", tid, counter++);

		::Sleep(5);
	}
	return 0;
}
