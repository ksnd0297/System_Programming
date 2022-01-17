





#include <stdio.h>
#include <tchar.h>
#include <windows.h>
#include <process.h>

unsigned int WINAPI OutputThreadFunction(LPVOID lpParam);

TCHAR string[100];
HANDLE hEvent;

int _tmain(int argc, TCHAR* argv[])
{
	HANDLE hThread;
	DWORD dwThreadID;
	
	hEvent = CreateEvent( // event object ����
		NULL, // ��� �Ұ�
		TRUE, // manual-reset mode�� ����
		FALSE, // non-signaled ���·� ����
		NULL // �̸����� event
	);
	if (hEvent == NULL) {
		_fputts(_T("Event object creation error \n"), stdout);
		return -1;
	}

	hThread = (HANDLE)_beginthreadex(
		NULL, 0,
		OutputThreadFunction,
		NULL, 0,
		(unsigned*)&dwThreadID
	);

	if (hThread == 0) {
		_fputts(_T("Thread creation erorr \n"), stdout);
		return -1;
	}

	_fputts(_T("Insert string : "), stdout);
	_fgetts(string, 30, stdin);

	SetEvent(hEvent); // event�� state�� signaled ���·� ����

	WaitForSingleObject(hThread, INFINITE);
	CloseHandle(hEvent); // evnet ������Ʈ �Ҹ�
	CloseHandle(hThread);

	return 0;
}

unsigned int WINAPI OutputThreadFunction(LPVOID lpParam)
{
	// evnet�� signaled ���°� �Ǳ⸦ ��ٸ���.
	WaitForSingleObject(hEvent, INFINITE);

	_fputts(_T("Output string : "), stdout);
	_fputts(string, stdout);

	return 0;
}