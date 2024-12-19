#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;
//传值参数
//int abc(int a, int b, int c)
//{
//	return a + b * c;
//}
//float abc(float a, float b, float c)
//{
//	return a + b * c;
//}
// 模板函数
//template<class T>
//T abc(T a, T b, T c)
//{
//	return a + b * c;
//}
//引用参数
//template<class T>
//T abc(T& a, T& b, T& c)
//{
//	return a + b * c;
//}
//常量引用参数
//template<class T>
//T abc(const T& a, const T& b, const T& c)
//{
//	return a + b * c;
//}
//通用版本
template<class Ta,class Tb,class Tc>
Ta abc(const Ta& a, const Tb& b, const Tc& c)
{
	return a + b * c;
}
int main()
{
	cout << abc(1, 1.2, 3) << endl;
	return 0;
}