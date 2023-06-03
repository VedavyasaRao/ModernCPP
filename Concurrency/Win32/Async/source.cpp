#include <windows.h>
#include <tchar.h>
#include <strsafe.h>

#define		BUF_SIZE 255
#define		MAX_COUNTER 25

DWORD WINAPI APCThread(LPVOID lpParam);
void NTAPI ConsoleWriterFunction(ULONG_PTR Parameter);

int _tmain()
{
	auto start_time = GetTickCount();
	HANDLE  hThread;

	hThread = CreateThread(NULL, 0, APCThread, NULL, NULL, NULL);
	if (hThread == NULL)
	{
		return 1;
	}

	::Sleep(10);
	for (int i = 1; i <= MAX_COUNTER; ++i)
	{
		QueueUserAPC(ConsoleWriterFunction, hThread, (ULONG_PTR)i);
	}

	WaitForSingleObject(hThread, INFINITE);


	CloseHandle(hThread);

	printf("\nElapsed Time = %d MilliSeconds\n", (GetTickCount() - start_time));
	return 0;
}


DWORD WINAPI APCThread(LPVOID lpParam)
{
	SleepEx(INFINITE, TRUE);
	return 0;
}

void NTAPI ConsoleWriterFunction(ULONG_PTR Parameter)
{
	int counter = (int)Parameter;
	HANDLE hStdout;
	DWORD tid = GetCurrentThreadId();
	TCHAR Format[] = TEXT("Thread Id %6ld: Value=%02d\n");
	TCHAR msgBuf[BUF_SIZE];
	size_t cchStringSize;
	DWORD dwChars;

	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdout == INVALID_HANDLE_VALUE)
		return;

	HRESULT hr = StringCchPrintf(msgBuf, BUF_SIZE, Format, tid, counter);
	StringCchLength(msgBuf, BUF_SIZE, &cchStringSize);
	WriteConsole(hStdout, msgBuf, (DWORD)cchStringSize, &dwChars, NULL);
	::Sleep(5);
}