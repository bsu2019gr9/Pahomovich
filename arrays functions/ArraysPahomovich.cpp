#include <iostream>
#include <iomanip>
#include<ctime>
#include "massiveFunctionsPahomovichk.h"

using namespace std;

int* createArr( const int N)
{
	int* Arr = nullptr;
	Arr = new int[N];
	return Arr;
}
void* createArr(int N, int*& p)
{
	p = new (nothrow) int[N];
	if (!p) exit(101);
}
void freeMemory(int*& Arr)// если передавать так, то после функции нужно очистить указатель; лучше передать по ссылке, чтобы поменять 
{
	delete[] Arr; Arr = nullptr;

}

void printArray(int* beg, int* end) {
	for (int *p = beg; p < end; ++p)
	cout <<setw(3)<< *p << " ";
	cout << '\n';
}
void inputArray(int* beg, int* end) {
	for (int *p = beg; p < end; ++p)
		cin >> *p;
}

void initRandomArray(int* beg, int* end, const int m = -10, const int M = 10) {
	int d = (M - m + 1);
	for (int* p = beg; p < end; ++p)
		*p = rand() % d + m;
};

void initArray(int* beg, int* end)
{
	int i = 1;
	for (int* p = beg; p < end; ++p) 
	{
		*p = i; 
		++i;
	}
}

void initRandArray(int* beg, int* end)
{
	srand(time(NULL));
	for (int *p = beg; p < end; ++p)
		*p = 0 + rand() % 100;
}

int findSum(int* beg, int* end) {
	int s = 0;
	for (int* p = beg; p < end; ++p)
		s += *p;
	return s;
}

int findMax(int* beg, int* end) {
	int max = *beg;
	for (int* p = beg; p < end; ++p)
		if (*p > max) max = *p;
	return max;
}
int findMin(int* beg, int* end) {
	int min = *beg;
	for (int* p = beg; p < end; ++p)
		if (*p < min)min = *p;
	return min;
}

void reverse(int* beg, int* end)
{

	for (int* p = beg, *q = end - 1; p < q; ++p, --q)
	{
		swap(*p, *q);
	}
}

void shuffleArr(int* beg, int* end)
{
	reverse(beg, end);
	reverse(beg, end - (end - beg) / 3);
	reverse(beg, end - (end - beg) / 2);
	reverse(beg, (end - (end - beg) / 4));
}

void swap(int& a, int& b)
{
	int t;
	t = a;
	a = b;
	b = t;
}

void initSortedArr(int* beg, int* end)
{
	int nuch = 10, num = 0;
	srand(time(NULL));
	for (int* p = beg; p < end; ++p)
	{
		num = rand() % (nuch)+0;
		if (num >= *(p - 1))   *p = num;
		else --* p;
		nuch = *p + 5;
	}
}

void moveLeft(int* beg, int* end, const int& k)
{
	reverse(beg, beg + k);
	reverse(beg, end);
	reverse(beg, end - k);
}
void moveRight(int* beg, int* end, const int& k)
{
	reverse(beg, end - k);
	reverse(beg, end);
	reverse(beg, beg + k);
}


void findMaxMin(int* beg, int* end, int& min, int& max) {

	for (int* p = beg; p < end; ++p)
	{
		if (*p < min) min = *p;
		if (*p > max)max = *p;
	}
}

void copyArr(int* RHSbeg, int* RHSend, int* LHSbeg, int* LHSend) // копирование массива 
{
	if (RHSend - RHSbeg == LHSend - RHSbeg) {
		for (int* Lp = LHSbeg, *Rp = RHSbeg; Lp < LHSend; ++Lp, ++Rp)
			*Lp = *Rp;
	}
}

void bubbleSort(int* beg, int* end)
{
	for (int j = 0; j < (end - beg) - 1; ++j)
		for (int* p = beg; p < end - 1; ++p)
		{
			if (*p > * (p + 1))
			{
				swap(*p, *(p + 1));
			}
		}
}

bool areEqual(int* RHSbeg, int* RHSend, int* LHSbeg, int* LHSend) // проверка массивов на совпадение элементов
{
	if (RHSend - RHSbeg != LHSend - RHSbeg) return false;
	else
	{
		for (int* Lp = LHSbeg, *Rp = RHSbeg; Lp < LHSend; ++Lp, ++Rp)
			if (*Lp != *Rp) return false;
		return true;
	}
}

void shakeArr(int* beg, int* end)
{
	int k = 0;
	srand(time(NULL));
	for (int* p = beg; p < end; ++p)
	{
		k = rand() % (end - beg);
		swap(*p, *(beg + k));
	}
}

/*-----------------------old way--------------------------*/
/*----------------------- it will be done... --------------------------*/

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
			C[k] = A[i]; 
			if (i < n) ++i; 
			else { 
				for (j = n - 1; j < m; ++j) 
				{ C[k] = B[j]; k++; }  
				break; }
		}
		else {
			C[k] = B[j]; 
			if (j < m) ++j; 
			else 
			{ for (i = m - 1; i < n; ++i) 
			{ C[k] = A[i]; k++; }  
			break; }
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
	if (im > iM && im - 1 != iM)
	{
		for (int i = iM + 1; i < im; ++i)
		{
			sum += Arr[i];
		}
		return sum;
	}
	else return 0;
}
