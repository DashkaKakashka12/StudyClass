#include <iostream>
#include <string>

using namespace std;

class Human {
private:
	string name = "Маша";
public:
	string GetName() {
		return name;
	}

	void SetName(string name) {
		this->name = name;
	}
};

class Student: public Human {
public:
	string group;

	void Learn() {
		cout << "Я учусь" << endl;
	}

};

class ZaoStudent: public Student {
public:
	void Learn() {
		cout << "Я бываю в унике 1 в год" << endl;
	}
};

class Professor: public Human {
public:
	string subject;

};

class A {
private:
	string msg;
public:

	A() {
		msg = "пустое сообщение";

	}

	A(string msg) {
		this->msg = msg;

	}

	void Print() {
		cout << msg << endl;
	}

//	string msg1 = "Сообщение 1";//можем обратиться везде, даже от объектов
//private:
//	string msg2 = "Сообщение 2"; //недоступны вне самого класса даже наследникам
//protected:
//	string msg3 = "Сообщение 3"; //доступны наследникам и самому классу, но не объектам
};

class B: public A { //public модификатор не меняетмодификаторов родителя. private-> все поля приватными. protected  public->protected 
private:
	string k;
public:

	B(string k): A(k) {
		
	}

};

//class C: public B{ //класс выхывает кострукторы всех от прабабушки родителей, а потом свой. A->B->C
//public:			//С деструкторами наоборот. сначала уничножаются дочерний, потом родительские С->B->A
//	C() {
//		cout << "Вызвался конструктор класса C" << endl;
//	}
//
//	~C() {
//		cout << "Вызвался деструктор класса C" << endl;
//	}
//};


int main() {
	setlocale(LC_ALL, "RU");

	A a("dsvf");
	a.Print();

	B b("haha");
	b.Print();


	/*B b;
	b.PrintMsg();*/

	/*Student st;
	st.Learn();

	ZaoStudent zaoSt;
	zaoSt.Learn();

	cout << st.GetName() << endl;
	st.SetName("Саша");
	cout<< st.GetName() << endl;
	cout << "----" << endl;
	cout<< zaoSt.GetName() << endl;*/


	return 0;
}
