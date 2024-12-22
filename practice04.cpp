#include<iostream>
using namespace std;
enum signType { plus, minus };
class currency
{
	friend ostream& operator<<(ostream&, const currency&);
	friend istream& operator>>(istream&, currency&);
public:
	currency(signType theSign = signType::plus, unsigned long theDollars = 0, unsigned int theCents = 0);
	~currency() {}
	void setValue(signType, unsigned long, unsigned int);
	void setValue(double);
	signType getSign()const
	{
		if (amount < 0)return signType::minus;
		else return signType::plus;
	}
	unsigned long getDollars()const
	{
		if (amount < 0)return (-amount) / 100;
		else return amount / 100;
	}
	unsigned int getCents()const
	{
		if (amount < 0)return -amount - getDollars() * 100;
		else return amount - getDollars() * 100;
	}
	currency operator+(const currency&)const;
	currency& operator+=(const currency& x)
	{
		amount += x.amount; return *this;
	}
	void output(ostream&)const;
	currency operator-(const currency&)const;
	currency operator%(const currency&)const;
	currency operator*(const currency&)const;
	currency operator/(const currency&)const;
	currency& operator=(int x);
	currency& operator=(double x);
private:
	long amount;
};
currency::currency(signType theSign, unsigned long theDollars, unsigned int theCents)
{
	setValue(theSign, theDollars, theCents);
}
void currency::setValue(signType theSign, unsigned long theDollars, unsigned int theCents)
{
	if (theCents > 99)
		throw "Cents should be < 100";
	amount = theDollars * 100 + theCents;
	if (theSign == signType::minus)amount = -amount;
}
void currency::setValue(double theAmount)
{
	if (theAmount < 0)
		amount = (long)((theAmount - 0.001) * 100);
	else
		amount = (long)((theAmount + 0.001) * 100);
}
currency currency::operator+(const currency& x)const
{
	currency result;
	result.amount = amount + x.amount;
	return result;
}
currency currency::operator-(const currency& x)const
{
	currency result;
	result.amount = amount - x.amount;
	return result;
}
currency currency::operator%(const currency& x)const
{
	currency result;
	result.amount = amount % x.amount;
	return result;
}
currency currency::operator*(const currency& x)const
{
	currency result;
	result.amount = amount * x.amount;
	return result;
}
currency currency::operator/(const currency& x)const
{
	currency result;
	result.amount = amount / x.amount;
	return result;
}
void currency::output(ostream& out)const
{
	long theAmount = amount;
	if (theAmount < 0) {
		out << '-'; theAmount = -theAmount;
	}
	long dollars = theAmount / 100;
	out << '$' << dollars << '.';
	int cents = theAmount - dollars * 100;
	if (cents < 10)out << '0';
	out << cents;
}
ostream& operator<<(ostream& out, const currency& x)
{
	long theAmount = x.amount;
	if (theAmount < 0) {
		out << "-";
		theAmount = -theAmount;
	}
	long dollars = theAmount / 100;
	out << '$' << dollars << '.';
	int cents = theAmount - dollars * 100;
	if (cents < 10)out << '0';
	out << cents;
	return out;
}
istream& operator>>(istream& in, currency& x)
{
	double d;
	in >> d;
	x.amount = d * 100;
	return in;
}
currency&currency:: operator=(int x)
{
	amount = x;
	return *this;
}
currency& currency::operator=(double x)
{
	amount = x * 100;
	return *this;
}
int main()
{
	currency c;
	cin >> c;
	cout << c << endl;
	return 0;
}