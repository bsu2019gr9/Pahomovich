#include <iostream>
#include <iomanip>
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
	bool operator>=(Fraction& ) const; //оператор  >=
	bool operator>(Fraction& ) const; //оператор  >
    bool operator<=(Fraction& ) const; //оператор  <=
	bool operator<(Fraction& ) const; //оператор  <
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


int main() {
	int i(11), N(5);
	Fraction fr1 = { 3 , 2 };
	Fraction fr2 = { 4 , -8 };
	Fraction* fr3 = new Fraction(5, 6);
	Fraction* fr4 = &fr2;
	Fraction* Fr = nullptr; 
	createArr(N,Fr);
	Fr[0] = fr1; Fr[1] = fr2; Fr[2] = *fr3; Fr[3] = { 5,3 }; Fr[4] = *fr4;
	cout << fr1 + fr2; cout << '\n';
	cout << *fr3 - fr2; cout << '\n';
	cout << fr1 * 6; cout << '\n';
    cout << (fr2 -= {1, 1}); cout << '\n';
	cout << (fr1 /= 2); cout << '\n';
	cout << (fr1 == fr2); cout << '\n';
	cout << (fr1 > *fr4); cout << "\n Enter your fraction";
	cin >> *fr4; 
	cout << *fr4; cout << '\n';
	cout << " Sorted array: \n";
	bubbleSort(Fr, N);
	printArray(Fr, Fr + N);
	cout << " Sum of array elements: \n";
	Fraction sum = { 0,1 };
	sum=sumOfElements(Fr,Fr+N);
	cout << sum; cout << "\n";
	cout << fr2; 
	if ((*fr4).isProperFraction()) cout << " is proper fraction\n";
	else cout << "is unproper fraction\n";
	Fraction propSum=sumOfProper(Fr,Fr+N);
	cout << propSum; cout << "\n";
	delete fr3; fr3 = nullptr;
	freeMemory(Fr);
	return 0;
}

Fraction::Fraction() :
	numerator(0),
	denominator(1)
{
	/*cout << "no params constructor working \n"; */
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
/*	cout << "constructor working for " << this->numerator << '/' << this->denominator << "\n"; */
};
Fraction::Fraction(const Fraction& other) :
	numerator(other.numerator),
	denominator(other.denominator)
{
/*	cout << "copy constructor working for " << this->numerator << '/' << this->denominator << "\n"; */
};
Fraction::~Fraction() { /*cout << "destructor working for..." << this->numerator << '/' << this->denominator << "\n";*/; };
Fraction Fraction::operator=(const Fraction& rhs)
{
	/*cout << "= working for " << rhs.numerator << '/' << rhs.denominator << "\n";*/
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

bool Fraction::operator==(Fraction& fr) const   
{
	return numerator == fr.numerator && denominator == fr.denominator;
}
bool Fraction::operator!=(Fraction& fr) const
{
	return numerator != fr.numerator || denominator != fr.denominator;
}
bool Fraction::operator<(Fraction& fr) const
{
	if (numerator * fr.denominator < fr.numerator * denominator)
		return true;
	else return false;
}
bool Fraction::operator>(Fraction& fr) const
{
	if (numerator * fr.denominator > fr.numerator * denominator)
		return true;
	else return false;
}
bool Fraction::operator<=(Fraction& fr) const
{
	if (numerator * fr.denominator < fr.numerator * denominator || numerator * fr.denominator == fr.numerator * denominator)
		return true;
	else return false;
}
bool Fraction::operator>=(Fraction& fr) const
{
	if (numerator * fr.denominator > fr.numerator* denominator || numerator * fr.denominator == fr.numerator * denominator)
		return true;
	else return false;
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

