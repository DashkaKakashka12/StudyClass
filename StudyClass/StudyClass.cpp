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
	void pop_front();
	void clear();
	void push_front(T data);
	void insert(T data, int index);
	void removeAt(int index);

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
	clear();
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
void List<T>::pop_front()
{
	Node<T> *temp = head; //обязательно указатель!!!!!
	head = head->pNext;
	delete temp;
	size--;
}

template<typename T>
void List<T>::clear()
{
	while (size) {
		pop_front();
	}

}

template<typename T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	/*Node<T>* current = this->head;
	head = new Node<T>(data);
	head->pNext = current; */
	size++;

}

template<typename T>
void List<T>::insert(T data, int index)
{

	if (index == 0) {
		push_front(data);
	}
	else {

		Node<T>* previous = this->head; //положили первый элемент
		for (int i = 0; i < index - 1; i++) //итерируемся до элемента предшествующего нужному
		{
			previous = previous->pNext; //в наш первый добавляем индекс последующего элемента
		}

		Node<T>* newNode = new Node<T>(data, previous->pNext);
		previous->pNext = newNode;

		size++;
	}


	
}

template<typename T>
void List<T>::removeAt(int index)
{
	if (index == 0) {
		pop_front();
	}
	else {
		Node<T>* previuos = this->head;

		for (int i = 0; i < index - 1; i++) {
			previuos = previuos->pNext;
		}

		Node<T>* toDelete = previuos->pNext;
		previuos->pNext = toDelete->pNext; //я вообще не понимаю как это работает
		delete toDelete;
		size--;

	}

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
	
	lst.push_front(1);
	lst.push_front(2);
	lst.push_front(3);
	lst.push_front(4);

	for (int i = 0; i < lst.getSize(); i++) {
		cout << lst[i] << endl;
	}
	cout << "Количество элементов: " << lst.getSize() << endl;

	lst.insert(55, 2);

	for (int i = 0; i < lst.getSize(); i++) {
		cout << lst[i] << endl;
	}
	cout << "Количество элементов: " << lst.getSize() << endl;


	lst.removeAt(1);

	for (int i = 0; i < lst.getSize(); i++) {
		cout << lst[i] << endl;
	}
	
	return 0;
}
