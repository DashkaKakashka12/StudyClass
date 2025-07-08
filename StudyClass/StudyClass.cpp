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

class Exception :public exception { //наследуемся от классаexception
public:
	Exception(const char* msg, int dateState) :exception(msg){ //используем конструктор базового класса 
		this->dateState = dateState;
	}

	int GetDateState() const {return dateState;} // метод для отслеживания состояния данных
	//обязательно чтобы в catch, в конструкторе класса и методе было const

private: 
	int dateState;

};

void Foo(int value) {

	if (value < 0){
		throw exception("Число меньше нуля"); 
		
	}

	if (value == 1) {
		throw Exception("Число = 1", value); 
	}

	cout << "Переменная = " << value << endl;
}


int main() {
	setlocale(LC_ALL, "RU");

	try
	{
		Foo(1);

	} //важен порядок catch. exception до Exception словит прописанный throw как обычный exception
	catch (const Exception& ex) //обязательно чтобы в catch, в конструкторе класса и методе было const
	{
		cout << "Блок 1 Мы поймали " << ex.what() << endl; 
		cout << "Состояние данных " << ex.GetDateState() << endl; //метод GetDateState выводит строку самой ошибки
	}
	catch (const exception& ex)
	{
		cout << "Блок 2 Мы поймали " << ex.what() << endl; //метод what содержит строку самой ошибки
	}
	
	
	return 0;
}
