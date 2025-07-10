#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include "StudyClass.h"

using namespace std;

template<typename T>

class Printer {
public:
	void Print(T a) {
		cout << a << endl;
	}
private:

};

template<> //создаём специализацию 
class Printer<string> { //указываем в <> тип для которого хотим сделать специализацию. когда укажем такой тип создадим новый класс
public:
	void Print(string a) { //как бы переопределяем метод под нужный тип
		cout << "--- " << a << " ---" << endl;
	}

};

int main() {
	setlocale(LC_ALL, "RU");

	Printer<string> a;
	a.Print("привет");

	return 0;
}
