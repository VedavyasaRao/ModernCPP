#include <windows.h>
#include <tchar.h>
#include <strsafe.h>

#define BUF_SIZE 255
#define  MAX_COUNTER 25
#define  MAX_THREADS 1

DWORD WINAPI ConsoleWriterFunction(LPVOID lpParam);
int counter = 1;

int _tmain()
{
	HANDLE  hThread[MAX_THREADS];

	for (int i = 0; i < MAX_THREADS; ++i)
	{
		//create thread
		hThread[i] = CreateThread(
			NULL,                   // default security attributes
			0,                      // use default stack size  
			ConsoleWriterFunction,       // thread function name
			NULL,		 // argument to thread function 
			NULL,					//default creation flags
			NULL);          // returns the thread identifier 

							// Check the return value for success.
							// If CreateThread fails, terminate execution. 
							// This will automatically clean up threads and memory. 
		if (hThread[i] == NULL)
		{
			ExitProcess(3);
		}
	}

	// Wait until all threads have terminated.
	WaitForMultipleObjects(MAX_THREADS, hThread, TRUE, INFINITE);

	for (int i = 0; i < MAX_THREADS; ++i)
	{
		// Close all thread handles and free memory allocations.
		CloseHandle(hThread[i]);
	}

	return 0;
}

DWORD WINAPI ConsoleWriterFunction(LPVOID lpParam)
{
	HANDLE hStdout;
	DWORD tid = GetCurrentThreadId();
	while (true)
	{
		try
		{
			if (counter > MAX_COUNTER)
				throw 1;

			TCHAR msgBuf[BUF_SIZE];
			size_t cchStringSize;
			DWORD dwChars;

			// Make sure there is a console to receive output results. 
			hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
			if (hStdout == INVALID_HANDLE_VALUE)
				throw 2;

			HRESULT hr = StringCchPrintf(msgBuf, BUF_SIZE, TEXT("Thread Id %6ld: Value=%02d\n"),
				tid, counter++);
			// Print the parameter values using thread-safe functions.
			StringCchLength(msgBuf, BUF_SIZE, &cchStringSize);
			WriteConsole(hStdout, msgBuf, (DWORD)cchStringSize, &dwChars, NULL);
		}
		catch (...)
		{
			return 1;
		}
	}
	return 0;
}