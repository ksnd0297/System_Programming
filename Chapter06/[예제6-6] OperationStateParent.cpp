




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

	// �ڽ� ���μ����� ����� ������ ��ٸ��� ����� �Լ�
	WaitForSingleObject(pi.hProcess, INFINITE);

	// �ڵ��� ����Ű�� ���μ����� ��ȯ�ϴ� �����ڵ带 ��� ���� ���Ǵ� �Լ�
	GetExitCodeProcess(pi.hProcess, &state);
	if (state == STILL_ACTIVE)
		_tprintf(_T("STILL_ACTIVE \n\n"));
	else
		_tprintf(_T("state : %d \n\n"), state);
	// CloseHandle(pi.hProcess);
	

	return 0;
}