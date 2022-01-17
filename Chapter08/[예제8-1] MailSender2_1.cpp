




#include <stdio.h>
#include <tchar.h>
#include <Windows.h>

#define SLOT_NAME _T("\\\\.\\mailslot\\mailbox")

int _tmain(int argc, TCHAR* argv[])
{
	HANDLE hMailSlot;
	TCHAR message[50];
	DWORD bytesWritten; // number of bytes write

	SECURITY_ATTRIBUTES sa; // 핸들의 상속 여부를 Y로 두기 위한 코드가 존재
	sa.nLength = sizeof(sa);
	sa.lpSecurityDescriptor = NULL;
	sa.bInheritHandle = TRUE;

	hMailSlot = CreateFile( // 생성하는 리소스의 핸들은 상속 가능 여부가 Y로 핸들 테이블에 등록
		SLOT_NAME,
		GENERIC_WRITE, FILE_SHARE_READ,
		&sa, OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);
	if (hMailSlot == INVALID_HANDLE_VALUE)
	{
		_fputts(_T("Unable to create mailslot!\n"), stdout);
		_gettchar();
		return 1;
	}

	_tprintf(_T("Inheritable Handle : %d \n"), hMailSlot);
	FILE* file = _tfopen(_T("InheritableHendle.txt"), _T("wt"));
	_ftprintf(file, _T("%d"), hMailSlot);
	fclose(file);

	STARTUPINFO si = { 0, };
	PROCESS_INFORMATION pi;
	si.cb = sizeof(si);

	TCHAR command[] = _T("MailSender2_2.exe");

	CreateProcess(NULL, command,
		NULL, NULL,
		TRUE, // 핸들 테이블 상속 설정!
		CREATE_NEW_CONSOLE,
		NULL, NULL,
		&si, &pi
	); // CreateProcess

	while (1)
	{
		_fputts(_T("MY CMD>"), stdout);
		_fgetts(message, sizeof(message) / sizeof(TCHAR), stdin);
		if (!WriteFile(
			hMailSlot, message, _tcslen(message) * sizeof(TCHAR),
			&bytesWritten, NULL))
		{
			_fputts(_T("Unable to write!"), stdout);
			CloseHandle(hMailSlot);
			return 1;
		}
		if (!_tcscmp(message, _T("exit")))
		{
			_fputts(_T("Good Bye!"), stdout);
			break;
		}
	}
	CloseHandle(hMailSlot);
	return 0;
}