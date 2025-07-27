#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <forward_list>


using namespace std;

//forward_list -- реализация односвязного списка




int main() {
	setlocale(LC_ALL, "RU");
	
	forward_list<int> fl = {3, 4, 5};
	//fl.push_front(4);

	forward_list<int>::iterator it = fl.before_begin(); 

	//fl.before_begin() как вставляет элемент в начало. можно просто push front
	


	//fl.erase_after(it); //удаляет СЛЕДУЮЩИЙ за указанным элемент
	//fl.insert_after(it, 9999); //вставить элемент перед каким-то
	//it--; не хранят элементы адрес предыдущего, только следующего, поэтому декремента нет
	//cout << *it << endl;

	for (auto el : fl) {
		cout << el << endl;
	}

	//size -- размерность
	//clear --очистить
	//insert -- вставить элемент
	//erase --  
	//pop -- удалить
	//push -- добавить
	//front -начало(вершина)
	//back -- конец
	//assign(5,1) --заполняет лист 5 элементами. все значение равны 1

	


	return 0;
}
