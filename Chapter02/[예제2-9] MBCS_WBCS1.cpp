#define UNICODE
#define _UNICODE
// ��ũ�� UNICODE _UNICODE ����

#include <stdio.h>
#include <tchar.h>
#include <Windows.h>

int wmain(void)
{
	TCHAR str[] = _T("1234567");
	//TCHAR -> "wchar_t" _T("1234567") -> L"1234567"�� �ν�
	int size = sizeof(str);
	printf("string length : %d \n", size);
	return 0;
}