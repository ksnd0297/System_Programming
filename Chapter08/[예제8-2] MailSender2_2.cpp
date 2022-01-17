




#include <stdio.h> 
#include <tchar.h>
#include <windows.h>

int _tmain(int argc, TCHAR* argv[])
{
	HANDLE hMailSlot;
	TCHAR message[50];
	DWORD bytesWritten;

	
	FILE* file = _tfopen(_T("InheritableHandle.txt"), _T("rt"));
	_ftscanf(file, _T("%d"), &hMailSlot);
	fclose(file);
	_tprintf(_T("Inheritable Handle : %d \n"), hMailSlot);

	_tprintf(_T("error code : %d"), GetLastError());
	getchar();

	while (1)
	{
		_fputts(_T("MY CMD>"), stdout);
		_fgetts(message, sizeof(message) / sizeof(TCHAR), stdin);

		if (!WriteFile(
			hMailSlot, message,
			_tcslen(message) * sizeof(TCHAR),
			&bytesWritten, NULL) )
		{
			_fputts(_T("Unable to write!"), stdout);
			_gettchar();
			CloseHandle(hMailSlot);
			return 1;
		}

		if (!_tcscmp(message, _T("exit")))
		{
			_fputts(_T("Good bye!"), stdout);
			break;
		}
	}

	CloseHandle(hMailSlot);
	return 0;
}