#include <stdio.h>
#include <tchar.h>
#include <Windows.h>

int _tmain(int argc, TCHAR* argv[])
{
	DWORD val1, val2;
	val1 = _ttoi(argv[1]);
	val2 = _ttoi(argv[2]);
	// _ttoi �Լ��� atoi �Լ��� �����ڵ� ����� _wtoi�� ���� �����ϱ� ���� ��ũ�� �Լ�
	// atoi (ASCII to Int) ���ڿ��� �������·� ��ȯ

	_tprintf(_T("%d + %d = %d \n"), val1, val2, val1 + val2);

	_gettchar();
	//_gettchar �Լ��� getchar �Լ��� �����ڵ� ����� getwchar �Լ��� ���� �����ϱ� ���� ��ũ�� �Լ�
	return 0;
}