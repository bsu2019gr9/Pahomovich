// зад: В строках текста удалить фрагменты, заключённые в круглые скобки. (...)
// прим: Если в строке встречается "(", но не встречается ")" , в файл результата записывается вся строка без удалений

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void initNULLstr(char* , int );//заполнение всей строки символом '\0'
void newFile(char* , ifstream& , ofstream& , int );//выполнение задания
void createStr(char*&, int);//выделение памяти на строку
void freeMemory(char*& str);//освобождение памяти

int main() {
	setlocale(LC_ALL, "Russian");

	int N = 100500;
	char* str = nullptr;
	createStr(str,N);
	ifstream takeFrom("e:\\input1.txt");   //открываем файл  для чтения
	ofstream putIn("e:\\rez.txt");  // сюда записывается файл-результата
	if (!takeFrom) { cout << "No file  Can't open\n"; exit(1); }
	if (!putIn) { cout << "file  Can't create\n"; exit(1); }
	newFile(str, takeFrom, putIn, N);
	freeMemory(str);
	takeFrom.close();//закрыли файл
	putIn.close();//закрыли файл
	system("pause");
}

void createStr(char*& str, int N)
{
	str = new(nothrow) char[N];
	if (!str)
	{
		cout << " NO MEMORY! " << "\n";
	}
}
void freeMemory(char*& str)
{
	delete[] str; str = nullptr;

}
void initNULLstr(char* str, int N)
{
	for (int i = 0; i < N; ++i)
		str[i] = '\0';
}
void newFile(char* str, ifstream& takeFrom, ofstream& putIn, int N)
{
	char* beg = str; //для )
	char* end = str;//для (
	int count = 0;
	while (1) {
		takeFrom.getline(str, N - 1);
		if (takeFrom.eof()) break; //читаем пока не кончится исходный файл. Т.е. пока не прочитаем EOF.
		if (takeFrom.fail()) takeFrom.clear(); //getline при переполнении выставляет бит состояния =1. Его проверяем fail'ом. А потом подчищаем буфер
		beg = str;
		end = str;
		while (1)
		{
			end = strstr(beg, "(");
			if (end && strstr(beg, ")"))
			{
				char* tmp = nullptr;
				createStr(tmp, end-beg+1);
				initNULLstr(tmp, end - beg + 1);
				strncpy(tmp, beg, end - beg);
				putIn << tmp;
				beg = strstr(beg, ")") + 1;
				freeMemory(tmp);
			}
			else {
				putIn << beg;//в файл
				break;
			}
		}
		count++;
		putIn << '\n';//переход на новую строку пишем в date2.txt только, если в строке 16 мы прочитали действительно СТРОКУ (до endl), а не последнюю строку афйла в которой EOF, а не endl
	}

	cout << "-----In file " << count << " lines";
}