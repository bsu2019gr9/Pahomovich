#include <iostream>
#include <iomanip>
#include<ctime>
#include "massiveFunctionsPahomovichk.h"

using namespace std;


int findIdMin(int* arr, const int& N) {
	int minId = 0;
	for (int i = 1; i < N; i++)if (arr[i] < arr[minId])minId = i;
	return minId;
}
int findIdMax(int* arr, const int& N) {
	int maxId = 0;
	for (int i = 1; i < N; i++)if (arr[i] > arr[maxId])maxId = i;
	return maxId;
}
void printArray(int* arr, const int& N) {
	for (int i = 0; i < N; ++i)cout << arr[i] << " ";
	cout << '\n';
}
void inputArray(int* arr, const int& N) {
	for (int i = 0; i < N; ++i)cin >> arr[i];
}

/*void initArray(int* Arr, const int& N)
{
	int k;
	srand(time(0));
	cout << "your k for [-k; k] ? \n";
	cin >> k;
	for (int i = 0; i < N; ++i)  Arr[i] = rand() % (2 * k + 1) - k;
}*/

void initArray(int* Arr, const int& N)
{
	for (int i = 0; i < N; ++i)  Arr[i] = i;
}

void initRandArray(int* arr, const int N)
{
	srand(time(NULL));
	for (int i = 0; i < N; ++i)
		arr[i] = 0 + rand() % 100;
}

void initSortedArr(int* Arr, const int& N)
{
	int nuch = 10, num = 0;
	srand(time(NULL));
	for (int i = 0; i < N; ++i)
	{
		num = rand() % (nuch)+0;
		if (num >= Arr[i - 1])   Arr[i] = num;
		else --i;
		nuch = Arr[i] + 5;
	}
}

int findMax(int* arr, const int& N) {
	int max = arr[0];
	for (int i = 0; i < N; i++)if (arr[i] > max)max = arr[i];
	return max;
}
int findMin(int* arr, const int N) {
	int min = arr[0];
	for (int i = 0; i < N; i++)if (arr[i] < min)min = arr[i];
	return min;
}
void findMaxMin(int* arr, const int& N, int& min, int& max) {

	for (int i = 0; i < N; i++) { if (arr[i] < min)min = arr[i]; if (arr[i] > max)max = arr[i]; }
}
int findSum(int* arr, const int N) {
	int s = 0;
	for (int i = 0; i < N; i++)
		s += arr[i];
	return s;
}

void reverce(int* Arr, const int& N)
{
	for (int i = 0; i < N / 2; ++i)
	{
		swap(Arr[i], Arr[N - 1 - i]);
	}
}

void shuffleArr(int* Arr, const int& N)
{
	reverce(Arr, N / 4);
	reverce(Arr, N / 2);
	reverce(Arr, N);
	reverce(Arr, N / 4);
}
void shakeArr(int* Arr, const int& N)
{
	int k = 0;
	srand(time(NULL));
	for (int i = 0; i < N; ++i)
	{
		k = rand() % N;
		swap(Arr[i], Arr[k]);
	}
}
void swap(int& a, int& b)
{
	int t;
	t = a;
	a = b;
	b = t;
}
void copyArr(int* RHS, const int& NR, int* LHS, const int& NL) // копирование массива 
{
	if (NR == NL) {
		for (int i = 0; i < NL; ++i)
			LHS[i] = RHS[i];
	}
}


void bubbleSort(int* Arr, const int& N)
{
	for (int j = 0; j < N - 1; ++j)
		for (int i = 0; i < N - 1; ++i)
		{
			if (Arr[i] > Arr[i + 1])
			{
				swap(Arr[i], Arr[i + 1]);
			}
		}
}

bool areEqual(int* RHS, const int& NR, int* LHS, const int& NL) // проверка массивов на совпадение элементов
{
	if (NL != NR) return false;
	else
	{
		for (int i = 0; i < NL; ++i)
			if (LHS[i] != RHS[i]) return false;
		return true;
	}
}

void evenOddSort(int* Arr, const int& N)
{
	int i = 0, j = 0, cnt = 1;
	while (cnt)
	{
		cnt = 0;
		if (N % 2 == 0) {
			for (i = 0; i < N - 1; i += 2)
				if (Arr[i] > Arr[i + 1]) { swap(Arr[i], Arr[i + 1]); ++cnt; }

			for (j = 1; j < N - 2; j += 2)
				if (Arr[j] > Arr[j + 1]) { swap(Arr[j], Arr[j + 1]); ++cnt; }
		}
		else
		{
			for (i = 0; i < N - 2; i += 2)
				if (Arr[i] > Arr[i + 1]) { swap(Arr[i], Arr[i + 1]); ++cnt; }

			for (j = 1; j < N - 1; j += 2)
				if (Arr[j] > Arr[j + 1]) { swap(Arr[j], Arr[j + 1]); ++cnt; }
		}

	}
}

