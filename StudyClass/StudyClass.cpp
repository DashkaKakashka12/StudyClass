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

	/*Point point(23, 22, 21);
	point.Print();


	
	ofstream file;
	file.open(path, ofstream::app);

	if (!file.is_open()) {
		cout << "Ошибка открытия файла" << endl;
	}
	else {
		cout << "Файл открыт" << endl;
		file.write((char*)&point, sizeof(Point)); //первым параметром передаём указатель на ссылку объекта(он должен быть типа char  поэтому используем приведение)
		// вторым параметром передаём размерность всего класса использую sizeof


	}


	file.close();*/


	ifstream file2;
	file2.open(path);

	if (!file2.is_open()) {
		cout <<"Ошибка открытия файла"<< endl;
	}
	else {
		cout << "Файл открыт" << endl;
		Point pnt;
		while (file2.read((char*)&pnt, sizeof(Point))) { //пока read может забрать строку и возвращает true в while действие выполняется
			pnt.Print();
		}
		
	}

	file2.close();

	return 0;
}
