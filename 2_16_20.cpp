#include<iostream>
#include<algorithm>
using namespace std;
int stepCount = 0;
template<class T>
T sum(T a[], int n)
{
	T theSum = 0;
	stepCount++;
	for (int i = 0; i < n; i++)
	{
		stepCount++;
		theSum += a[i];
		stepCount++;
	}
	stepCount++;
	stepCount++;
	return theSum;
}
template<typename T>
T sum_s(T a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		stepCount += 2;
	}
	stepCount += 3;
	return 0;
}
template<class T>
T rSum(T a[], int n)
{
	if (n > 0)
	{
		stepCount += 2;
		return rSum(a, n - 1) + a[n - 1];
	}
	stepCount += 2;
	return 0;
}
template<typename T>
void transpose(T** a, int rows)
{
	for (int i = 0; i < rows; i++)
		for (int j = i + 1; j < rows; j++)
			swap(a[i][j], a[j][i]);
}
template<class T>
void inef(T a[], T b[], int n)
{
	for (int j = 0; j < n; j++)
		b[j] = sum(a, j + 1);
}

int main()
{
	int a[4] = { 1,2,3,4 };
	rSum(a, 4);
	cout << stepCount << endl;
	return 0;
}