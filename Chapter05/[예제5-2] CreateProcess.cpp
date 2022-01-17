




#include <stdio.h>
#include <tchar.h>
#include <Windows.h>

#define DIR_LEN MAX_PATH+1

int _tmain(int argc, TCHAR* argv[])
{
	STARTUPINFO si = { 0, };
	PROCESS_INFORMATION pi;

	si.cb = sizeof(si); // 구조체 변수의 크기
	si.dwFlags = STARTF_USEPOSITION | STARTF_USESIZE; // dwX와 dwY의 값을 사용(STARTF_USEPOSITION) dwXSize 와 dwYSize의 값을 사용(STARTF_USESIZE)
	si.dwX = 100;
	si.dwY = 200;
	si.dwXSize = 300;
	si.dwYSize = 200;
	//si.lpTitle = _T("I am a boy!"); // 콘솔 윈도우의 타이틀 바 제목

	TCHAR command[] = _T("AdderProcess.exe 10 20");
	BOOL state;
	TCHAR name[] = _T("AdderProcess.exe");

	TCHAR cDir[DIR_LEN];
	GetCurrentDirectory(DIR_LEN, cDir);
	_fputts(cDir, stdout);
	_fputts(_T("\n"), stdout);

	SetCurrentDirectory(_T("C:\\WinSystem"));

	GetCurrentDirectory(DIR_LEN, cDir);
	_fputts(cDir, stdout);
	_fputts(_T("\n"), stdout);

	state = CreateProcess( // 프로세스 생성
		name,				// 실행파일의 이름
		command,			// main 함수에 전달될 문자열
		NULL, NULL, TRUE,
		CREATE_NEW_CONSOLE,
		NULL, NULL, &si, &pi
	); // CreateProcess

	if (state != 0)
		_fputts(_T("Creation OK! \n"), stdout);
	else {
		_fputts(_T("Creation Error! \n"), stdout);
		_tprintf(_T("error cod : %d \n"), GetLastError());
	}
		

	return 0;
}