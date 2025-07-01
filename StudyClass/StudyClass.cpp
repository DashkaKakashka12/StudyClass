#include <iostream>
#include <string>

using namespace std;


class Human {
private: 
	string name;
	int weight;
	int age;
public:
	Human(string name) {
		this->name = name;
		this->age = 0;
		this->weight = 0;
	}

	Human(string name, int age):Human(name) { //сначала отрабатывает Human(name), потом с двумя параметрами
		this->age = age;
	}

	Human(string name, int age, int weight):Human(name,age) { //помогает не дублироватьинициализацию, делегируем присваивание полей другим конструкторам
		this->weight = weight;
	}
};


class Msg{
private:
	string msg;
public:
	Msg(string msg) {
		this->msg = msg;
	}

	virtual string GetMsg() {
		return msg;
	}
};

class BracketsMsg : public Msg {
public:
	BracketsMsg(string msg) : Msg(msg) {

	}
	string GetMsg() override {
		return "{ " + Msg::GetMsg() + " }"; //без ::Msg:: вызывается GetMsg() у BracketsMsg(рекурсия надо явно указать что этот метод вызываем у базового класса)
	}
};

class Printer {
private:

public:
	void Print(Msg* msg) {
		cout << msg->GetMsg() << endl;
	}

};

int main() {
	setlocale(LC_ALL, "RU");

	BracketsMsg m("Привет");
	Printer p;
	p.Print(&m);
	

	return 0;
}
