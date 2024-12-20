#include<iostream>
using namespace std;
int abc(int a, int b, int c)
{
	if (a < 0 && b < 0 && c < 0)
		throw 1;
	if (a == 0 && b == 0 && c == 0)
		throw 2;
	return a + b * c;
}
template<typename T>
int count(T& a, int size)
{
	if (size / sizeof(a[0]) < 1)
		throw"Too Small";
}
void test01()
{
	try { abc(0, 0, 0); }
	catch (int e)
	{
		cout << e << endl;
	}
}
void test02()
{
	int a[5];
	try { count(a, 0); }
	catch (const char* e)
	{
		cout << e << endl;
	}
}
int main()
{
	test02();
	return 0;
}
