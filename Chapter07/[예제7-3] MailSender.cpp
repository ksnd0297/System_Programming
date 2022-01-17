




#include <stdio.h>
#include <tchar.h>
#include <Windows.h>
// 메일슬롯의 주소(이름)
#define SLOT_NAME _T("\\\\.\\mailslot\\mailbox")

int _tmain(int argc, TCHAR* argv[])
{
	HANDLE hMailSlot;
	TCHAR message[50];
	DWORD bytesWritten;

	hMailSlot = CreateFile(
		SLOT_NAME,
		GENERIC_WRITE,
		FILE_SHARE_READ,
		NULL,
		OPEN_EXISTING, // 이미 만들어 놓은 메일슬롯에 접근하는 것이 목적
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);
	if (hMailSlot == INVALID_HANDLE_VALUE)
	{
		_fputts(_T("Unable to create mailslot!\n"), stdout);
		return 1;
	}

	while (1)
	{
		_fputts(_T("MY CMD>"), stdout);
		_fgetts(message, sizeof(message) / sizeof(TCHAR), stdin);

		if (!WriteFile(hMailSlot, message, _tcslen(message) * sizeof(TCHAR), &bytesWritten, NULL))
		{
			_fputts(_T("Unable to write!"), stdout);
			CloseHandle(hMailSlot);
			return 1;
		}

		if (!_tcscmp(message, _T("exit")))
		{
			_fputts(_T("Good Bye!"), stdout);
			getchar();
			break;
		}
	}
	CloseHandle(hMailSlot);
	return 0;
}