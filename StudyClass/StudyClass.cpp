#include <iostream>
#include <string>
#include <vector>
#include <list>


using namespace std;

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
	
	int a = 5;
	cout << ++a << endl;
	
	return 0;
}
