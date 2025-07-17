#include <iostream>
#include <string>
#include <vector>


using namespace std;

//итораторы == оболочка под умные указатели. используются для получения и изменения данных в динамических структурах
//в разных дс разная реализация инераторов

//в векторе есть и перегрузка[] и итераторы 


int main() {
	setlocale(LC_ALL, "RU");
	
	
	vector<int> MyVector = {5, 6, 7, 8};

	auto it = MyVector.begin();	 // begin возвращает данные нужного типа(vector тут). it предоставляет доступ к первому элементу vector
	//*it = 1000; //можно заменить элемнет любой ячейки используя арифметику указателей
	//it += 2; для передвижания по коллекции
	//cout << *it << endl;
	//advance(it, 2); //использыется для передвижания если нельзя через арифметику указателей

	for (vector<int>::iterator i = MyVector.begin(); i != MyVector.end(); i++)
	{
		cout << *i << endl;
	}
	//end() указывает на следующий элемент после последнего(в никуда). const_iterator не позволяет менять значение
	//для const_iterator работают и обычные begin, end по цепочке наследования. но можно cbegin, cend.
	//reverse_iterator для перебора с конца. обязательно rbegin, rend. итераторы для хода назад. rend указывает на следующий за первым элементов. rbegin на последний эленет

	cout << endl << endl;




	//МЕТОДЫ КОТОРЫЕ РАБОТАЮТ ТОЛЬКО С ИТЕРАТОРАМИ

	advance(it, 3);
	MyVector.insert(it, 1000);				//добавить элемент по какому-то индексу. если индекс не указывать то поставит на begin. advance для указания индекса
	//удалить элемент по какому-то индексу


	for (vector<int>::iterator i = MyVector.begin(); i != MyVector.end(); i++)
	{
		cout << *i << endl;
	}


	cout << endl << endl;

	vector<int>::iterator itEr = MyVector.begin();
	//advance(itEr, 3);
	MyVector.erase(itEr); //тот элемент на который указывает итератор будет удалён из коллекции. itEr +3 удаляет диапазон


	for (vector<int>::iterator i = MyVector.begin(); i != MyVector.end(); i++)
	{
		cout << *i << endl;
	}
	


	/* Пример арифметики указателей на массиве
	int arr[] = {1,2,3,};
	cout << arr[1] << endl;
	cout << *(arr + 1) << endl;*/ //адресс массива +1 элемент и разыменовать == второй элемент



	//auto

	//vector<int>::iterator it = MyVector.begin()	= 	auto it = MyVector.begin();


	
	return 0;
}
