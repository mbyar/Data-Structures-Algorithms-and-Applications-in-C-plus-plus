#include<iostream>
using namespace std;
template<typename T>
void make2dArray(T**& a, int row, int rowsize[])
{
	a = new T*[row];
	for (int i = 0; i < row; i++)
	{
		a[i] = new T[rowsize[i]];
		a[i] = 0;
	}
}
template<typename T>
void changeLength1D(T*& a, int oldLength, int newLength)
{
	T* p = new T[newLength];
	int min = oldLength;
	if (newLength < min)
		min = newLength;
	for (int i = 0; i < min; i++)
	{
		p[i] = a[i];
	}
	delete[] a;
	a = p;
}
template<typename T>
void changeLength2D(T**&a, int oldrow, int newrow, int oldclum, int newclum)
{
	T** p = new T*[newrow];
	for (int i = 0; i < newrow; i++)
		p[i] = new T[newclum];
	int min = oldrow;
	if (newrow < min)
		min = newrow;
	int min2 = oldclum;
	if (newclum < min2)
		min2 = newclum;
	for (int i = 0; i < min; i++)
	{
		for (int j = 0; j < min2; j++)
			p[i][j] = a[i][j];
	}
	for (int i = 0; i < oldrow; i++)
		delete[] a[i];
	delete[] a;
	a = p;
}
void test01()
{
	int** x;
	int a[3] = { 1,2,3 };
	make2dArray(x, 3, a);
	//调试的时候看一下吧
}
void test02()
{
	int* a = new int[3];
	a[0] = 0;
	a[1] = 1;
	a[2] = 2;
	changeLength1D(a, 3, 2);
	cout << a[0] << endl;
	cout << a[1] << endl;
	cout << a[2] << endl;
}
void test03()
{
	int** a = new int* [2];
	for (int i = 0; i < 2; i++)
		a[i] = new int[2];
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			a[i][j] = i + j;
	changeLength2D(a, 2, 3, 2, 3);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cout << a[i][j] << endl;
}
int main()
{
	//test01();
	//test02();
	test03();
	return 0;
}
