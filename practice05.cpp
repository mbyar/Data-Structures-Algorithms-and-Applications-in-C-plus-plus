#include<iostream>
using namespace std;
int fun1(int n)
{
	int count = 1;
	for (int i = 1; i <= n; i++)
	{
		count *= i;
	}
	return count;
}
int Fibonacci(int n)
{
	if (n <= 2)
		return 1;
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}
int Fibonacci1(int n)
{
	if (n <= 2)
		return 1;
	int a = 1, b = 1;
	for (int i = 0; i < n - 2; i++)
	{
		a = a + b;
		b = a - b;
	}
	return a;
}
int fun2(int n)
{
	if (n % 2 == 0)
		return n / 2;
	else
		return fun2(3 * n + 1);
}
int fun21(int n)
{
	if (n % 2 == 0)
		return n / 2;
	else
		return (3 * n + 1) / 2;
}
int fun3(int a, int b)
{
	int c = 1;
	for (int i = 0; i < b; i++)
	{
		c *= a;
	}
	return c;
}
int A(int i, int j)
{
	if (i == 1 && j >= 1)
		return fun3(2, j);
	else if (i >= 2 && j == 1)
		return A(i - 1, 2);
	else if (i >= 2 && j >= 2)
		return A(i - 1, A(i, j - 1));
	else
		return 0;
}
int gcd(int x, int y)
{
	if (y == 0)
		return x;
	else if (y > 0)
		return gcd(y, x % y);
	else
		return 0;
}
template<typename T>
bool IsExist(T x[], T g, int n)
{
	if (n < 1)
		return false;
	if (x[n - 1] == g)
		return true;
	return IsExist(x, g, n - 1);
}
template <typename Ta>
void subset(Ta* A, int n, int i)
{
	if (i == n)
	{
		for (int j = 0; j < n; j++)
			cout << *(A + j);
		cout << endl;
	}
	else
	{
		A[i] = 0;
		subset(A, n, i + 1);
		A[i] = 1;
		subset(A, n, i + 1);
	}
}
void g(int n)
{
	if (n == 1)
		cout << 1 << ' ';
	else
	{
		g(n - 1);
		cout << n << ' ';
		g(n - 1);
	}
}
int main()
{
	g(9);
	return 0;
}