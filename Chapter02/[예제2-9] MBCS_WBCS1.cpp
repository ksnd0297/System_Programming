#define UNICODE
#define _UNICODE
// 매크로 UNICODE _UNICODE 정의

#include <stdio.h>
#include <tchar.h>
#include <Windows.h>

int wmain(void)
{
	TCHAR str[] = _T("1234567");
	//TCHAR -> "wchar_t" _T("1234567") -> L"1234567"로 인식
	int size = sizeof(str);
	printf("string length : %d \n", size);
	return 0;
}