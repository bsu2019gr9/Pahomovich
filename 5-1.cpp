#include <iostream>
#include <cmath>
#include "ArraysPahomovich.h"

using namespace std;

//Класс арифметическая дробь.

struct Fraction //хранится как "numerator/denominator"
{
private:
	int numerator; //числитель дроби
	int denominator; //знаменатель дроби
public:
	Fraction(); // конструктор без параметров
	Fraction(int, int = 1); // конструктор с параметрами 
	Fraction(const Fraction& ); // конструктор копирования
	~Fraction(); // деструктор

	Fraction operator=(const Fraction& ) ; //оператор присваивания
	Fraction operator+(const Fraction& ) const; //сложение двух дробей
	Fraction operator-(const Fraction& ) const; //вычитание двух дробей
	Fraction operator*(const Fraction& ) const; //умножение двух дробей
	Fraction operator/(const Fraction& ) const; // деление двух дробей
	Fraction operator+(const int ) const; //прибавление числа к дроби
	Fraction operator-(const int ) const; //отнимание числа от дроби
	Fraction operator*(const int ) const; //умножение дроби на число
	Fraction operator/(const int ) const; //деление дроби на число

	Fraction operator+=(const Fraction& ); //прибавление дроби с присваиванием
	Fraction operator-=(const Fraction& ); //вычитание дроби с присваиванием
	Fraction operator*=(const Fraction& ); //умножение на дробь с присваиванием
	Fraction operator+=(const int); //прибавление целого числа с присваиванием
	Fraction operator-=(const int); //вычитание целого числа из дроби с присваиванием
	Fraction operator*=(const int); //умножение на целое число с присваиванием
	Fraction operator/=(const int); //деление на целое число с присваиванием

	bool operator==(Fraction& ) const; //операция равенства
	bool operator!=(Fraction& ) const; //операция неравенства

	friend void operator<<(ostream& , const Fraction& ); //вывод
	friend void operator>>(istream& , Fraction& ); //ввод

	bool isProperFraction( ); //возвращает true, если дробь правильная и false, если неправильная

private:
	void reduceFr( ); //сокращение дроби
	void findSign( ); //определение знака в дроби
	int founding_GCD(int tmp_a, int tmp_b)
	{
		if (tmp_a % tmp_b == 0) return tmp_b;
		else return tmp_a % tmp_b;
	}
};

Fraction Value(Fraction fr) { 	return fr;   }
Fraction* fff(Fraction* fr) {	return fr;   }
Fraction Link(Fraction& fr) {	return fr;   }
Fraction sumOfElements(Fraction** Fr, int N); //находит сумму элементов в массиве из дробей

int main() {
	int i(11), N(3);
	Fraction fr1 = { 2 , 3 };
	Fraction fr2 = { 4 , -8 };
	Fraction fr3 = fr2;
	Fraction* Fr2 = new Fraction(5, 6);
	Fraction* Fr3 = &fr3;
	Fraction** Fr = nullptr;
	Fr = new (nothrow) Fraction * [N];
	Fr[0] = &fr1; Fr[1] = &fr2; Fr[2] = &fr3;
	Fraction fr4;
	fr4 = fr1 + fr2; cout << fr4; cout << '\n';
	fr4 = *Fr2 - fr2; cout << fr4; cout << '\n';
	fr4 = fr1*6; cout << fr4; cout << '\n';
	fr4 -= {1, 1}; cout << fr4; cout << '\n';
	cin >> fr4; 
	cout << fr4; cout << '\n';
	cout << Value(fr1);
	cout << Link(fr2);
	cout << fff(Fr2);
	Fraction sum = { 0,1 };
	sum = sumOfElements(Fr, 3);
	cout << "--------------------------------------------------------------------\n";
	cout << sum; cout << "\n";
	if (fr2.isProperFraction()) cout << "is proper fraction\n";
	else cout << "is unproper fraction\n";
	delete Fr2; Fr2 = nullptr;
	delete[] Fr; Fr = nullptr;
	return 0;
}

