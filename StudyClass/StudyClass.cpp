#include <iostream>
#include <functional>
#include <vector>


using namespace std;

//Лямбда выражения (анонимные функции) -- [](){}
//пространство вокруг лямбда функции это контекст. внутри тела лямбды нельзя ссылаться на контекст, надо передавать в [] ссылку на контекст
//возврат значений из лямбды через auto
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

void DoWork(vector<int>& vc, function<void(int)> f) { //function<void(int,int)> f
	//vector<function<void(int)>> fvc -- вектор из всех функций с соответствующей сигнатурой
	for (auto el : vc) {
		f(el);
	}

}

int main() {
	setlocale(LC_ALL, "RU");

	int p = 0;
	auto f = [&p]() {
		p = 9;
	}; 
	f();

	/*vector<int> vc = { 1,2,30,45,67,8,54,99,122,57,23 };
	DoWork(vc, [](int a) {
		if (a % 2 == 0) {
			cout << "Лямбда: ";
			cout << a << endl;
		}
	});*/


	 //f = [](int a) {
		//cout << "Вызвана анонимная функция с параметром " << a << endl;
		//}; //всю анонимную передаём параметром в Dowork вместо присваивания. тоесть можно function<void(int)> f, f = анонимная функцию. или сразу


	return 0;
}