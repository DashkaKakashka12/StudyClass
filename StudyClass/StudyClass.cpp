#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std; 



class Point {
public:
	Point() {
		 x = 0.0;
		 y = 0.0;
		 z = 0.0;
	}

	Point(double x, double y, double z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

private:
	double x;
	double y;
	double z;

};

template <typename T, typename P> //всегда обязательно неотрывно перед классом. вместо typename можно писать class. функционал не меняется
class MyClass {
public:
	
	MyClass(T a, P a2) { //принимаем параментром тип шаблона
		this->a = a;
		this->a2 = a2;
	}
	
	void DataTypeSize() {
		cout << "Переменная T занимает " << sizeof(a) << " байта" << endl;
		cout << "Переменная P занимает " << sizeof(a2) << " байта" << endl;
	}

private:
	T a;
	P a2;

};

int main() {
	setlocale(LC_ALL, "RU");

	Point a;
	int a2 = 2; // обязательно надо инициализировать.	ПОЧЕМУ??

	MyClass <Point, int>ob(a, a2);//нельзя просто создать объект класса. Обязательно указываем тип данных с которым работаем 
	ob.DataTypeSize();

	return 0;
}
