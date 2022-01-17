




#include <stdio.h>
#include <tchar.h>
#include <Windows.h>


int _tmain(int argc, TCHAR* argv[])
{
	STARTUPINFO si = { 0, };
	PROCESS_INFORMATION pi;
	DWORD state;








	TCHAR command[] = _T("OperationStateChild.exe");

	CreateProcess(NULL, command,
		NULL, NULL, TRUE,
		CREATE_NEW_CONSOLE,
		NULL, NULL,
		&si, &pi
	); // CreateProcess

	//for (DWORD i = 0; i < 10000; i++)
	//	for (DWORD i = 0; i < 10000; i++);

	// 자식 프로세스가 종료될 때까지 기다리는 기능의 함수
	WaitForSingleObject(pi.hProcess, INFINITE);

	// 핸들이 가리키는 프로세스가 반환하는 종료코드를 얻기 위해 사용되는 함수
	GetExitCodeProcess(pi.hProcess, &state);
	if (state == STILL_ACTIVE)
		_tprintf(_T("STILL_ACTIVE \n\n"));
	else
		_tprintf(_T("state : %d \n\n"), state);
	// CloseHandle(pi.hProcess);
	

	return 0;
}