//После каждого слова строки, оканчивающегося заданной подстрокой, вставить указанный символ.


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

const int maxSize = 10000;
const int subSize = 10;

void Task(char*&, char*, char*);
int wordCounter(char*, char*);
int main()
{ // объявление основных данных, ввод строк, выполнение функции
	setlocale(LC_ALL, "Russian");

	char* str = nullptr;
	str = new(nothrow) char[maxSize];
	char* subStr = nullptr;
	subStr = new(nothrow) char[subSize];
	char* symb = nullptr;
	symb = new(nothrow) char[2];

	cout << "Введите строку: \n";
	cin.getline(str, maxSize);
	cout << "Введите подстроку: \n";
	cin.getline(subStr, subSize);
	cout << "Введите символ, который желаете вставить:";
	cin >> symb;
	Task(str, subStr, symb);
	cout << '\n' << str;
	delete[] str; str = nullptr;
	delete[] subStr; subStr = nullptr;
	delete[] symb; symb = nullptr;
}
int wordCounter(char* str, char* subStr)
{
	char separetors[]{ " '~`.,/|(;)\":!?" };
	char* p = str,
		* tmpP = nullptr;
	int length = strlen(str),
		subLength = strlen(subStr),
		counter = 0;
	while (1)
	{
		tmpP = strstr(p, subStr); // tmp указывает на начало подстроки
		p = tmpP + subLength; // p указывает на символ следующий за подстрокой
		if (!tmpP) break;
		if (strpbrk(p, separetors) || *p == '\0') counter++;
	}
	return counter;
}
void Task(char*& str, char* subStr, char* symb)
{
	char separetors[]{" '~`.,/|(;)\":!?"};
	char* p = str,
		* tmpP = nullptr,
		* beg = str;
	int subLength = strlen(subStr),
		length = strlen(str),
		count = wordCounter(str, subStr);

	cout << "there are " << count << " words with subStr \n";

	char* tmpStr = nullptr;
	tmpStr = new(nothrow) char[strlen(str) + 2 + count]; //создание временного массива символов
	count = 0;
	char* start = tmpStr; //место, с которого заполняю строку tmpStr
	int startLen = 0;

	while (1)
	{
		tmpP = strstr(p, subStr); // tmp указывает на начало подстроки
		p = tmpP + subLength; // p указывает на символ следующий за подстрокой 
		if (!tmpP)
		{
			if (str+length-beg > 0)  strcpy(start, beg);
			break;
		}
		if (strpbrk(p, separetors) || *p == '\0')
		{
			strncpy(start, beg, p - beg); // beg указывает на начало вставки, а p на конец вставки
			start = start + (p - beg);
			strcpy(start, symb);
			start += 1;
			strncpy(start, p, 1);
			start += 1;
			beg = p + 1;
		}

	}
	//cout << "\n"<<tmpStr;

	delete[] str;	str = tmpStr;  tmpStr = nullptr;
}
