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


void Foo(int value) {

	if (value < 0){
		throw "Число меньше нуля";
		//throw exception("Число меньше нуля");//можно передать как число, строку(throw "Число меньше нуля") так и класс (exception) 
		//чаще всего использую exception и передают параметром сообщение. чтобы в failure можно было словить это exception
	}

	if (value == 0) {
		throw exception("Число 0");
	}

	if (value == 1) {
		throw 1;
	}

	cout << "Перемкнная = " << value << endl;
}


int main() {
	setlocale(LC_ALL, "RU");

	try
	{
		Foo(1);

	}
	catch (const exception& ex) //то что ловит catch должно соответстовать типу данных throw(catch автоматически ловит то что бросает throw)
	{
		cout << "Блок 1 Мы поймали " << ex.what() << endl; //метод what содержит строку самой ошибки
	}
	catch (const char* ex) {
		cout << "Блок 2 Мы поймали " << ex << endl;
	}
	catch (...) { //важен порядок написания. если такой cath будет идти до конкретных, то конкретные не словятся. он в самом конце
		cout << "что-то пошло не так" << endl;
	}
	
	return 0;
}
