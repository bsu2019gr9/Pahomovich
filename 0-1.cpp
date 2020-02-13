/* вычислить значение функции f(x) = 2xe^x + sin2x
   на отрезке [a;b] с шагом h и точностью еps, 
   используя разложение в ряд тейлора 
*/
// в точке 0 чета идет не так, но я не знаю что... 
#include <iostream>
#include <cmath>
using namespace std;

void table(double , double , double , double , double );
double f(double , double );

int main() {
	double a = 0, b = 0, x = 1, h = 0, eps = 0;
	cout << " \n"; cin >> a;
	cout << " \n"; cin >> b;
	cout << " \n"; cin >> h;
	cout << " \n"; cin >> eps;
	table(x, a, b, h, eps);
	return 0;
}
void table(double x, double a, double b, double h, double eps) // таблица значений функции
{
	cout << " \n";
	for (x = a; x <= b + h / 2; x += h)
	{
		cout << "x = "; 
		cout.width(6); cout << x;
		cout.width(10); cout << f(x,eps);
		cout.width(10); cout << (2*x*exp(x)+sin(2*x));
		cout << "\n";
	}
}
double f(double x, double eps)  // функция
{
	double sum = 1, term = 1;
	//вычисление e^x:
	for (int i = 1; fabs(term) > eps; i++)
	{
		term = term * x / i;
		sum = sum + term;
	}
	//2*x*e^x:
	sum = sum * 2 * x;
	// 2*x*e^x + sin2x:
	term = 2*x;
	sum += term;
	for (int i = 3; fabs(term) > eps; i+=2)
	{
		term = term *(- 4 )* x * x / i / (i - 1);
		sum += term;
	}
	return sum;
}

