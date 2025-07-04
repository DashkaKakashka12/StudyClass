#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;

class Point {
public:

	Point() {
		x = y = z = 0;
	}

	Point(int x, int y, int z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
	void Print() {
		cout << "x:" << x << "\ty:" << y << "\tz:" << z<< endl;
	}

	int x;
	int y;
	int z;
};


int main() {
	setlocale(LC_ALL, "RU");
	
	string path = "myFile.txt";

	fstream fs;
	fs.open(path, fstream::in | fstream::out | fstream::app); 
	//fstream::in указываем что хотим записывать данные в файл. fstream::out что хотим читать 
	if (!fs.is_open()) {
		cout << "Файл не удалось открыть " << endl;
	}
	else {

		int number;
		cout << "Файл открыт" << endl;
		cout << "1. Записать данные в файл" << endl;
		cout << "2. Прочитать все данные из файла" << endl;
		cin >> number;
		string stroka;
		if (number == 1) {
			cout << "Вводите данные" << endl;
			SetConsoleCP(1251); //переключение консоли для корректного отображения кириллицы. кодировка по умолчанию 866
			cin >> stroka;
			fs << stroka << "\n";
			SetConsoleCP(866);
		}
		else {
			cout << "Вот все данные в файле: " << endl;
			while (!fs.eof()) {
				stroka = " ";
				fs >> stroka;
				cout << stroka << endl;
			}

			
		}
	}

	fs.close();
	
	return 0;
}
