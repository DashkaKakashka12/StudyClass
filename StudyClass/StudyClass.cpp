#include <iostream>
#include <string>
#include <vector>
#include <list>


using namespace std;

//префикс и постфикс
//префиксный и постфиксный отличаются приоритетностью операций 

template<typename T>
void PrintList(const list<T>& lts) {
	for (auto i = lts.cbegin(); i != lts.cend(); ++i)
	{
		cout << *i << endl;
	}


}

int main() {
	setlocale(LC_ALL, "RU");
	
	list<int> ::iterator it;

	it++; //f12 для просмотра прописанной разницы в их реализации


	++it;
	
	return 0;
}
