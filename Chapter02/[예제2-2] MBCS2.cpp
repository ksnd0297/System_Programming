#include <stdio.h>

int main(void)
{
	char str[] = "한글입니다";
	int i;

	for (i = 0; i < 5; i++)
		fputc(str[i], stdout);

	fputs("\n", stdout);

	for (i = 0; i < 10; i++)
		fputc(str[i], stdout);
	// 1바이트 데이터를 출력하는 fputc 함수를 10번 호출해야 함
	fputs("\n", stdout);
	return 0;
}