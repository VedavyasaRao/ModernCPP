#include <windows.h>
#include <tchar.h>
#include <strsafe.h>

#define		MAX_COUNTER 25

DWORD CALLBACK ConsoleWriterFunction(LPVOID lpParam);
HANDLE hsyncEventHandle = {};

int _tmain()
{
	auto start_time = GetTickCount();

	hsyncEventHandle = CreateEvent(0, FALSE, FALSE, 0);
	if (hsyncEventHandle == NULL)
	{
		return 1;
	}

	::Sleep(10);
	for (int i = 1; i <= MAX_COUNTER; ++i)
	{
		BOOL b = QueueUserWorkItem(ConsoleWriterFunction, (LPVOID)i, WT_EXECUTEDEFAULT);
		WaitForSingleObject(hsyncEventHandle, INFINITE);
	}

	CloseHandle(hsyncEventHandle);

	printf("\nElapsed Time = %d MilliSeconds\n", (GetTickCount() - start_time));
	return 0;
}

DWORD CALLBACK ConsoleWriterFunction(LPVOID lpParam)
{
	int counter = (int)lpParam;
	DWORD tid = GetCurrentThreadId();

	printf("Thread Id %6ld: Value=%02d\n", tid, counter);

	SetEvent(hsyncEventHandle);
	return 0;
}