#include<iostream>

using namespace std;
//8		7+6*x+5*x*x+4*x*x*x+3*x*x*x*x
//		(((3*x+4)*x+5)*x+6)*x+7
template<typename T>
void my_rank(T a[], int n, int r[])
{
	for (int i = 0; i < n; i++)
		r[i] = 0;
	for (int i = 1; i < n; i++)
		for (int j = 0; j < i; j++)
			if (a[i] < a[j])
				r[j]++;
			else
				r[i]++;
}

int main()
{
	int a[9] = { 3,2,6,5,9,4,7,1,8 };
	int r[9];
	my_rank(a, 9, r);
	for (int i = 0; i < 9; i++)
	{
		cout << r[i] << " ";
	}
	cout << endl;
	return 0;
}