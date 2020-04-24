#include <iostream>
using namespace std;

struct Fraction //хранится как "numerator/denominator"
{
private:
	int numerator; //числитель дроби
	int denominator; //знаменатель дроби
public:
	Fraction(); // конструктор без параметров
	Fraction(int, int = 1); // конструктор с параметрами 
	Fraction(const Fraction&); // конструктор копирования
	~Fraction(); // деструктор

	Fraction operator=(const Fraction&); //оператор присваивания
	Fraction operator+(const Fraction&) const; //сложение двух дробей
	Fraction operator-(const Fraction&) const; //вычитание двух дробей
	Fraction operator*(const Fraction&) const; //умножение двух дробей
	Fraction operator/(const Fraction&) const; // деление двух дробей
	Fraction operator+(const int) const; //прибавление числа к дроби
	Fraction operator-(const int) const; //отнимание числа от дроби
	Fraction operator*(const int) const; //умножение дроби на число
	Fraction operator/(const int) const; //деление дроби на число

	Fraction operator+=(const Fraction&); //прибавление дроби с присваиванием
	Fraction operator-=(const Fraction&); //вычитание дроби с присваиванием
	Fraction operator*=(const Fraction&); //умножение на дробь с присваиванием
	Fraction operator+=(const int); //прибавление целого числа с присваиванием
	Fraction operator-=(const int); //вычитание целого числа из дроби с присваиванием
	Fraction operator*=(const int); //умножение на целое число с присваиванием
	Fraction operator/=(const int); //деление на целое число с присваиванием

	bool operator==(Fraction&) const; //операция равенства
	bool operator!=(Fraction&) const; //операция неравенства
	bool operator>=(Fraction&) const; //оператор  >=
	bool operator>(Fraction&) const; //оператор  >
	bool operator<=(Fraction&) const; //оператор  <=
	bool operator<(Fraction&) const; //оператор  <
	friend void operator<<(ostream&, const Fraction&); //вывод
	friend void operator>>(istream&, Fraction&); //ввод

	bool isProperFraction(); //возвращает true, если дробь правильная и false, если неправильная

private:
	void reduceFr(); //сокращение дроби
	void findSign(); //определение знака в дроби
	int founding_GCD(int tmp_a, int tmp_b)
	{
		if (tmp_a % tmp_b == 0) return tmp_b;
		else return tmp_a % tmp_b;
	}
};