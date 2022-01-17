





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
	
	hEvent = CreateEvent( // event object 생성
		NULL, // 상속 불가
		TRUE, // manual-reset mode로 생성
		FALSE, // non-signaled 상태로 생성
		NULL // 이름없는 event
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

	SetEvent(hEvent); // event의 state를 signaled 상태로 변경

	WaitForSingleObject(hThread, INFINITE);
	CloseHandle(hEvent); // evnet 오브젝트 소멸
	CloseHandle(hThread);

	return 0;
}

unsigned int WINAPI OutputThreadFunction(LPVOID lpParam)
{
	// evnet가 signaled 상태가 되기를 기다린다.
	WaitForSingleObject(hEvent, INFINITE);

	_fputts(_T("Output string : "), stdout);
	_fputts(string, stdout);

	return 0;
}