




#include <stdio.h>
#include <tchar.h>
#include <windows.h>

int _tmain(int argc, TCHAR* argv[])
{
	SetEnvironmentVariable(_T("Good"), _T("morning"));
	SetEnvironmentVariable(_T("Hey"), _T("Ho!"));
	SetEnvironmentVariable(_T("Big"), _T("Boy"));

	STARTUPINFO si = { 0, };
	PROCESS_INFORMATION pi = { 0, };
	si.cb = sizeof(si);

	int num = CreateProcess(
		NULL, _T("EnvChild"), NULL, NULL, FALSE,
		CREATE_NEW_CONSOLE | CREATE_UNICODE_ENVIRONMENT,
		NULL, //  부모 프로세스의 환경변수 등록
		NULL, &si, &pi
	);
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
	getchar();
	return 0;
}