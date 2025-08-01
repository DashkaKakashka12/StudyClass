#include <iostream>
#include <functional>
#include <vector>


using namespace std;

//function -- обёртка для функции, метода класса. как указатель на функцию
//function<void(int)> f -- сначала указываем тип возвращаемого значения, затем типы параметров. через запятую если несколько


void Foo(int a) {
	if (a > 10 && a < 40) {
		cout << "Foo: ";
		cout << a << endl;
	}
}


void Bar(int a) {
	if (a % 2 == 0) {
		cout << "Bar: ";
		cout << a << endl;
	}
}

void DoWork(vector<int>& vc, vector<function<void(int)>> fvc) { //function<void(int,int)> f
	//vector<function<void(int)>> fvc -- вектор из всех функций с соответствующей сигнатурой
	for (auto el : vc) {
		for (auto& fel : fvc) {
			fel(el);
		}
	}

}

int main() {
	setlocale(LC_ALL, "RU");

	vector<int> vc = { 1,2,30,45,67,8,54,99,122,57,23 };

	vector<function<void(int)>> fvc; //вектор для функций

	fvc.emplace_back(Foo);
	fvc.emplace_back(Bar);


	DoWork(vc, fvc);

	return 0;
}