#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std; //позволяет не прописывать str:: на каждой строке. такое работает со всеми пространствами
						//нельзя использовать если есть несколько функций с одинаковыми именами.


//используется два разработчика назвали функции одиноковыми именами

namespace firstNS {
	void Foo() {
		cout << "Функция из firstNS" << endl;
	}
}

namespace SecondNS {
	void Foo() {
		cout << "Функция из SecondNS" << endl;
	}
}

//namespace SecondNS {
//	void Foo() {
//		cout << "Функция из SecondNS" << endl;
//	}
//} для компилятора два одинаковых пространства имён с одинаковой реализацией рано одному пространству имён с дублированием реализации
// если  такое всё же произошло, то второе пространство имён можно поместить в новое. объявление thindNS::SecondNS::Foo();

int main() {
	setlocale(LC_ALL, "RU");


	SecondNS::Foo();


	return 0;
}
