#pragma once
typedef Fraction myType;

// функции на хипе:
myType* createArr(size_t);
void* createArr(size_t, myType*&);
void freeMemory(myType*&);
myType findMax(myType*, myType*); //возвращает максимальный элемент массива
myType findMin(myType*, myType*); //возвращает минимальный элемент массива
void findMaxMin(myType*, myType*, myType&, myType&); //находит мин и макс элементы массива
void printArray(myType*, myType*); // печать массива
void inputArray(myType*, myType*); // ввод массива с клавиатуры
void initArray(myType*, myType*); // инициализация массива
void initRandomArray(myType*, myType*, const int = -5, const int = 5); // иницилизация массива рандомными значениями
myType sumOfElements(myType*, myType*); //возвращает сумму элементов массива
Fraction sumOfProper(Fraction*, Fraction*); //подсчёт суммы правильных дробей
void bubbleSort(myType*, size_t); // пузырьковая сортировка
void reverse(myType*, myType*);

// функции на стеке:
myType findMax(myType*, size_t); //возвращает максимальный элемент массива
myType findMin(myType*, size_t); //возвращает минимальный элемент массива
void bubbleSort(myType*, size_t); // пузырьковая сортировка
myType sumOfElements(myType*, size_t); //возвращает сумму элементов массива
void printArray(myType*, size_t); // печать массива
void inputArray(myType*, size_t); // ввод массива с клавиатуры