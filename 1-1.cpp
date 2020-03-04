#include <iostream>
#include <iomanip>
#include<ctime>
#include "ArraysPahomovich.h"
using namespace std;

int Task01(int*, int*);	//В массиве размера N, заполненного случ.числами от -10 до 10, 
	                    //подсчитать количество элементов, встречающихся более одного раза.

int Task02(int*, int*);	//В массиве размера N, заполненного случ.числами от - 10 до 20,
	                    //определить максимальную длину последовательности равных элементов.


int main()
{
	int n;
	cout << "Enter size of array: \n";
	cin >> n;
	int* arr = createArr(n);
	initRandomArray(arr, arr + n, -10, 10);
	printArray(arr, arr + n);
	cout << "\n ";
	cout << " Count of Task 1: " << Task01(arr, arr + n)<<"\n";
	// inputArray(arr, arr + n); //- для проверки
	initRandomArray(arr, arr + n, -10, 20);
	printArray(arr, arr + n);
	cout << " Count of Task 2: " << Task02(arr, arr + n);
	freeMemory(arr);
}

int Task01(int* beg, int* end)
{
	bubbleSort(beg, end);
	printArray(beg, end);
	int elem = *beg, counter = 0, rez = 0;
	for (int* p = beg; p < end; ++p)
	{
		if (elem == *p) ++counter;
		else {
			if (counter > 1 && rez <= counter) rez = counter;
			counter = 1; elem = *p;
		}
	}
	return rez;
}

int Task02(int* beg, int* end)
{
	int elem = *beg, maxLength = 0, counter = 0;
	for (int* p = beg; p < end; ++p)
	{
		if (elem == *p) ++counter;
		else {
			if (maxLength <= counter) { maxLength = counter; counter = 1; }
			elem = *p;
		}
	}
	return maxLength;
}