int* createArr( const int); 
void freeMemory(int*&);
void printArray(int*, int* ); // печать массива
void inputArray(int*, int*); //
void initRandArray(int*, int*); //инициализация элементов массива
void initArray(int*, int*);//генерирует случайные числа от -k до k
void initSortedArr(int*, int*); // вводит отсортированный массив рандомных чисел
void initRandomArray(int*, int*, const int, const int);

int findMax(int*, int*); // возвпащает максимальный элемент массива
int findMin(int*, int*); // возвращает минимальный элемент массива
void findMaxMin(int*, int*, int&, int&); // ищем одновременно максимальный и минимальный элементы массивов
int findSum(int*, int*); // возвращает сумму всех элементов массива
int findIdMax(int*, const int&);
int findIdMin(int*, const int&);

void reverse(int*, int*);//реверс массива
void swap(int&, int&);

bool areEqual(int*, int*, int*, int*); // проверка эквивалентности соответствующих элементов массива (эквивалентности массивов)
void copyArr(int*, int*, int*, int*); // копирует массив в другой массив

void bubbleSort(int*, int*);// сортировка пузырьком
void evenOddSort(int*, const int&); //чётно-нечётная сортировка
void ShellSort(int*, const int&); // сортировка Шелла
void shuffleArr(int*, int*); //тасует элементы массива (несколько реверсов массива по частям)
void shakeArr(int*, int*); // перетасовка элементов массива (смена местами рандомных элементов) 
void moveLeft(int*, int*, const int&); // сдвиг массива на к элементов влево
void moveRight(int*, int*, const int&); //сдвиг массива на к элементов вправо

void MargerArr(int*, int*, int*, const int&, const int&);//слияние двух первых массивов А и В с размерами m и n соответственно в массив С размером в два раза больше максимального
void CompressArr(int*, const int&, const int&, const int&); // сжатие массива. остаются значения в диапазоне [a;b]
int summIf(int*, const int&, int); //возвращает сумму элементов между first max и last min в случаях, когда условие не выполняется, возвращается sum = 0
