#include <windows.h>
#include <tchar.h>
#include <strsafe.h>

#define		BUF_SIZE 255
#define		MAX_COUNTER 25

DWORD CALLBACK ConsoleWriterFunction(LPVOID lpParam);
HANDLE hsyncEventHandle = {};

int _tmain()
{
	auto start_time = GetTickCount();
	HANDLE  hThread;

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
	SetEvent(hsyncEventHandle);
	return 0;
}