#include <iostream>
#include <iomanip>
#include<ctime>
#include <cmath>
#include "FractionStruct.h"
using namespace std;

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
	return Fraction(numerator, denominator);
}

Fraction Fraction::operator+(const Fraction& rhs) const
{
	return Fraction(numerator * rhs.denominator + denominator * rhs.numerator, denominator * rhs.denominator);
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
	if (numerator * fr.denominator > fr.numerator* denominator)
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
		if (a % b == 0) { break; }
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