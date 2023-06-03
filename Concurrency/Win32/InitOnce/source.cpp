#include <windows.h>
#include <tchar.h>
#include <strsafe.h>

#define BUF_SIZE 255
#define  MAX_COUNTER 25
#define  MAX_THREADS 2

BOOL CALLBACK InitHandleFunction(PINIT_ONCE InitOnce, PVOID Parameter, PVOID *lpContext);
DWORD WINAPI ConsoleWriterFunction(LPVOID lpParam);
HANDLE hMutex = {};
int counter = 1;

INIT_ONCE g_InitOnce = INIT_ONCE_STATIC_INIT;


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

void InitMutex()
{
	PVOID lpContext;
	BOOL  bStatus;

	bStatus = InitOnceExecuteOnce(&g_InitOnce, InitHandleFunction, NULL, &lpContext);
}

BOOL CALLBACK InitHandleFunction(PINIT_ONCE InitOnce, PVOID Parameter, PVOID *lpContext)
{
	printf("Creating mutex %d\n\n", GetCurrentThreadId());
	hMutex = CreateMutex(NULL, FALSE, NULL);
	if (hMutex == NULL)
	{
		return FALSE;
	}
	return TRUE;
}


DWORD WINAPI ConsoleWriterFunction(LPVOID lpParam)
{
	InitMutex();
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
		{
			MutexHelper mh;

			if (counter > MAX_COUNTER)
				break;

			HRESULT hr = StringCchPrintf(msgBuf, BUF_SIZE, Format, tid, counter++);
			StringCchLength(msgBuf, BUF_SIZE, &cchStringSize);
			WriteConsole(hStdout, msgBuf, (DWORD)cchStringSize, &dwChars, NULL);
		}
		::Sleep(5);
	}
	return 0;
}