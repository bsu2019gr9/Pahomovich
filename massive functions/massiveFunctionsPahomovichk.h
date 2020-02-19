int* giveMemory(int);
void freeMemory(int*);
void printArray(int*, const int&); // печать массива
void inputArray(int*, const int&); //
void initRandArray(int*, const int&); //инициализация элементов массива
void initArray(int*, const int&);//генерирует случайные числа от -k до k
void initSortedArr(int*, const int&); // вводит отсортированный массив рандомных чисел

int findMax(int*, const int&); // возвпащает максимальный элемент массива
int findMin(int*, const int&); // возвращает минимальный элемент массива
void findMaxMin(int*, const int&, int&, int&); // ищем одновременно максимальный и минимальный элементы массивов
int findSum(int*, const int&); // возвращает сумму всех элементов массива
int findIdMax(int*, const int&);
int findIdMin(int*, const int&);

void reverce(int*, const int&);//реверс массива
void swap(int&, int&);


bool areEqual(int*, const int&, int*, const int&); // проверка эквивалентности соответствующих элементов массива (эквивалентности массивов)
void copyArr(int*, const int&, int*, const int&); // копирует массив в другой массив

void bubbleSort(int*, const int&);// сортировка пузырьком
void evenOddSort(int*, const int&); //чётно-нечётная сортировка
void ShellSort(int*, const int&); // сортировка Шелла
void shuffleArr(int*, const int&); //тасует элементы массива (несколько реверсов массива по частям)
void shakeArr(int*, const int&); // перетасовка элементов массива (смена местами рандомных элементов) 
void moveLeft(int*, const int&, const int&); // сдвиг массива на к элементов влево
void moveRight(int*, const int&, const int&); //сдвиг массива на к элементов вправо

void MargerArr(int*, int*, int*, const int&, const int&);//слияние двух первых массивов А и В с размерами m и n соответственно в массив С размером в два раза больше максимального
void CompressArr(int*, const int&, const int&, const int&); // сжатие массива. остаются значения в диапазоне [a;b]
int summIf(int*, const int&, int); //возвращает сумму элементов между first max и last min в случаях, когда условие не выполняется, возвращается sum = 0
