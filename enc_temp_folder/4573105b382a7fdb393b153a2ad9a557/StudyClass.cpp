#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include "StudyClass.h"

using namespace std;

template<typename T>
class SmartPointer {
public:
	SmartPointer(T* a) {
		this->a = a;
		cout << "Constructor" << endl;
	}

	T& operator *() {

		return *a;
	}
	//DoPoint() {
	////	T* p = new T;
	//}

	~SmartPointer(){
		delete a; //просто удаляет вксь объект и выделенную под него память тоже
		cout << "Destructor" << endl;

	}

private:
	T *a;
};


int main() {
	setlocale(LC_ALL, "RU");

	SmartPointer<int> a = new int(5); //не нужно очищать память. очищается с деструктором. 
	//int* b = new int(3);
	*a = 1234;

	cout << *a << endl;


	return 0;
}
