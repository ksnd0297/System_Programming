#include <stdio.h>

int main(void)
{
	char str[] = "�ѱ��Դϴ�";
	int i;

	for (i = 0; i < 5; i++)
		fputc(str[i], stdout);

	fputs("\n", stdout);

	for (i = 0; i < 10; i++)
		fputc(str[i], stdout);
	// 1����Ʈ �����͸� ����ϴ� fputc �Լ��� 10�� ȣ���ؾ� ��
	fputs("\n", stdout);
	return 0;
}