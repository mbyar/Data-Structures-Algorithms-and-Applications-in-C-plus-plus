#include<iostream>
using namespace std;
//template<class T>
//bool make2dArray(T**& x, int numberOfRows, int numberOfColumns)
//{
//	try {
//		x = new T * [numberOfRows];
//		for (int i = 0; i < numberOfRows; i++)
//			x[i] = new int[numberOfColumns];
//		return true;
//	}
//	catch (bad_alloc) { return false; }
//}
template<typename T>
void make2dArray(T**& x, int numberOfRows, int numberOfColumns)
{
	x = new T * [numberOfRows];
	for (int i = 0; i < numberOfRows; i++)
		x[i] = new T[numberOfColumns];
}
template<typename T>
void delete2dArray(T**& x, int numberOfRows)
{
	for (int i = 0; i < numberOfRows; i++)
		delete[] x[i];
	delete[] x;
	x = NULL;
}
void test01()
{
	int** x;
	try { make2dArray(x, 1, 2); }
	catch (bad_alloc)
	{
		cerr << "Could not create x" << endl;
		exit(1);
	}
}
int main()
{
	test01();
	return 0;
}