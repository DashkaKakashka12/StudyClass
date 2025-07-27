#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <forward_list>
#include <array>


using namespace std;

//array -- отличие от вектора в том что это обёртка для статического массива

int main() {
	setlocale(LC_ALL, "RU");
	
	array<int, 4> arr = {2, 3, 4, 5}; //обязательно вторым параметром указатькол-во эл-тов
	
	cout << arr.back() << endl;


	//arr.at(0) -- проверяет выход за границы размера
	//arr.fill(2); //заполняет все элементы одним значением
	//arr.back() -- вывод последнего эл-та
	//arr.front() --вывод первого эл-та
	//arr.size -- узнать размер


	return 0;
}
