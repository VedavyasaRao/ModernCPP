#include <windows.h>
#include <tchar.h>
#include <strsafe.h>

#define BUF_SIZE 255
#define  MAX_COUNTER 25
#define  MAX_THREADS 2

DWORD WINAPI IncrementerFunction(LPVOID lpParam);
DWORD WINAPI WriterFunction(LPVOID lpParam);

CRITICAL_SECTION cs = {};
CONDITION_VARIABLE IncrementerVar;
CONDITION_VARIABLE WriterVar;

int counter = 0;

struct CSHelper
{
	CSHelper()
	{
		EnterCriticalSection(&cs);
	}
	~CSHelper()
	{
		LeaveCriticalSection(&cs);
	}
};


int _tmain()
{
	HANDLE  hThread[MAX_THREADS];

	InitializeCriticalSection(&cs);
	InitializeConditionVariable(&IncrementerVar);
	InitializeConditionVariable(&WriterVar);

	for (int i = 0; i < MAX_THREADS; ++i)
	{
		//create thread
		hThread[i] = CreateThread(
			NULL,                   // default security attributes
			0,                      // use default stack size  
			((i == 0) ? IncrementerFunction : WriterFunction),       // thread function name
			NULL,   // argument to thread function 
			NULL,					//default creation flags
			NULL);          // returns the thread identifier 

							// Check the return value for success.
							// If CreateThread fails, terminate execution. 
							// This will automatically clean up threads and memory. 
		if (hThread[i] == NULL)
		{
			ExitProcess(3);
		}
		::Sleep(100);
	}

	// Wait until all threads have terminated.
	WaitForMultipleObjects(MAX_THREADS, hThread, TRUE, INFINITE);

	for (int i = 0; i < MAX_THREADS; ++i)
	{
		// Close all thread handles and free memory allocations.
		CloseHandle(hThread[i]);
	}
	DeleteCriticalSection(&cs);

	return 0;
}

DWORD WINAPI IncrementerFunction(LPVOID lpParam)
{
	DWORD tid = GetCurrentThreadId();
	while (true)
	{
		CSHelper csh;
		try
		{
			if (counter > MAX_COUNTER)
				throw 1;
			++counter;
		}
		catch (...)
		{
			WakeConditionVariable(&WriterVar);
			return 1;
		}
		WakeConditionVariable(&WriterVar);
		SleepConditionVariableCS(&IncrementerVar, &cs, INFINITE);
	}
	return 0;
}


DWORD WINAPI WriterFunction(LPVOID lpParam)
{
	HANDLE hStdout;
	DWORD tid = GetCurrentThreadId();

	while (true)
	{
		CSHelper csh;
		try
		{
			if (counter > MAX_COUNTER)
				throw 1;

			if (counter != 0)
			{
				TCHAR msgBuf[BUF_SIZE];
				size_t cchStringSize;
				DWORD dwChars;

				// Make sure there is a console to receive output results. 
				hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
				if (hStdout == INVALID_HANDLE_VALUE)
					throw 2;

				HRESULT hr = StringCchPrintf(msgBuf, BUF_SIZE, TEXT("Thread Id %6ld: Value=%02d\n"),
					tid, counter);
				// Print the parameter values using thread-safe functions.
				StringCchLength(msgBuf, BUF_SIZE, &cchStringSize);
				WriteConsole(hStdout, msgBuf, (DWORD)cchStringSize, &dwChars, NULL);
			}
		}
		catch (...)
		{
			WakeConditionVariable(&IncrementerVar);
			return 1;
		}
		WakeConditionVariable(&IncrementerVar);
		SleepConditionVariableCS(&WriterVar, &cs, INFINITE);
	}
	return 0;
}