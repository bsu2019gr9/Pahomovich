#include<iostream>
#include<fstream>  
#include <clocale>
using namespace std;
struct color { unsigned char r; unsigned char g; unsigned char b; } c;
void diagonalGradient(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, int, int, int, ofstream&); // диагональный градиент
void horizontalGradient(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, int, int, int, ofstream&); // горизонтальный градиент
void verticalGradient(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, int, int, int, ofstream&);// вертикальный градиент

int main() {
	setlocale(LC_ALL, "Russian");
	ifstream takeFrom("d:\\paint.bmp", ios::binary); //  ios::binary влияет ТОЛЬКО на endl.
	ofstream putInto("d:\\rez.bmp", ios::binary);//сюда пишем (поток типа ofstream= output file stream)
	if (!takeFrom) { cout << "No file d:\\paint.bmp. Can't open\n"; exit(1); }
	if (!putInto) { cout << "   file d:\\rez.bmp. Can't create\n"; exit(1); }

	unsigned char endR(0), endG(0), endB(0); // конечный цвет
	unsigned char begR(0), begG(0), begB(0); // первоначальный цвет;
	int step(80);
	char buf[78];// Куда читать байты
	color c;
	int wid, heig;
	int grad = 1;

	takeFrom.read((char*)&buf, 18);   //Чтение 18 байт заголовка (куда, сколько)
	putInto.write((char*)&buf, 18);    //Запись 18 байт заголовка 
	takeFrom.read((char*)&wid, 4); cout << "w=" << wid;   //Чтение width из заголовка
	takeFrom.read((char*)&wid, 4); cout << ", h=" << wid; //Чтение height из заголовка
	wid = 600; heig = 400;
	putInto.write((char*)&wid, 4);    //Запись width в заголовок bmp ( w кратно 4, обязательно для нас, чтобы не делать выравнивание)
	putInto.write((char*)&heig, 4);    //Запись height в заголовок bmp
	takeFrom.read((char*)&buf, 28);   //Чтение 28 байт заголовка bmp
	putInto.write((char*)&buf, 28);    //Запись 28 байт заголовка bmp

	begR = 15;	begG = 201;	begB = 244;
	endR = 200;	endG = 33;	endB = 104;
	step = 80;//неверно работает при step=255
	/*	begR = 150;	begG = 255;	begB = 0;
	endR = 200;	endG = 33;	endB = 104;*/

	if (step > wid)   step = wid;

	cout << "\n Which gradient do you want?\n 1 - horizontal gradient;\n 2 - vertical gradient;\n 3 - diagonalGradient.\n";
	cin >> grad;
	switch (grad)
	{
	case 1: 	horizontalGradient(begR, begG, begB, endR, endG, endB, wid, heig, step, putInto); cout << "Let's see your gradient! \n"; break;
	case 2: 	verticalGradient(begR, begG, begB, endR, endG, endB, wid, heig, step, putInto); cout << "Let's see your gradient! \n"; break;
	case 3: 	diagonalGradient(begR, begG, begB, endR, endG, endB, wid, heig, step, putInto); cout << "Let's see your gradient! \n"; break;
	default:    cout << "Your chose incorrect, goodby! \n";
	}
	
	takeFrom.close();//закрыли файл
	putInto.close();//закрыли файл
	return 0;
}

void diagonalGradient(unsigned char begR, unsigned char begG, unsigned char begB, unsigned char endR, unsigned char endG, unsigned char endB, int wid, int heig, int step, ofstream& putInto)
{
	float cR = (float)begR, cG = (float)begG, cB = (float)begB;
	float tR = (float)begR, tG = (float)begG, tB = (float)begB;
	float colorStep = wid / step;
	float tmpStep = colorStep;
	float colorStepH = heig / step;
	float tmpStepH = colorStepH;
	float stepR = (float)(endR - begR) / step / 2;
	float stepG = (float)(endG - begG) / step / 2;
	float stepB = (float)(endB - begB) / step / 2;
	for (int i = 1; i <= heig; i++) {
		for (int j = 1; j <= wid; j++) {
			if (j == colorStep) {
				colorStep += tmpStep;
				cR += stepR;
				cG += stepG;
				cB += stepB;
			}
			c.r = (unsigned char)cR;
			c.g = (unsigned char)cG;
			c.b = (unsigned char)cB;
			putInto.write((char*)&c.b, sizeof(c.b));
			putInto.write((char*)&c.g, sizeof(c.g));
			putInto.write((char*)&c.r, sizeof(c.r));
		}
		if (i == colorStepH)
		{
			tR += stepR;
			tG += stepG;
			tB += stepB;
			colorStepH += tmpStepH;
		}

		cR = tR;
		cG = tG;
		cB = tB;

		colorStep = tmpStep;
	}
}

void horizontalGradient(unsigned char begR, unsigned char begG, unsigned char begB, unsigned char endR, unsigned char endG, unsigned char endB, int wid, int heig, int step, ofstream& putInto)
{
	float colorStep = wid / step;
	float tmpStep = colorStep;
	float cR = (float)begR, cG = (float)begG, cB = (float)begB;
	float stepR = (float)(endR - begR) / step;
	float stepG = (float)(endG - begG) / step;
	float stepB = (float)(endB - begB) / step;
	cR = (float)begR;
	cG = (float)begG;
	cB = (float)begB;
	for (int i = 1; i <= heig; i++) {
		for (int j = 1; j <= wid; j++) {
			if (j == colorStep) {
				colorStep += tmpStep;
				cR += stepR;
				cG += stepG;
				cB += stepB;
			}
			c.r = (unsigned char)cR;
			c.g = (unsigned char)cG;
			c.b = (unsigned char)cB;
			putInto.write((char*)&c.b, sizeof(c.b));
			putInto.write((char*)&c.g, sizeof(c.g));
			putInto.write((char*)&c.r, sizeof(c.r));
		}
		cR = (float)begR;
		cG = (float)begG;
		cB = (float)begB;
		colorStep = tmpStep;
	}
}

void verticalGradient(unsigned char begR, unsigned char begG, unsigned char begB, unsigned char endR, unsigned char endG, unsigned char endB, int wid, int heig, int step, ofstream& putInto)
{
	float colorStepH = heig / step;
	float tmpStepH = colorStepH;
	float cR = (float)begR, cG = (float)begG, cB = (float)begB;
	float tR = (float)begR, tG = (float)begG, tB = (float)begB;
	float stepR = (float)(endR - begR) / step;
	float stepG = (float)(endG - begG) / step;
	float stepB = (float)(endB - begB) / step;
	for (int i = 1; i <= heig; i++) {
		for (int j = 1; j <= wid; j++) {
			
			c.r = (unsigned char)cR;
			c.g = (unsigned char)cG;
			c.b = (unsigned char)cB;
			putInto.write((char*)&c.b, sizeof(c.b));
			putInto.write((char*)&c.g, sizeof(c.g));
			putInto.write((char*)&c.r, sizeof(c.r));
		}
		if (i == colorStepH)
		{
			tR += stepR;
			tG += stepG;
			tB += stepB;
			colorStepH += tmpStepH;
		}
		cR = tR;
		cG = tG;
		cB = tB;
	}
}
