




#define _WIN32_WINNT 0x0400

#include <stdio.h>
#include <tchar.h>
#include <Windows.h>

int _tmain(int argc, TCHAR* argv[])
{
	HANDLE hTimer = NULL;
	LARGE_INTEGER liDueTime;

	liDueTime.QuadPart = -100000000;

	// Ÿ�̸� ������Ʈ ����
	hTimer = CreateWaitableTimer(NULL, FALSE, _T("WaitableTimer"));

	if (!hTimer)
	{
		_tprintf(_T("CreateWaitableTimer failed (%d) \n"), GetLastError());
		return 1;
	}
	_tprintf(_T("Waiting for 10 seconds ... \n"));

	// Ÿ�̸��� �˶��� 10�ʷ� ����
	SetWaitableTimer(hTimer, &liDueTime, 0, NULL, NULL, FALSE);

	// Ÿ�̸��� �˶��� ���
	WaitForSingleObject(hTimer, INFINITE);
	_tprintf(_T("Timer was signaled. \n"));
	MessageBeep(MB_ICONEXCLAMATION);

	return 0;
}