#include <iostream>
#include <string>

using namespace std;


class Car {
private:

public:
	Car()
	{
		cout << "вызвался конструктор класса Car" << endl;

	}
	string str = "Поле класса машина";
	void Use() {
		cout << "Я еду" << endl;
	}
	~Car()
	{
		cout << "вызвался деструктор класса Car" << endl;

	}

};


class Airplain {
private:

public:
	Airplain()
	{
		cout << "вызвался конструктор класса Airplain" << endl;

	}
	string str2 = "Поле класса Airplain";

	void Use() {
		cout << "Я лечу" << endl;
	}

	~Airplain()
	{
		cout << "вызвался конструктор деструктор Airplain" << endl;

	}
};

class FlingGar: public Car, public Airplain { //синтаксис множественного наследования
private:

public:
	FlingGar()
	{
		cout << "вызвался конструктор класса FlingGar" << endl; // вызов конструкторов происходит по порядку прописанному при наследовании (Car -> Airplain -> FlingGar)
	}

	~FlingGar()
	{
		cout << "вызвался деструктор класса FlingGar" << endl; //вызов деструкторов происходит в обратном порядке создания (разрушаются FlingGar->Airplain->Car)  
	}

};

int main() {
	setlocale(LC_ALL, "RU");
	
	FlingGar FC;
	//FC.Use(); нельзя вызвать неоднозначный метод(если методы в базовах классах называются одинакого среда разработки скажет об этом)
	FC.Car::Use();  //синтаксис при неодназначном методе
	cout << endl << endl;
	/*cout << FC.str2;
	FC.Fly();
	FC.Drive();*/

	/*Car* ptrC = &FC;
	Airplain* ptrA = &FC;*/

	return 0;
}
