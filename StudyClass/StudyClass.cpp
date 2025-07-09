#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include "StudyClass.h"

using namespace std; 



class Point {
public:
	Point() {
		 x = 0.0;
		 y = 0.0;
		 z = 0.0;
	}

	Point(double x, double y, double z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

private:
	double x;
	double y;
	double z;

};


template <class T1> //всегда обязательно неотрывно перед классом. вместо typename можно писать class. функционал не меняется
class TypeSize {
public:
	
	TypeSize(T1 a) { //принимаем параментром тип шаблона
		this->a = a;
	}
	
	void DataTypeSize() {
		cout << "Переменная T занимает " << sizeof(a) << " байта" << endl;
	}

protected:
	T1 a;
	
};


template<class T1>
class TypeInfo :public TypeSize<T1>{//обязатльно указывать тип который наследуется. Можно указать явно int например но он должен совпадать

public:
	TypeInfo(T1 a): TypeSize<T1>(a) {   //так как конструктора по умолчанию у TypeSize нет 

	}

	void ShowTipeName() {
		cout << "Переменная типа " << typeid(this->a).name() << endl;//для передачи поля базового класса меняем модификатор доступа. #include "typeinfo"
						//обязательно указывать this потому что на этапе компиляции TypeInfo компилятор ещё не знает что такое поле есть в TypeSize 
	}
};


int main() {
	setlocale(LC_ALL, "RU");

	
	int c = 0; // обязательно надо инициализировать int.	ПОЧЕМУ??

	TypeInfo <int>ob(c);//нельзя просто создать объект класса. Обязательно указываем тип данных с которым работаем 
	ob.DataTypeSize();
	ob.ShowTipeName();

	return 0;
}
