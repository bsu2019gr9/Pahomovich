#include <iostream>
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
	Fraction(const Fraction& other); // конструктор копирования
	~Fraction(); // деструктор
	Fraction operator=(const Fraction& rhs); //оператор присваивания
	Fraction operator+(const Fraction& rhs); //сложение двух дробей
	Fraction operator-(const Fraction& rhs); //вычитание двух дробей
	Fraction operator*(const Fraction& rhs); //умножение двух дробей
	Fraction operator/(const Fraction& rhs); // деление двух дробей
	Fraction operator+(const int rhs); //прибавление числа к дроби
	Fraction operator-(const int rhs); //отнимание числа от дроби
	Fraction operator*(const int rhs); //умножение дроби на число
	Fraction operator/(const int rhs); //деление дроби на число
	friend void operator<<(ostream& out, const Fraction& f); //вывод
	friend void operator>>(istream& in, Fraction& f); //ввод
private:
	void reduceFr( ); //сокращение дроби
	int founding_GCD(int tmp_a, int tmp_b)
	{
		if (tmp_a % tmp_b == 0) return tmp_b;
		else return tmp_a % tmp_b;
	}
};

Fraction Value(Fraction fr) { 	return fr;   }
Fraction* fff(Fraction* fr) {	return fr;   }
Fraction Link(Fraction& fr) {	return fr;   }

int main() {
	int i(11);
	Fraction fr1 = { 2 , 3 };
	Fraction fr2 = { 1,2 };
	Fraction fr3 = fr2;
	Fraction Fr[4];
	Fraction* Fr2 = new Fraction(1, 2);
	Fraction* Fr3 = &fr3;
	cout << *Fr2;
	cout << fr1; cout << '\n';
	fr1 = { 1 , 2 };
	cout << fr1; cout << '\n';
	cin >> fr3;
	cout << fr2; cout << '\n';
	cout << fr3; cout << '\n';
	Fraction f4 = { 1,1 };
	f4 = fr3;
	f4 = fr3 + fr1;
	f4 = fr2 - *Fr2;
	cout << f4; cout << '\n';
	cout << Value(fr1);
	cout << Link(fr2);
	cout << fff(Fr2);
	fr2 = { 4,8 };
	fr2.reduceFr();
	cout << fr2; cout << '\n';
	delete Fr2; Fr2 = nullptr;
}

Fraction::Fraction() :
	numerator(1),
	denominator(1)
{
	cout << "no params constructor working \n";
};
Fraction::Fraction(int num, int denom = 1) : 
	numerator(num),
	denominator(denom)
{
	if (!denominator) throw "Bad arg";
	cout << "constructor working for " << this->numerator << '/' << this->denominator << "\n";
};
Fraction::Fraction(const Fraction& other) :
	numerator(other.numerator),
	denominator(other.denominator)
{
	cout << "copy constructor working for " << this->numerator << '/' << this->denominator << "\n";
};
Fraction::~Fraction() { cout << "destructor working for...\n"; };
Fraction Fraction::operator=(const Fraction& rhs)
{
	cout << "= working for " << rhs.numerator << '/' << rhs.denominator << "\n";
	numerator = rhs.numerator;
	denominator = rhs.denominator;
	return Fraction(numerator,denominator);
}

Fraction Fraction::operator+(const Fraction& rhs) 
{
	return Fraction(numerator*rhs.denominator + denominator*rhs.numerator, denominator*rhs.denominator);
}
Fraction Fraction::operator-(const Fraction& rhs)
{
	return Fraction(numerator * rhs.denominator - denominator * rhs.numerator, denominator * denominator);
}
Fraction Fraction::operator*(const Fraction& rhs) 
{
	return Fraction(numerator * rhs.numerator, denominator * rhs.denominator);
}
Fraction Fraction::operator/(const Fraction& rhs) 
{
	return Fraction(numerator * rhs.denominator, denominator * rhs.numerator);
}

Fraction Fraction::operator+(const int& rhs) 
{
	return Fraction(numerator + denominator * rhs, denominator * denominator);
}
Fraction Fraction::operator-(const int& rhs)
{
	return Fraction(numerator - denominator * rhs, denominator * denominator);
}
Fraction Fraction::operator*(const int& rhs) 
{
	return Fraction(numerator * rhs, denominator);
}
Fraction Fraction::operator/(const int& rhs) 
{
	return Fraction(numerator, denominator * rhs);
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
	numerator = numerator / b;
	denominator = denominator / b;
};
