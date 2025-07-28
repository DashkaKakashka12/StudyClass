#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <forward_list>
#include <array>
#include <deque>
#include <set>


using namespace std;

//set, multiset -- ассоциативные контейнеры на основе бинарного дерева

//set нет методов [], push pop. При выводе ка кбы сортирует из от большего к меньшему(упорядоченно)
//set не может хранить два одинаковых элемента, только уникальные значения
//set не может изменять значение так как оно оперделяет позоцию его нахождения

//multiset может хранить несколько одинаковых эл-тов в коллекции, в библиотеке set




//typedef -- возможность давать псевдоним типам данных



int main() {
	setlocale(LC_ALL, "RU");
	
	multiset<int> m = {1,1,1,2,4,5,3};

	//find для поиска элемента. возвращает итерор на этот элемент если он найден 	auto it = s.find(10);
	//erase для удаления, insert для удаления. они возвращают результат своей работы(отслеживается итератором)


	//для multiet:
	// auto it = m.lower_bound(1);// --вернёт первую единицу которую найдёт
	//upper_bound(1);// --вернёт следующий элемент после последней единицы(из отсортированного списка)
	//auto a = m.equal_range(1); //возвращает диапазон чисел от lower_bound до upper_bound
	
	for (auto el : m) {
		cout << el << endl;
	}



	//typedef std::vector<int> int_vector -- как пространство имён
	//тогда в main int_vector vector1 вместо объявления


	return 0;
}
