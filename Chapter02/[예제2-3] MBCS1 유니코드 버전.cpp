#include <stdio.h>
#include <string.h>

int main(void)
{
	wchar_t str[] = L"ABC";
	int size = sizeof(str);
	int len = strlen(str);

	printf("�迭�� ũ�� : %d \n", size);
	printf("���ڿ� ���� : %d \n", len);

	return 0;
}