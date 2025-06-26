#include <iostream>
#include <string>

using namespace std;

class TestClass;
class Apple; 
class HumanTakeApple;

class Human {

public: //нарушение инкапсуляции: объявление полей побличными
	int age;
	int weight;
	string name;

	void Print() { //используется для вывода установленных значений
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

	Point() { //улучшенный конструктор по умолчанию. в данном случае устанавливает 0 в значание переменной
		x = 0;
		y = 0;
		cout << this << " constr" << endl;
	}

	Point(int valueX, int valueY) { //конструктор с параметрами. принимает значения для установки в переменную изначально.
		x = valueX;
		y = valueY;
		cout << this << " constr" << endl;
	}

	bool operator == (const Point& other) { // принимаем ссылку на другую пременную с которой сравниваем (чтобы видеть значиния)
		return this->x == other.x && this->y == other.y; // возвращаем true когда все условия выполнились
	}

	bool operator != (const Point& other) {// принимаем ссылку на другую пременную с которой сравниваем (чтобы видеть значиния)
		return !(this->x == other.x && this->y == other.y); //возвращаем true если условия не верны
	}

	Point operator -(const Point& other) {// принимаем ссылку на другую пременную с которой сравниваем (чтобы видеть значиния). Объект возвращает звачение типа класса
		Point temp; // временная переменная для хранения результата
		temp.x = this->x - other.x; // наша переменная - другая по параметрам
		temp.y = this->y - other.y;
		return temp; //возвращаем временную посчитанную переменную 
	}

	Point operator +(const Point& other) { //аналогично operator -
		Point temp;
		temp.x = this->x + other.x;
		temp.y = this->y + other.y;
		return temp;
	}

	Point operator *(const Point& other) {//аналогично operator -
		Point temp;
		temp.x = this->x * other.x;
		temp.y = this->y * other.y;
		return temp;
	}

	int GetX() { //получаем значение установленное в переменной, никаких параметров не передаём. Функция возвращает переменную того же типа
		return x;
	}

	void SetX(int valueX) { //передаём в функцию значение которое и устанавливается в переменную. Функция ничего не возыращает
		x = valueX;
	}

	int GetY() {//аналогично GetX()
		return y;
	}

	void SetY(int y) { //аналогично SetX()
		this->y = y;
	}

	void Print() {
		cout << "x = " << x << endl;
		cout << "y = " << y << endl << endl;
	}

	Point& operator ++() {  // инкремент префиксный (до переменной ++a)
		this->x++;
		this->y += 1;

		return* this;
	}

	Point& operator --() { // декремент префиксный (до переменной ++a)
		this->x--;
		this->y--;

		return*this;
	}

	Point& operator ++(int value) { // декремент постфиксный (после переменной a++). Параметр передаём только для того чтобф компилятор видел разницу
		Point temp(*this); // храним значение во временной переменной чтобы увеличить сразу только его
		this->x++;
		this->y++;

		return temp;
	}

	friend void chengeX(Point& value, TestClass& testValue); //дружественная функция получает доступ к приватным полям класса. не является членом класса
};

class TestClass {
public:
	int& operator[](int index) { //принимает номер ячейки данные которой нам нужны
		return arr[index]; //возвращает значение лежащие в ячейке
	}

	friend void chengeX(Point& value, TestClass& testValue);

private:
	int arr[5] = { 1,2,3,4,5 };
	int data = 0;
};

void chengeX(Point& value, TestClass& testValue) { //не является членом класса поэтому this не работатет. Может быть дружественной к нескольким классам
	value.x = -1;
	testValue.data = 99;

}


class CoffeGrinder {
private:
	bool ChekVoltage() { // метод для проверки напряжения, напряжение либо есть либо нет(поэтому булевый)
		return true;
	}


public:
	void Start() {
		if (ChekVoltage()) //в зависимости от результата булевого метода выполняет определённое действие
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

class Metody
{
public:
	
	void Print();

private:

};

void Metody::Print() {
	cout << "Сообщение" << endl;
}

class HumanTakeApple {
public:
	void TakeApple(Apple& apple);

	void EatApple(Apple& apple) {
		
	}
};

class Apple {
	friend HumanTakeApple; //дружественный класс
private:
	int weight;
	string color;
	string name;
	int id;
	static int count;

	//friend void HumanTakeApple::TakeApple (Apple& apple); //дружественный метод
public:
	
	Apple(int weight, string color, string name) {
		this->color = color;
		this->weight = weight;
		this->name = name;
		count++;
		id = count; // оригинальные id равные количеству по созданию
	}

	int GetId() {
		return id;
	}

	static int GetCount() { //статичный метод доступен всем, но ему не доступны нестатичные параметры
		return count;
	}

	static void changeColor(Apple& apple, string color) {//статичный метод доступен всем, и ему доступны нестатичные параметры благодаря ссылке
		apple.color = color;
	}

};

int Apple::count = 0;

void HumanTakeApple::TakeApple(Apple& apple)
{
	cout << "TakeApple: " << apple.name << endl << "weight: " << apple.weight << "\ncolor:" << apple.color<< endl << endl;
}

class Image {
public:

	void GetImageInfo() {
		for (int i = 0; i < lenght; i++)
		{
			cout << pixels[i].Get() << endl;
		}
	}

private:

	class Pixel {
	private:
		int r;
		int g;
		int b;


	public:
		Pixel(int r, int g, int b) {
			this->r = r;
			this->g = g;
			this->b = b;
		}
		string Get() {
			return "Pixel: r=" + to_string(r) + " g= " + to_string(g) + " b= " + to_string(b);
		}
	};

	static const int lenght = 5;
	Pixel pixels[lenght]{
		Pixel(0, 4, 64),
		Pixel(4, 14, 10),
		Pixel(111, 4, 24),
		Pixel(244, 244, 14),
		Pixel(111, 179, 64),
	};
};


int main() {
	setlocale(LC_ALL, "RU");

	/*MyClass a(10);
	MyClass b(a);*/

	/*Point a(1, 1);
	Point b = a++;
	++a;
	Point c = a * b;*/


	/*TestClass a;
	cout << a[2] << endl;*/
	
	/*TestClass test;
	Point a(5, 12);
	a.Print();
	chengeX(a, test);
	a.Print();*/

	//Metody a;
	//a.Print();

	/*Apple apple(150, "Red", "first");
	HumanTakeApple human;
	human.TakeApple(apple);
	Apple::changeColor(apple, "Gren");
	human.TakeApple(apple);*/

	/*HumanTakeApple human;
	human.TakeApple(apple);
	Apple apple2(50, "Green");
	cout << Apple::GetCount();*/
	//cout << "\ncountAllApple:" << apple.GetCount << endl;


	Image pic;
	pic.GetImageInfo();

	return 0;
}
