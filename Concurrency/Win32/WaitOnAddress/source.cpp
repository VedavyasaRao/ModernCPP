#include <windows.h>
#include <tchar.h>
#include <strsafe.h>
#pragma comment( lib, "Synchronization.lib" )

#define  MAX_COUNTER 25
#define  MAX_THREADS 2

DWORD WINAPI IncrementerFunction(LPVOID lpParam);
DWORD WINAPI WriterFunction(LPVOID lpParam);

ULONG  IncrementerVar = {};
ULONG WriterVar = {};
ULONG DefaultVal = {};

int counter = 0;


int _tmain()
{
	auto start_time = GetTickCount();
	HANDLE  hThread[MAX_THREADS];

	for (int i = 0; i < MAX_THREADS; ++i)
	{
		hThread[i] = CreateThread(NULL, 0, ((i == 0) ? IncrementerFunction : WriterFunction),
			NULL, NULL, NULL);
		if (hThread[i] == NULL)
		{
			return 1;
		}
		Sleep(10);
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
	while (true)
	{
		if (counter > MAX_COUNTER)
		{
			WakeByAddressSingle(&WriterVar);
			break;
		}
		++counter;
		WakeByAddressSingle(&WriterVar);
		WaitOnAddress(&IncrementerVar, &DefaultVal, sizeof(ULONG), INFINITE);
	}
	return 0;
}


DWORD WINAPI WriterFunction(LPVOID lpParam)
{
	DWORD tid = GetCurrentThreadId();
	while (true)
	{
		if (counter > MAX_COUNTER)
		{
			WakeByAddressSingle(&IncrementerVar);
			break;
		}

		if (counter != 0)
		{
			printf("Thread Id %6ld: Value=%02d\n", tid, counter);
		}
		WakeByAddressSingle(&IncrementerVar);
		WaitOnAddress(&WriterVar, &DefaultVal, sizeof(ULONG), INFINITE);
	}
	return 0;
}
