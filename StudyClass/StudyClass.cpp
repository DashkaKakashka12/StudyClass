#include <iostream>
#include <string>
#include <vector>
#include <list>


using namespace std;

//foreach перебор контейнеров 
//for_each	//как алгоритм + подключить библиотеку


template<typename T>
void PrintList(const list<T>& lts) {
	for (auto i = lts.cbegin(); i != lts.cend(); ++i)
	{
		cout << *i << endl;
	}
}

int main() {
	setlocale(LC_ALL, "RU");
	
	//int arr[] = { 1,2,3,4,5};
	list<int> list = { 1,2,3,4,5,6 };

	for (auto element : list) //	for each (auto var in arr) -- не работает
	{
		//данные передаются по значению поэтому при изменении element в коллекции ничего не меняется
		//(const auto &element : arr)
		cout << element << endl;
	}
	


	return 0;
}
