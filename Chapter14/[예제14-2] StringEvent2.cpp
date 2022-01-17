




#include <stdio.h>
#include <tchar.h>
#include <Windows.h>
#include <process.h> /* _beginthreadex, _endthreadex */

unsigned int WINAPI OutputThreadFunction(LPVOID lpParam);
unsigned int WINAPI CountThreadFunction(LPVOID lpParam);

TCHAR string[100];
HANDLE hEvent;

int _tmain(int argc, TCHAR* argv[])
{
	HANDLE hThread[2];
	DWORD dwThreadID[2];

	hEvent = CreateEvent( // event object ����
		NULL, // ��� �Ұ�
		TRUE, // auto-reset mode�� ����
		FALSE, // non-signaled ���·� ����
		NULL // �̸����� event
	);
	if (hEvent == NULL) {
		_fputts(_T("Event object creation error \n"), stdout);
		return -1;
	}

	hThread[0] = (HANDLE)_beginthreadex(
		NULL, 0,
		OutputThreadFunction,
		NULL, 0,
		(unsigned*)&dwThreadID[0]
	);

	hThread[1] = (HANDLE)_beginthreadex(
		NULL, 0,
		CountThreadFunction,
		NULL, 0,
		(unsigned*)&dwThreadID[1]
	);

	if (hThread[0] == 0 || hThread[1] == 0)
	{
		_fputts(_T("Thread creation error \n"), stdout);
		return -1;
	}

	_fputts(_T("Insert string : "), stdout);
	_fgetts(string, 30, stdin);

	SetEvent(hEvent); // event�� state�� signaled ���·� ����

	WaitForMultipleObjects(
		2, //�迭�� ����
		hThread, // �ڵ��� �迭
		TRUE, // ��� �ڵ��� ��ȣ���� ���·� �� �� ����
		INFINITE // ���Ѵ��
	);

	CloseHandle(hEvent); // event ������Ʈ �Ҹ�
	CloseHandle(hThread[0]);
	CloseHandle(hThread[1]);

	return 0;
}

unsigned int WINAPI OutputThreadFunction(LPVOID lpParam)
{
	WaitForSingleObject(hEvent, INFINITE);
	_fputts(_T("output string : "), stdout);
	_fputts(string, stdout);
	return 0;
}

unsigned int WINAPI CountThreadFunction(LPVOID lpParam)
{
	WaitForSingleObject(hEvent, INFINITE);
	_tprintf(_T("output stirng length : %d \n"), _tcslen(string) - 1);
	return 0;
}