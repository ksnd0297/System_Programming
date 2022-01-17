#include <stdio.h>
#include <tchar.h>
#include <Windows.h>

int _tmain(int argc, TCHAR* argv[])
{
	DWORD val1, val2;
	val1 = _ttoi(argv[1]);
	val2 = _ttoi(argv[2]);
	// _ttoi 함수는 atoi 함수와 유니코드 기반의 _wtoi를 동시 지원하기 위한 매크로 함수
	// atoi (ASCII to Int) 문자열을 정수형태로 변환

	_tprintf(_T("%d + %d = %d \n"), val1, val2, val1 + val2);

	_gettchar();
	//_gettchar 함수는 getchar 함수와 유니코드 기반의 getwchar 함수를 동시 지원하기 위한 매크로 함수
	return 0;
}