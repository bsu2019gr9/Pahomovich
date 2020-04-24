#include <iostream>
#include <iomanip>
#include<ctime>
#include <cmath>
#include "FractionStruct.h"
#include "FractionFunctions.h"
using namespace std;
typedef Fraction myType;

// функции на хипе
Fraction sumOfElements(myType* beg, myType* end)
{
	myType sum = { 0,1 };
	for (myType* p = beg; p < end; ++p)
	{
		sum += *p;
	}
	return sum;
}
void findMaxMin(myType* beg, myType* end, myType& min, myType& max) {

	for (myType* p = beg; p < end; ++p)
	{
		if (*p < min) min = *p;
		if (*p > max)max = *p;
	}
}
myType findMax(myType* beg, myType* end) {
	myType max = *beg;
	for (myType* p = beg; p < end; ++p)
		if (*p > max) max = *p;
	return max;
}
myType findMin(myType* beg, myType* end) {
	myType min = *beg;
	for (myType* p = beg; p < end; ++p)
		if (*p < min) min = *p;
	return min;
}
void printArray(myType* beg, myType* end) {
	for (myType* p = beg; p < end; ++p)
	{
		cout << *p; cout << " ";
	}
	cout << '\n';
}
void inputArray(myType* beg, myType* end) {
	for (myType* p = beg; p < end; ++p)
		cin >> *p;
}
void bubbleSort(myType* beg, size_t N)
{
	for (size_t j = 0; j < N; ++j)
		for (myType* p = beg; p < beg + N - 1; ++p)
		{
			if (*p > * (p + 1))
			{
				swap(*p, *(p + 1));
			}
		}
}
Fraction sumOfProper(Fraction* beg, Fraction* end) {
	Fraction sum = { 0,1 };
	for (Fraction* p = beg; p < end; ++p)
	{
		if ((*p).isProperFraction()) sum += *p;
	}
	return sum;
}
void initArray(myType* beg, myType* end) {
	int i = 1;
	for (myType* p = beg; p < end; ++p)
		*p = { i,++i };
}
myType* createArr(size_t N)
{
	myType* Arr = nullptr;
	try { Arr = new myType[N]; }
	catch (...) { cout << "No memory...\n"; exit(101); }
	return Arr;
}
void* createArr(size_t N, myType*& Arr)
{
	Arr = new (nothrow) myType[N];
	if (!Arr) exit(101);
}
void freeMemory(myType*& Arr)
{
	if (Arr)
	{
		delete[] Arr; Arr = nullptr;
	}

}
void initRandomArray(myType* beg, myType* end, const int m, const int M) {
	srand(time(NULL));
	int d = (M - m + 1);
	for (myType* p = beg; p < end; ++p)
		*p = { rand() / d + m, rand() / d + m };
}
void reverse(myType* beg, myType* end)
{

	for (myType* p = beg, *q = end - 1; p < q; ++p, --q)
	{
		swap(*p, *q);
	}
}



// функции на стеке
myType findMax(myType* Arr, size_t N) {
	myType max = Arr[0];
	for (size_t i = 0; i < N; ++i)
		if (Arr[i] > max) max = Arr[i];
	return max;
}
myType findMin(myType* Arr, size_t N) {
	myType min = Arr[0];
	for (size_t i = 0; i < N; ++i)
		if (Arr[i] > min) min = Arr[i];
	return min;
}
void printArray(myType* Arr, size_t N) {
	for (size_t i = 0; i < N; ++i)
	{
		cout << Arr[i]; cout << " ";
	}
	cout << '\n';
}
void inputArray(myType* Arr, size_t N) {
	for (size_t i = 0; i < N; ++i)
		cin >> Arr[i];
}
Fraction sumOfElements(myType* Arr, size_t N)
{
	myType sum = { 0,1 };
	for (size_t i = 0; i < N; ++i)
	{
		sum += Arr[i];
	}
	return sum;
}