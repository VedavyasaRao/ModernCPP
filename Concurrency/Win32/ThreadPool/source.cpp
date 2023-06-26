#include <windows.h>
#include <tchar.h>
#include <strsafe.h>

#define		MAX_COUNTER 25

TP_CALLBACK_ENVIRON cbe = {};
VOID NTAPI ConsoleWriterFunction(PTP_CALLBACK_INSTANCE Instance, PVOID Context);
HANDLE hsyncEventHandle = {};

int _tmain()
{
	auto start_time = GetTickCount();
	InitializeThreadpoolEnvironment(&cbe);
	hsyncEventHandle = CreateEvent(NULL, FALSE, FALSE, NULL);
	if (hsyncEventHandle == NULL)
	{
		return 1;
	}

	for (int i = 1; i <= MAX_COUNTER; ++i)
	{
		TrySubmitThreadpoolCallback((PTP_SIMPLE_CALLBACK)ConsoleWriterFunction, (LPVOID)i, &cbe);
		WaitForSingleObject(hsyncEventHandle, INFINITE);
	}
	

	CloseHandle(hsyncEventHandle);
	DestroyThreadpoolEnvironment(&cbe);

	printf("\nElapsed Time = %d MilliSeconds\n", (GetTickCount() - start_time));
	return 0;
}

VOID NTAPI ConsoleWriterFunction(PTP_CALLBACK_INSTANCE Instance, PVOID Context)
{
	int counter = (int)Context;
	DWORD tid = GetCurrentThreadId();

	printf("Thread Id %6ld: Value=%02d\n",tid,counter);
	SetEvent(hsyncEventHandle);
	Sleep(5);
}

