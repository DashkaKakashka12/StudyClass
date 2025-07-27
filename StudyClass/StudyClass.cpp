#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <forward_list>
#include <array>
#include <deque>


using namespace std;

//deque -- сокращение double and q -- двухсторонняя очередь
//в отличии от вектора есть push back/front, a, перегруженные []
//дек это лист(двухсвязный списов) из векторов(динамический массив)
//работает быстрее чем списки, но медленнее чем векторы

int main() {
	setlocale(LC_ALL, "RU");
	
	deque<int> dq = { 1,3,5 };
	//методы всё те же
	deque<int>::iterator it; //может использоваться для двухстороннего обхода 


	return 0;
}
