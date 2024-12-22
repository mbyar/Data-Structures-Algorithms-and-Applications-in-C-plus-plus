#include<iostream>
using namespace std;
enum signType { plus, minus };
class currency
{
public:
	currency(signType theSign = signType::plus,
		unsigned long theDollars = 0,
		unsigned int theCents = 0);
	~currency(){}
	void setValue(signType, unsigned long, unsigned int);
	void setValue(double);
	signType getsign() const { return sign; }
	unsigned long getDollars() const { return dollars; }
	unsigned int getCents() const { return cents; }
	currency add(const currency&)const;
	currency& increment(const currency&);
	void output()const;
	currency& input();
	currency& subtract(const currency&)const;
	currency percent(double x)const;
	currency multiply(double x)const;
	currency divide(double x)const;
private:
	signType sign;
	unsigned long dollars;
	unsigned int cents;
};
currency::currency(signType theSign, unsigned long theDollars, unsigned int theCents)
{
	setValue(theSign, theDollars, theCents);
}
void currency::setValue(signType theSign, unsigned long theDollars, unsigned int theCents)
{
	if (theCents > 99)
		throw "Cents should be < 100";
	sign = theSign;
	dollars = theDollars;
	cents = theCents;
}
void currency::setValue(double theAmount)
{
	if (theAmount < 0) { sign = signType::minus; theAmount = -theAmount; }
	else sign = signType::plus;;
	dollars = (unsigned long)theAmount;
	cents = (unsigned int)((theAmount + 0.001 - dollars) * 100);
}
currency currency::add(const currency& x)const
{
	long a1, a2, a3;
	currency result;
	a1 = dollars * 100 + cents;
	if (sign == signType::minus) a1 = -a1;
	a2 = x.dollars * 100 + x.cents;
	if (x.sign == signType::minus) a2 = -a2;
	a3 = a1 + a2;
	if (a3 < 0) { result.sign = signType::minus; a3 = -a3; }
	else result.sign = signType::plus;
	result.dollars = a3 / 100;
	result.cents = a3 - result.dollars * 100;
	return result;
}
currency& currency::increment(const currency& x)
{
	*this = add(x);
	return *this;
}
void currency::output() const
{
	if (sign == signType::minus)cout << '-';
	cout << '$' << dollars << '.';
	if (cents < 10) cout << '0';
	cout << cents;
}
currency& currency::input()
{
	double a;
	cin >> a;
	this->setValue(a);
	return *this;
}
currency& currency::subtract(const currency& x)const
{
	long a1, a2, a3;
	currency result;
	a1 = dollars * 100 + cents;
	if (sign == signType::minus) a1 = -a1;
	a2 = x.dollars * 100 + x.cents;
	if (x.sign == signType::minus) a2 = -a2;
	a3 = a1 - a2;
	if (a3 < 0) { result.sign = signType::minus; a3 = -a3; }
	else result.sign = signType::plus;
	result.dollars = a3 / 100;
	result.cents = a3 - result.dollars * 100;
	return result;
}
currency currency::percent(double x)const
{
	double result = (double)(dollars * 100 + cents) * x / 10000.0;
	currency c;
	c.setValue(result);
	return c;
}
currency currency::multiply(double x)const
{
	double result = (double)(dollars * 100 + cents) / 100.0 * x;
	currency c;
	c.setValue(result);
	return c;
}
currency currency::divide(double x)const
{
	double result = (double)(dollars * 100 + cents) / 100.0 / x;
	currency c;
	c.setValue(result);
	return c;
}
int main()
{
	currency c(signType::plus, 10, 20);
	currency a(signType::plus, 20, 10);
	c.percent(20.0).output();
	return 0;
}