




#include <stdio.h>
#include <tchar.h>
#include <windows.h>
#include <process.h>

HANDLE hMutex;
DWORD dwWaitResult;

void ProcessBaseCriticalSection()
{
	dwWaitResult = WaitForSingleObject(hMutex, INFINITE);

	switch (dwWaitResult)
	{
		// 쓰레드가 뮤텍스를 소유하였다
	case WAIT_OBJECT_0:
		_tprintf(_T("thread got mutex ! \n"));
		break;

		// time-out 발생하였다.
	case WAIT_TIMEOUT:
		_tprintf(_T("timer expired ! \n"));
		return;

		// 뮤텍스 반환이 적절이 이뤄지지 않았다.
	case WAIT_ABANDONED:
		return;
	}

	for (DWORD i = 0; i < 5; i++)
	{
		_tprintf(_T("Thread Running! \n"));
		Sleep(100);
	}

	ReleaseMutex(hMutex);
}

int _tmain(int argc, TCHAR* argv[])
{
#if 1
	hMutex = CreateMutex(
		NULL,
		FALSE,
		_T("NamedMutex") // named mutex
	);
#else 
	hMutex = OpenMutex(
		MUTEX_ALL_ACCESS, // 접근권한 요청
		FALSE, // 핸들을 상속하지 않겠다.
		_T("NamedMutex") // 뮤텍스 오브젝트 이름
	);
#endif

	if (hMutex == NULL)
	{
		_tprintf(_T("CreateMutex error : %d\n"), GetLastError());
		return -1;
	}

	ProcessBaseCriticalSection();

	CloseHandle(hMutex);
	return 0;
}