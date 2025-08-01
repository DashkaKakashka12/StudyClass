#include <iostream>
#include <functional>
#include <vector>


using namespace std;

//захват переменных в контекст [] лямбда функций
//переменные в [] передаются через запятую,
//[=] - ситывание всего контекста до лямбды по значению
//[&] - ситывание всего контекста до лямбды по ссылке
//mutable ключевое слово при захвате по значению позваляет изменять переданные параметры, но только внутри лямбды(работать с копией) 
//[&a,b]() mutable -- с а работаем как с ссылкой, с b со значением


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

class MyClass
{
public:
	int a = 30;
	MyClass() {};
	~MyClass() {};

	void Msg() {
		cout << "msg" << endl;
	}

	void L() {
		auto f = [this]() { //позврляет использовать this внутри лямбды
			this->Msg();
		};
		f();
	};


};


int main() {
	setlocale(LC_ALL, "RU");

	MyClass m;
	m.L();

	int a = 55;
	int b = 10;

	auto f = [&a,b]() mutable{ //для указания типа возвращаемого значения помимо явного можно использовать f = [&a,b]()-> int
		cout << a << endl;
		a = 1;
		b = 1;
		cout << b << endl;
		return 0;
	};

	auto result = f();

	return 0;
}