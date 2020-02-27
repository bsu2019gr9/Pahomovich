//•() В массиве А(N, М) поменять местами строки, содержащие максимальный и минимальный элементы.
#include <iostream>
#include <iomanip>
#include<ctime>
#include "ArraysPahomovich.h"
using namespace std;


int** createArray(int, int);
void printArray(int**, int, int);
void initRandArray(int**, int, int, int, int);
void freeMemory(int**&, int);
void findStrWithMinMaxEl(int**, int, int, int&, int&);
void findIDStrWithMinMaxID(int**, int, int, int&, int&);
int main()
{
	int N = 0, M = 0;
	cout << " Enter size of rows: \n ";
	cin >> N;;
	cout << " Enter size of cols: \n";
	cin >> M;
	int** arr = createArray(N, M);
	initRandArray(arr, N, M, -10, 10);
	printArray(arr, N, M);
	int minRow = **arr, maxRow = **arr;
	findIDStrWithMinMaxID(arr, N, M, minRow, maxRow);
	swap(arr[minRow],arr[maxRow]);
	printArray(arr, N, M);
	freeMemory(arr, N);
}

int** createArray(int N, int M)
{
	int** p = new (nothrow) int* [N];
	if (!p) exit(404);
	for (int i = 0; i < N; i++) {
		p[i] = new (nothrow) int[M];
		if (!p[i]) exit(404);
	}
	cout << "\n";
	char a = '99';
	return p;
}
void printArray(int** p, int N, int M)
{
	for (size_t i = 0; i < N; i++) {
		for (size_t j = 0; j < M; j++)
			cout << setw(3) << p[i][j] << " ";
		cout << '\n';
	}
}
void initRandArray(int** p, int N, int M, int min, int max)
{
	srand(time(NULL));
	int d = (max - min + 1);
	for (size_t i = 0; i < N; i++)
		for (size_t j = 0; j < M; j++)
			p[i][j] = rand() % d + min;
}
void freeMemory(int**& arr, int N)
{
	for (size_t i = 0; i < N; i++) delete[] arr[i];
	delete[] arr;
	arr = nullptr;
}

void findIDStrWithMinMax(int** p, int N, int M, int& minRow, int& maxRow)
{
	int min = **p, max = **p;
	for (size_t i = 0; i < N; i++)
		for (size_t j = 0; j < M; j++)
		{
			if (p[i][j] <= min) { min = p[i][j]; minRow = i; }
			if (p[i][j] >= max) { max = p[i][j]; maxRow = i; }
		}
}



