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
	

private:
	int x;
	int y;
	int z;

	friend ostream& operator <<(ostream& os, const Point& point);
	friend istream& operator >>(istream& is, Point& point);
		;

};

ostream& operator <<(ostream& os, const Point& point)
{
	os << point.x << " " << point.y << " " << point.z;
	return os;
}

istream& operator >>(istream& is, Point& point)
{
	is >> point.x >> point.y >> point.z;
	return is;
}


int main() {
	setlocale(LC_ALL, "RU");


	string path = "myFile.tx";

	fstream fs;
	fs.exceptions(ifstream::badbit | ifstream::failbit); //прописываем для ручной обработки исключений
	//fs.open(path, fstream::in | fstream::out | fstream::app); 
	try
	{
		cout << "Попытка открыть файл" << endl; //дальче места ошибт код не выполнится
		fs.open(path);
		cout << "Файл успешно открыт" << endl;

	}
	catch (const ifstream::failure & ex)//можно через exceptions. но ifstream::failure предоставляет ещё и метод code
	{
		
		cout << ex.what() << endl;// вид ошибки 
		cout << ex.code() << endl; //код ошибки в документации класса
		cout << "Ошибка открытия файла" << endl;
	}

	fs.close();
	
	return 0;
}