void ShellSort(int* Arr, const int& N)
{
	int tmp;
	int step = 0, i = 0, j = 0;
	for (step = N / 2; step > 0; step /= 2) {
		for (i = step; i < N; ++i) {
			for (j = i - step; j >= 0 && Arr[j] > Arr[j + step]; j -= step)
			{
				swap(Arr[j], Arr[j + step]);
			}
		}
	}
}

void CompressArr(int* Arr, const int& n, const int& a, const int& b)
{
	int i = 0, j = 0;
	for (i = 0; i <= n; ++i)
		if (fabs(Arr[i]) >= a && fabs(Arr[i]) <= b)
		{
			for (j = i; j < n - 1; j++)
				Arr[j] = Arr[j + 1];
			Arr[j] = 0;
			i--;
		}
}

void MargerArr(int* A, int* B, int* C, const int& m, const int& n)
{
	int i = 0, j = 0, k = 0;
	for (k = 0; k < (n + m); ++k)
		if (A[i] < B[j])
		{
			C[k] = A[i]; if (i < n) ++i; else { for (j = n - 1; j < m; ++j) { C[k] = B[j]; k++; }  break; }
		}
		else {
			C[k] = B[j]; if (j < m) ++j; else { for (i = m - 1; i < n; ++i) { C[k] = A[i]; k++; }  break; }
		}
}

int summIf(int* Arr, const int& n, int sum) {
	int min, max;
	min = max = Arr[0];
	int im = 0, iM = 0;
	for (int i = 0; i < n; i++) {
		if (Arr[i] <= min) { min = Arr[i]; im = i; }
		if (Arr[i] > max) { max = Arr[i]; iM = i; }
	}
	cout << "\n last min: " << min << "first max: " << max << "\n";
	if (im > iM&& im - 1 != iM)
	{
		for (int i = iM + 1; i < im; ++i)
		{
			sum += Arr[i];
		}
		return sum;
	}
	else return 0;
}

void moveLeft(int* Arr, const int& n, const int& k)
{
	reverce(Arr, k);
	reverce(Arr, n);
	reverce(Arr, n - k);
}
void moveRight(int* Arr, const int& n, const int& k)
{
	reverce(Arr, n - k);
	reverce(Arr, n);
	reverce(Arr, k);
}

int* giveMemory(int N)
{
	int* Arr = nullptr;
	Arr = new int[N];
	return Arr;
}
void freeMemory(int* Arr)
{
	if (Arr)
	{
		delete[] Arr; Arr = nullptr;
	}
	else
	{
		cout << "Array is already empty."; return;
	}
}
#include <iostream>
#include <iomanip>
#include<ctime>
#include "massiveFunctionsPahomovichk.h"

using namespace std;


int findIdMin(int* arr, const int& N) {
	int minId = 0;
	for (int i = 1; i < N; i++)if (arr[i] < arr[minId])minId = i;
	return minId;
}
int findIdMax(int* arr, const int& N) {
	int maxId = 0;
	for (int i = 1; i < N; i++)if (arr[i] > arr[maxId])maxId = i;
	return maxId;
}
void printArray(int* arr, const int& N) {
	for (int i = 0; i < N; ++i)cout << arr[i] << " ";
	cout << '\n';
}
void inputArray(int* arr, const int& N) {
	for (int i = 0; i < N; ++i)cin >> arr[i];
}

/*void initArray(int* Arr, const int& N)
{
	int k;
	srand(time(0));
	cout << "your k for [-k; k] ? \n";
	cin >> k;
	for (int i = 0; i < N; ++i)  Arr[i] = rand() % (2 * k + 1) - k;
}*/

void initArray(int* Arr, const int& N)
{
	for (int i = 0; i < N; ++i)  Arr[i] = i;
}

void initRandArray(int* arr, const int N)
{
	srand(time(NULL));
	for (int i = 0; i < N; ++i)
		arr[i] = 0 + rand() % 100;
}

void initSortedArr(int* Arr, const int& N)
{
	int nuch = 10, num = 0;
	srand(time(NULL));
	for (int i = 0; i < N; ++i)
	{
		num = rand() % (nuch)+0;
		if (num >= Arr[i - 1])   Arr[i] = num;
		else --i;
		nuch = Arr[i] + 5;
	}
}

int findMax(int* arr, const int& N) {
	int max = arr[0];
	for (int i = 0; i < N; i++)if (arr[i] > max)max = arr[i];
	return max;
}
int findMin(int* arr, const int N) {
	int min = arr[0];
	for (int i = 0; i < N; i++)if (arr[i] < min)min = arr[i];
	return min;
}
void findMaxMin(int* arr, const int& N, int& min, int& max) {

	for (int i = 0; i < N; i++) { if (arr[i] < min)min = arr[i]; if (arr[i] > max)max = arr[i]; }
}
int findSum(int* arr, const int N) {
	int s = 0;
	for (int i = 0; i < N; i++)
		s += arr[i];
	return s;
}

