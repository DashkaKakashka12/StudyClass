#include <iostream>
#include <string>
#include <vector>
#include <list>


using namespace std;

//list -- реализация двухсвязных списков
//в листе не реализованы []. и нет доступа к индексу через итерации. только с начала или с конца по каждому элементу


//разница между постфиксным и префиксным. когда постфиксное мы создаём ещё один объект. допустим i++ где i = 5. мы вернём 5, но при этом i станет равно 6. префиксно мы сразу просто изменяем значение и возвращаем его
//в итераторах это не влияет на логику работы, лишь на скорость. при ++i не нужно создавать ещё один объект


template<typename T>
void PrintList(const list<T>& lts) {
	for (auto i = lts.cbegin(); i != lts.cend(); ++i)
	{
		cout << *i << endl;
	}


}

int main() {
	setlocale(LC_ALL, "RU");
	
	list<int> mylist = { 99,1,2,3,99,4,5,6 };
	//mylist.push_back(111);
	//mylist.push_front(222);
	//mylist.pop_back();
	//mylist.pop_front();

	PrintList(mylist);
	cout << "количество элементов: " << mylist.size() << endl;

	cout << endl << endl;

	mylist.assign(5,1);	//заполняет лист 5 элементами. все значение равны 1

	auto it = mylist.begin();
	advance(it, 5); 
	//mylist.insert(it, 0); 		//вставлюет элемент. не удаляет предыдущий а смещает их
	//mylist.erase(it);		//удаляет элемент


	//mylist.clear();		//очистка всего листа
	//mylist.reverse();	//меняет порядок элементов от последнего к первому
	//mylist.unique();	//удаление дубликатов(но только тех которые идут последоватьльно)
	//mylist.remove(99); //удаляет все элеенты равные переданному значению

	
	PrintList(mylist);
	cout << "количество элементов: " << mylist.size() << endl;


	
	

	


	//mylist.sort(); //сортируем от меньшего элемента к большему



	
	return 0;
}
