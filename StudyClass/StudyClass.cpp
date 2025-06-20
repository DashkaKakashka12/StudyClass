#include <iostream>

using namespace std;

class Human {

public:
	int age;
	int weight;
	string name;

	void Print() {
		age += 5;
		cout << age << endl;
		cout << weight << endl;
		cout << name << endl;
	}
};


class Point {
private:
	int x;
	int y;

public:

	Point() {
		x = 0;
		y = 0;
		cout << this << " constr" << endl;
	}

	Point(int valueX, int valueY) {
		x = valueX;
		y = valueY;
		cout << this << " constr" << endl;
	}

	bool operator == (const Point& other) {
		return this->x == other.x && this->y == other.y;
	}

	bool operator != (const Point& other) {
		return !(this->x == other.x && this->y == other.y);
	}

	Point operator +(const Point& other) {
		Point temp;
		temp.x = this->x + other.x;
		temp.y = this->y + other.y;
		return temp;
	}

	int GetX() {
		return x;
	}

	void SetX(int valueX) {
		x = valueX;
	}

	int GetY() {
		return y;
	}

	void SetY(int y) {
		this->y = y;
	}

	void Print() {
		cout << "x = " << x << endl;
		cout << "y = " << y << endl << endl;
	}
};

class CoffeGrinder {
private:
	bool ChekVoltage() {
		return true;
	}


public:
	void Start() {
		if (ChekVoltage())
		{
			cout << "Вжуууух" << endl;
		}
		else {
			cout << "Напряжение не в норме. НЕ ВЖУХ(((" << endl;
		}

	}
};

class MyClass {
private:
	int* data;
	int Size;

public:

	MyClass(int size) {
		this->data = new int[size];
		this->Size = size;

		for (int i = 0; i < size; i++)
		{
			data[i] = i;
		}
		cout << data << " Вызвался конструктор " << this << endl;
	}

	MyClass(const MyClass& other) {

		this->Size = other.Size;
		this->data = new int[other.Size];
		for (int i = 0; i < Size; i++)
		{
			this->data[i] = other.data[i];
		}
		cout << data << " Вызвался конструктор копирования" << this << endl;


	}

	~MyClass() {
		cout << data << " Вызвался деструктор " << this << endl;
		delete[] data;
	}
};


void Foo(MyClass value) {
	cout << "Вызвалась функция Foo" << endl;
}

MyClass Foo2() {

	cout << "Вызвалась функция Foo2" << endl;
	MyClass temp(2);

	return temp;
}


int main() {
	setlocale(LC_ALL, "RU");

	/*MyClass a(10);
	MyClass b(a);*/

	Point a(5, 1);
	Point b(77, 12);

	Point c = a + b;


	return 0;
}