void reverce(int* Arr, const int& N)
{
	for (int i = 0; i < N / 2; ++i)
	{
		swap(Arr[i], Arr[N - 1 - i]);
	}
}

void shuffleArr(int* Arr, const int& N)
{
	reverce(Arr, N / 4);
	reverce(Arr, N / 2);
	reverce(Arr, N);
	reverce(Arr, N / 4);
}
void shakeArr(int* Arr, const int& N)
{
	int k = 0;
	srand(time(NULL));
	for (int i = 0; i < N; ++i)
	{
		k = rand() % N;
		swap(Arr[i], Arr[k]);
	}
}
void swap(int& a, int& b)
{
	int t;
	t = a;
	a = b;
	b = t;
}
void copyArr(int* RHS, const int& NR, int* LHS, const int& NL) // копирование массива 
{
	if (NR == NL) {
		for (int i = 0; i < NL; ++i)
			LHS[i] = RHS[i];
	}
}


void bubbleSort(int* Arr, const int& N)
{
	for (int j = 0; j < N - 1; ++j)
		for (int i = 0; i < N - 1; ++i)
		{
			if (Arr[i] > Arr[i + 1])
			{
				swap(Arr[i], Arr[i + 1]);
			}
		}
}

bool areEqual(int* RHS, const int& NR, int* LHS, const int& NL) // проверка массивов на совпадение элементов
{
	if (NL != NR) return false;
	else
	{
		for (int i = 0; i < NL; ++i)
			if (LHS[i] != RHS[i]) return false;
		return true;
	}
}

void evenOddSort(int* Arr, const int& N)
{
	int i = 0, j = 0, cnt = 1;
	while (cnt)
	{
		cnt = 0;
		if (N % 2 == 0) {
			for (i = 0; i < N - 1; i += 2)
				if (Arr[i] > Arr[i + 1]) { swap(Arr[i], Arr[i + 1]); ++cnt; }

			for (j = 1; j < N - 2; j += 2)
				if (Arr[j] > Arr[j + 1]) { swap(Arr[j], Arr[j + 1]); ++cnt; }
		}
		else
		{
			for (i = 0; i < N - 2; i += 2)
				if (Arr[i] > Arr[i + 1]) { swap(Arr[i], Arr[i + 1]); ++cnt; }

			for (j = 1; j < N - 1; j += 2)
				if (Arr[j] > Arr[j + 1]) { swap(Arr[j], Arr[j + 1]); ++cnt; }
		}

	}
}

void ShellSort(int* Arr, const int& N)
{
	int tmp;
	int step = 0, i = 0, j = 0;
	for (step = N / 2; step > 0; step /= 2) {
		for (i = step; i < N; ++i) {
			for (j = i - step; j >= 0 && Arr[j] > Arr[j + step]; j -= step)
			{
				swap(Arr[j], Arr[j + step]);
			}
		}
	}
}

void CompressArr(int* Arr, const int& n, const int& a, const int& b)
{
	int i = 0, j = 0;
	for (i = 0; i <= n; ++i)
		if (fabs(Arr[i]) >= a && fabs(Arr[i]) <= b)
		{
			for (j = i; j < n - 1; j++)
				Arr[j] = Arr[j + 1];
			Arr[j] = 0;
			i--;
		}
}

void MargerArr(int* A, int* B, int* C, const int& m, const int& n)
{
	int i = 0, j = 0, k = 0;
	for (k = 0; k < (n + m); ++k)
		if (A[i] < B[j])
		{
			C[k] = A[i]; if (i < n) ++i; else { for (j = n - 1; j < m; ++j) { C[k] = B[j]; k++; }  break; }
		}
		else {
			C[k] = B[j]; if (j < m) ++j; else { for (i = m - 1; i < n; ++i) { C[k] = A[i]; k++; }  break; }
		}
}

int summIf(int* Arr, const int& n, int sum) {
	int min, max;
	min = max = Arr[0];
	int im = 0, iM = 0;
	for (int i = 0; i < n; i++) {
		if (Arr[i] <= min) { min = Arr[i]; im = i; }
		if (Arr[i] > max) { max = Arr[i]; iM = i; }
	}
	cout << "\n last min: " << min << "first max: " << max << "\n";
	if (im > iM&& im - 1 != iM)
	{
		for (int i = iM + 1; i < im; ++i)
		{
			sum += Arr[i];
		}
		return sum;
	}
	else return 0;
}

void moveLeft(int* Arr, const int& n, const int& k)
{
	reverce(Arr, k);
	reverce(Arr, n);
	reverce(Arr, n - k);
}
void moveRight(int* Arr, const int& n, const int& k)
{
	reverce(Arr, n - k);
	reverce(Arr, n);
	reverce(Arr, k);
}

int* giveMemory(int N)
{
	int* Arr = nullptr;
	Arr = new int[N];
	return Arr;
}
void freeMemory(int* Arr)
{
	if (Arr)
	{
		delete[] Arr; Arr = nullptr;
	}
	else
	{
		cout << "Array is already empty."; return;
	}
}
