#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include "StudyClass.h"

using namespace std;

class MyClass1 {
public:
	int a = 10;

};

class MyClass2 : public MyClass1 {


};

struct MyStruct1 { //у структуры по умолчанию все поля и методы, наследование с public, у класса всё с private.

	int a = 22;
};



struct MyStruct2: MyStruct1 {


};


int main() {
	setlocale(LC_ALL, "RU");

	MyStruct2 m;
	MyStruct1 l;


	return 0;
}
