




#include <stdio.h>
#include <tchar.h>
#include <windows.h>
#include <process.h>

unsigned int WINAPI ThreadProc(LPVOID lpParam)
{
	while (1)
	{
		_tprintf(_T("Running State! \n"));
		Sleep(10000);
	}
	return 0;
}

int _tmain(int argc, TCHAR* argv[])
{
	DWORD dwThreadId;
	HANDLE hThread;
	DWORD susCnt; // suspend count를 확인하기 위한 변수

	hThread = (HANDLE)_beginthreadex(NULL, 0, ThreadProc, NULL, CREATE_SUSPENDED, (unsigned*)&dwThreadId);

	// 쓰레드 생성 확인
	if (hThread == NULL) _tprintf(_T("Thread Creation fault! \n"));

	susCnt = ResumeThread(hThread); // Blocked -> Ready 상태
	_tprintf(_T("suspend count : %d \n"), susCnt);
	Sleep(10000);

	susCnt = SuspendThread(hThread); // Ready -> Blocked 상태
	_tprintf(_T("suspend count : %d \n"), susCnt);
	Sleep(10000);

	susCnt = SuspendThread(hThread);
	_tprintf(_T("suspend count : %d \n"), susCnt);
	Sleep(10000);

	susCnt = ResumeThread(hThread);
	_tprintf(_T("suspend count : %d \n"), susCnt);

	susCnt = ResumeThread(hThread);
	_tprintf(_T("suspend count : %d \n"), susCnt);

	WaitForSingleObject(hThread, INFINITE);
	return 0;
}