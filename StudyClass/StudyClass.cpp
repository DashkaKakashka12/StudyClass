#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <memory>

using namespace std;

template<typename T>
class SmartPointer {
public:
	SmartPointer(T* a) {
		this->a = a;
		cout << "Constructor" << endl;
	}

	T& operator *() {//возвращаем значение по ссылке чтобы далее могли изменять его, а не создавать копию

		return *a;
	}

	~SmartPointer(){
		delete a; //удаляет весь объект и выделенную под него память тоже
		cout << "Destructor" << endl;

	}

private:
	T *a;
};


int main() {
	setlocale(LC_ALL, "RU");
	srand(time(NULL));

	/*SmartPointer<int> a1 = new int(5);  
	SmartPointer<int> a2 = a1;*/

	/*auto_ptr<int> ap1(new int(5)); 
	auto_ptr<int> ap2(ap1);*/ //указатель ap1 затирается и доступ остаётся только у ap2


	//unique_ptr <int> ap1(new int(5)); 
	//unique_ptr <int> ap2; //нельзя чтобы оба указателя ссылались на одну облась памяти
	//ap2 = move(ap1); //p2.swap(p1) анфлог. передаём значение из ap1 в ap2, адрес ap1 не затирается(неопределённое состояние) 
	//reset(затирает адрес и значение) release(затирает только значение)


	/*shared_ptr <int> ap1(new int(5)); 
	shared_ptr <int> ap2(ap1);*/ // оба указетеля могут цказывать на оду и туже облать памяти
	//все данные будут уничтожены когда уничтожится последний указатель

	int size = 0;
	cout << "Введите размер массива " << endl;
	cin >> size;
	shared_ptr <int[]> ap1(new int[size]);

	cout << "Массив: " << endl;

	for (int i = 0; i < size; i++)
	{
		ap1[i] = rand() % 20;
		cout << ap1[i] << endl;
	}

	return 0;
}
