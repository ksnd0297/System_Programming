




#include <stdio.h>
#include <tchar.h>
#include <Windows.h>

int _tmain(int argc, TCHAR* argv[])
{
	SetPriorityClass(GetCurrentProcess(), NORMAL_PRIORITY_CLASS);

	while (1) {
		Sleep(10);

		_fputts(_T("NORMAL_PRIORITY_CLASS Process \n"), stdout);
	}
	return 0;
}