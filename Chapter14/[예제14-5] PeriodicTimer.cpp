




#define _WIN32_WINT0x0400

#include <stdio.h>
#include <tchar.h>
#include <Windows.h>

int _tmain(int argc, TCHAR* argv[])
{
	HANDLE hTimer = NULL;
	LARGE_INTEGER liDueTime;

	liDueTime.QuadPart = -10000000;

	// 타이머 오브젝트 생성
	hTimer =
		CreateWaitableTimer(NULL, FALSE, _T("WaitableTimer"));

	if (!hTimer)
	{
		_tprintf(_T("CreateWaitableTimer failed (%d) \n"), GetLastError());
		return 1;
	}

	_tprintf(_T("Waiting for 10 seconds... \n"));

	// 알람을 10 초 후에, 그리고 5초 간격으로 설정한다
	SetWaitableTimer(
		hTimer, &liDueTime, 5000, NULL, NULL, FALSE
	);

	// 타이머의 알람을 대기
	int stop = 0;
	while (1)
	{
		if (stop == 3) {
			CancelWaitableTimer(hTimer);
			printf("Timer is stop");
		}
		WaitForSingleObject(hTimer, INFINITE);
		_tprintf(_T("Timer was signaled. \n"));
		MessageBeep(MB_ICONEXCLAMATION);
		stop++;
	}
	return 0;
}