#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <memory>

using namespace std;

template<typename T>
class List {
public:
	List();
	~List();

	void push_back(T data);
	int getSize() { return size; }

	T& operator [](const int index);

private:
	template<typename T>
	class Node {
	public: //нет private потому что весь класс private в List
		Node* pNext; //указатель на следующий элемент типа следующего элемента
		T data;


		Node(T data = T(), Node* pNext = nullptr) {
			this->data = data;
			this->pNext = pNext;
		}


	};


	Node<T> *head; //указатель на первый элемент списка
	int size;

};


template<typename T>
List<T>::List() {
	size = 0;
	head = nullptr;
}

template<typename T>
List<T>::~List() {

}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr) {
		head = new Node<T>(data);
	}
	else {
		Node<T>* current = this->head;

		while (current->pNext !=nullptr) {
			current = current->pNext;
		}

		current->pNext = new Node<T>(data);

	}

	size++;
}

template<typename T>
T& List<T>::operator[](const int index)
{
	Node<T>* current = this->head;

	int count = 0;

	while (current != nullptr) { //идём пока адрес элемента следующего не равен нулю
		if (count == index) {  
			return current->data; // если количество равно принятому индексу возвращаем данные(тут значение)
		}

		current = current->pNext; // если количество не равно принятому индексу, заменяем объект следующим за ним по адресу и увеличиваем количество
		count++;
	}
}



int main() {
	setlocale(LC_ALL, "RU");
	
	List<int> lst;
	lst.push_back(5);
	lst.push_back(10);
	lst.push_back(40);

	cout << "Количество элементов в списке: "<< lst.getSize() << endl;

	for (int i = 0; i < lst.getSize(); i++)
	{
		cout << lst[i] << endl;
	}

	
	return 0;
}
