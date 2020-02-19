/* вычислить значение функции f(x) = 2xe^x + sin2x
   на отрезке [a;b] с шагом h и точностью еps, 
   используя разложение в ряд тейлора  */
// в точке 0 что-то пошло не так...
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void printTable(double , double , double , double , double );
double function(double , double );

int main() {
	setlocale(LC_ALL, "Russian");
	double a = 0, b = 0, x = 1, h = 0, eps = 0;
	cout << "Введите начало интервала а:  \n"; cin >> a;
	cout << "Введите конец интервала b: \n"; cin >> b;
	cout << "Введите шаг h:  \n"; cin >> h;
	cout << "Введите погрешность eps: \n"; cin >> eps;
	printTable(x, a, b, h, eps);
	return 0;
}
void printTable(double x, double a, double b, double h, double eps) // таблица значений функции
{
	cout << "Таблица значений функции: \n";
	for (x = a; x <= b + h / 2; x += h)
	{
		cout << "x = " << setw(6) << x << setw(10) << function(x, eps) << setw(10) << (2 * x * exp(x) + sin(2 * x));
		cout << "\n";
	}
}
double function(double x, double eps)  // функция
{
	double sum = 1, term = 1;
	int i = 1;
	//вычисление e^x:
	while (fabs(term) > eps)
	{
		term = term * x / i;
		sum = sum + term;
		i++;
	}
	//2*x*e^x:
	sum = sum * 2 * x;
	// 2*x*e^x + sin2x:
	term = 2*x;
	sum += term;
	i = 3;
	while (fabs(term) > eps)
	{
		term = term * (-4) * x * x / i / (i - 1);
		sum += term;
		i += 2;
	}
	return sum;
}

