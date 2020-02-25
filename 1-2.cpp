//•() В массиве А(N, М) поменять местами строки, содержащие максимальный и минимальный элементы.

#include <iostream>
#include <iomanip>
#include<ctime>
#include "massiveFunctionsPahomovichk.h"
using namespace std;

int** createArray(int , int ); 
void printArray(int** , int , int );
void initRandArray(int** , int , int , int, int);
void freeMemory(int** & , int );
void swapRows(int** , int , int , int ); // меняет местами две строки
void findStrWithMinMaxEl(int** , int , int , int& , int& ); // ищет строки с минимальным и
                                                            //максимальным элементами в массиве
int main()
{	int N = 0, M = 0;
    cout << " Enter size of rows: \n ";
	cin >> N;;
	cout << " Enter size of cols: \n";
	cin >> M;
	int** arr = createArray(N, M);
	initRandArray(arr, N, M, -10, 10);
	printArray(arr, N, M);
	int minRow = 0, maxRow = 0;
	findStrWithMinMaxEl(arr, N, M, minRow, maxRow);
	swapRows(arr, minRow, maxRow, M);
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

void swapRows(int** p, int row1, int row2, int cols) {

	for (int i = 0; i < cols; ++i)
	{
		swap(p[row1][i], p[row2][i]);
	}
}

void findStrWithMinMaxEl(int** p, int N, int M, int& minRow, int& maxRow)
{
	int min = **p, max = **p;
	for (size_t i = 0; i < N; i++)
		for (size_t j = 0; j < M; j++)
		{
			if (p[i][j] <= min) { min = p[i][j]; minRow = i; }
			if (p[i][j] >= max) { max = p[i][j]; maxRow = i; }
		}
	cout << " min element: " << min << "\t in Row: " << minRow;
	cout << "\n max element: " <<max<<"\t in Row: "<< maxRow << "\n";
}


