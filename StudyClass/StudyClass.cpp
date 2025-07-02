#include <iostream>
#include <string>

using namespace std;

__interface IBicycle{ //интерфейс по факту это абстрактный класс с виртуальным методами. можно использовать ключевое слово, а так же просто class. У интерфейса только public секция
public: // Если не указывать модификатор доступа для метода в интерфейсе, он автоматически считается публичны 
	void virtual EwistTheWell() = 0; //крутить руль
	void virtual Ride() = 0; //ехать

};

class Human {
private:
public:
	void RideOn(IBicycle& bicycle) {
		cout << "крутим руль" << endl;
		bicycle.EwistTheWell();		//вызываем метод через ссылку на объект интерфейса
		cout << "Поехали!" << endl;
		bicycle.Ride();

	}
};

class SympleBicycle: public IBicycle {
private:

public:
	void EwistTheWell() override {  //реализовываем интерфейс
		cout << "Метод EwistTheWell у SympleBicycle " << endl;
	} 

	void Ride() override {
		cout << "Метод Ride у SympleBicycle " << endl;
	} 
};


class SportBicycle: public IBicycle {
private:

public:
	void EwistTheWell() override { 
		cout << "Метод EwistTheWell у SportBicycle " << endl;
	}

	void Ride() override {
		cout << "Метод Ride у SportBicycle " << endl;
	}
};

int main() {
	setlocale(LC_ALL, "RU");
	Human h;
	SympleBicycle sb;
	SportBicycle sportB;
	h.RideOn(sportB);



	return 0;
}
