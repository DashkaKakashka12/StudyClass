#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <forward_list>
#include <array>
#include <deque>
#include <set>
#include <map>


using namespace std;

//map, multimap -- структура бинарного дерева, хранит и ключ и значение, тоже упорядочиваются, но только по ключу
//map хранит только уникальные значенияю есть перегруженный [] для изменения значения


//multimap -- может хранить повторяющиеся значения, у multimap всё тоже самое что и у map. только может быть несколько одинаковых ключей. но не перегружен [], at


int main() {
	setlocale(LC_ALL, "RU");
	
	//pair<int, string> p(1, "phone");//шаблонная пара. первое ключ, второе значение.
	
	map<int, string> m;

	m.insert(make_pair(1, "notepad")); //для добавления элемента. пара создаётся и копируется в map 
	m.emplace(2, "phone"); // более краткий спооб добавления жлемента. пара сразу создаётсчя в map
	m.emplace(55, "tv");
	m.emplace(44, "condi");

	m.erase(2);

	cout << m[22] << endl;

	// auto it = m.find(2); // вывод значения. также можео и изменить значение. 
	//добавит элемент если его не было. нужно использовать at, тогда не добавит если элемента не было

	//у multimap всё тоже самое. только может быть несколько одинаковых ключей. но не перегружен [], at

	return 0;
}
