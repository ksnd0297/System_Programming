




#include <stdio.h>
#include <tchar.h>
#include <Windows.h>

#define DIR_LEN MAX_PATH+1

int _tmain(int argc, TCHAR* argv[])
{
	STARTUPINFO si = { 0, };
	PROCESS_INFORMATION pi;

	si.cb = sizeof(si); // ����ü ������ ũ��
	si.dwFlags = STARTF_USEPOSITION | STARTF_USESIZE; // dwX�� dwY�� ���� ���(STARTF_USEPOSITION) dwXSize �� dwYSize�� ���� ���(STARTF_USESIZE)
	si.dwX = 100;
	si.dwY = 200;
	si.dwXSize = 300;
	si.dwYSize = 200;
	//si.lpTitle = _T("I am a boy!"); // �ܼ� �������� Ÿ��Ʋ �� ����

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

	state = CreateProcess( // ���μ��� ����
		name,				// ���������� �̸�
		command,			// main �Լ��� ���޵� ���ڿ�
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