Fraction::Fraction() :
	numerator(0),
	denominator(1)
{
	cout << "no params constructor working \n";
};
Fraction::Fraction(int num, int denom) : 
	numerator(num),
	denominator(denom)
{
	if (!denominator) throw "Bad arg";
	else
	{
		reduceFr();
		findSign();
	}
	cout << "constructor working for " << this->numerator << '/' << this->denominator << "\n";
};
Fraction::Fraction(const Fraction& other) :
	numerator(other.numerator),
	denominator(other.denominator)
{
	cout << "copy constructor working for " << this->numerator << '/' << this->denominator << "\n";
};
Fraction::~Fraction() { cout << "destructor working for..." << this->numerator << '/' << this->denominator << "\n";; };
Fraction Fraction::operator=(const Fraction& rhs)
{
	cout << "= working for " << rhs.numerator << '/' << rhs.denominator << "\n";
	numerator = rhs.numerator;
	denominator = rhs.denominator;
	return Fraction(numerator,denominator);
}

Fraction Fraction::operator+(const Fraction& rhs) const  
{
	return Fraction(numerator*rhs.denominator + denominator*rhs.numerator, denominator*rhs.denominator);
}
Fraction Fraction::operator-(const Fraction& rhs) const 
{
	return Fraction(numerator * rhs.denominator - denominator * rhs.numerator, denominator * denominator);
}
Fraction Fraction::operator*(const Fraction& rhs) const
{
	return Fraction(numerator * rhs.numerator, denominator * rhs.denominator);
}
Fraction Fraction::operator/(const Fraction& rhs) const
{
	return Fraction(numerator * rhs.denominator, denominator * rhs.numerator);
}

Fraction Fraction::operator+(const int rhs) const
{
	return Fraction(numerator + denominator * rhs, denominator * denominator);
}
Fraction Fraction::operator-(const int rhs) const
{
	return Fraction(numerator - denominator * rhs, denominator * denominator);
}
Fraction Fraction::operator*(const int rhs) const
{
	return Fraction(numerator * rhs, denominator);
}
Fraction Fraction::operator/(const int rhs) const
{
	return Fraction(numerator, denominator * rhs);
}

//---------?????????????????????????????????????????????????????????????????????????????
Fraction Fraction::operator+=(const Fraction& rhs)
{
	return Fraction(numerator = numerator * rhs.denominator + denominator * rhs.numerator, denominator = denominator * rhs.denominator);
}
Fraction Fraction::operator-=(const Fraction& rhs)
{
	return Fraction(numerator = numerator * rhs.denominator + denominator * rhs.numerator, denominator = denominator * rhs.denominator);
}
Fraction Fraction::operator*=(const Fraction& rhs)
{
	return Fraction(numerator *= rhs.numerator, denominator *= rhs.denominator);
}
Fraction Fraction::operator+=(const int rhs)
{
	return Fraction(numerator += denominator * rhs, denominator += 0);
}
Fraction Fraction::operator-=(const int rhs)
{
	return Fraction(numerator -= denominator * rhs, denominator += 0);
}
Fraction Fraction::operator*=(const int rhs)
{
	return Fraction(numerator *= rhs, denominator += 0);
}
Fraction Fraction::operator/=(const int rhs)
{
	return Fraction(numerator += 0, denominator *= rhs);
}
//---------?????????????????????????????????????????????????????????????????????????????

bool Fraction::operator==(Fraction& fr) const   
{
	return numerator == fr.numerator && denominator == fr.denominator;
}
bool Fraction::operator!=(Fraction& fr) const
{
	return numerator != fr.numerator || denominator != fr.denominator;
}

void operator>>(istream& in, Fraction& f)
{
	in >> f.numerator;
	in >> f.denominator;
}
void operator<<(ostream& out, const Fraction& v)
{
	out << " " << v.numerator << '/' << v.denominator << " ";
}
void Fraction::reduceFr()
{
	int a = numerator;
	int b = denominator;
	while (1)
	{
		a = founding_GCD(a, b);
		if (a % b == 0) {   break;   }
		else swap(a, b);
	}
	numerator /= b;
	denominator /= b;
}
void Fraction::findSign()
{
	if (denominator < 0)
	{
		denominator *= (-1);
		numerator *= (-1);
	}
}
bool Fraction::isProperFraction()
{
	if (abs(numerator) < abs(denominator)) return true;
	else return false;
};

Fraction sumOfElements(Fraction** Fr, int N)
{
	Fraction sum = { 0,1 };
	for (Fraction** p = Fr; p < Fr + N; ++p)
	{
		sum += **p;
	}
	return sum;
}