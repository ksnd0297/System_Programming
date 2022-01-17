#include <iostream>

using namespace std;

int FuncTwo(int& a)
{
	a++;
	return a;
}

int main(void)
{
	int num1 = 10;
	int num2 = FuncTwo(num1);
	cout << num2;
	return 0;
}