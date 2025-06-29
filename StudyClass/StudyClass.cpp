#include <iostream>
#include <string>

using namespace std;

class Weapon {	//класс в котором присутствует чисто виртуальная функция (пустая) называется абстрактным
public:
	virtual void Shoot() = 0; 	//экземпляры абстрактного класса компилятор не позволяет создавать
	void Foo() {
		cout << "Foo" << endl; //но если в классе есть не только абстрактный метод, то объекты наследники могут его вызвать
	}						
};

class Gun: public Weapon {
private:

public:		
	void Shoot() override { //благодаря virtual в наследниках можем переопределить работу метода
		cout << "Бам!!!" << endl;
	}
};

class SubmachineGun: public Gun {
public:
	void Shoot() override { //компилятор контролирует соответствие сигнатуры переопределяемого метода методу родителя
		cout << "Бам! Бам! Бам!" << endl;
	}
};

class Bazooka: public Weapon {
public:
	void Shoot() override { 
		cout << "Барабам" << endl;
	}
};

class Knife :public Weapon {
public:
	void Shoot() override {
		cout << "хряк" << endl;
	}
};

class Player {
public:
	void Shoot(Weapon* weapon) {
		weapon->Shoot();
	}
};

class A {
public:
	A() {
		//cout << "Выделена динамическая память класса A" << endl;
	}

	virtual ~A() = 0; //класс в котором объявлен чисто виртуальный деструктор становиться абьстрактным
		//cout <<"Освобождена динамическая память класса A" << endl;
	
};

A::~A() {}; //чтобы компилятор не ругался ибо он дурак

class B: public A {
public:
	B() {
		//cout << "Выделена динамическая память класса B" << endl;
	}

	~B() override {
		//cout << "Освобождена динамическая память класса B" << endl;
	}
};


int main() {
	setlocale(LC_ALL, "RU");

	/*A *bptr = new B;
	delete bptr;*/


	//Gun gun;
	//SubmachineGun  machineGun;
	
	//Gun* weapon = &gun; //указатель бюазового класса может указывать на обьект наследника
	//weapon->Shoot();
	

	//Player player;
	////Bazooka bazooka;
	//Knife knife;
	//player.Shoot(&knife); //полиморфизм -- возможность использования одного и того же метода(Shoot) разными классами с разной реализацией(переопределение)
	//knife.Foo();


	return 0;
}
