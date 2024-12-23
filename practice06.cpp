#include<iostream>
#include<numeric>
#include<functional>
#include<iterator>
#include<algorithm>
using namespace std;
template<class T>
T my_accumulate(T* start, T* end, T initialValue)
{
	T count = initialValue;
	T* p = start;
	while (p != end)
	{
		count += *p;
		p++;
	}
	return count;
}
template<class T, class F>
T my_accumulate_plus(T* start, T* end, T initalValue, F fun)
{
	T count = initalValue;
	T* p = start;
	while (p != end)
	{
		count = fun(count, *p);
		p++;
	}
	return count;
}
template<class T>
void my_copy(T* start, T* end, T* to)
{
	T* p = start;
	while (p != end)
	{
		*to = *p;
		to++;
		p++;
	}
}
template<class T>
void permutations(T list[], int k, int m)
{
	sort(list, list + m);
	do {
		copy(list, list + m, ostream_iterator<T>(cout, ""));
		cout << endl;
	} while (next_permutation(list, list + m ));
}
template<typename T>
void permutations1(T list[], int k, const int m)
{
	T s [100];
	my_copy(list, list + m, s);
	do {
		copy(list, list + m, ostream_iterator<T>(cout, ""));
		cout << endl;
	} while (next_permutation(list, list + m));
	while (prev_permutation(s, s + m))
	{
		copy(s, s + m, ostream_iterator<T>(cout, ""));
		cout << endl;
	}
}
template<class T>
void permutations2(T list[], int k, int m)
{
	do {
	} while (next_permutation(list, list + m));
	do {
		copy(list, list + m, ostream_iterator<T>(cout, ""));
		cout << endl;
	} while (next_permutation(list, list + m));
}
template<typename T>
int my_count(T a[], int n, T value)
{
	return count(a, a + n, value);
}
template<typename T>
void my_fill(T a[], int start, int end, T value)
{
	fill(a+start - 1, a+end, value);
}
template<typename T>
T my_inner_product(T a[], T b[], int n, int inival)
{
	return inner_product(a, a + n, b, inival);
}
template<typename T>
void my_iota(T a[], int n, T value)
{
	iota(a, a + n, value);
}
template<typename T>
bool my_is_sorted(T a[], int n)
{
	return is_sorted(a, a + n);
}
template<typename T>
auto my_mismatch(T a[], T b[], int n)
{
	return mismatch(a, a + n, b);
}
void test01()
{
	int a[4] = { 1,2,3,4 };
	char s[3] = { 'h','e','l' };
	float f[3] = {};
	cout << my_accumulate_plus(a, a + 4, 3, multiplies<int>()) << " " << accumulate(a, a + 4, 3, multiplies<int>()) << endl;
	cout << my_accumulate_plus(s, s + 3, '8',multiplies<char>()) << " " << accumulate(s, s + 3, '8', multiplies<char>()) << endl;
	cout << my_accumulate_plus(f, f, 1.3f, multiplies<float>()) << " " << accumulate(f, f, 1.3f, multiplies<char>()) << endl;
}
void test02(void)
{
	int a[4] = { 1,2,3,4 };
	int b[4] = { 2,1,3,4 };
	my_mismatch(a,b,4);
}
int main()
{
	//test01();
	test02();
	return 0;
}