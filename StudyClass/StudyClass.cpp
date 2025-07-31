#include <iostream>
#include <thread>
#include <chrono>



using namespace std;

//возврат параметров из потока по ссылке с помощью std::ref(q)
//std::ref(q) --создание класса который позволяет работать с потоком который позволяет работать с реузльтатом как ссылкой

void DoWork(int &a) {

	this_thread::sleep_for(chrono::milliseconds(3000));
	cout << "ID: " << this_thread::get_id() << "----------DoWork START" << endl;
	this_thread::sleep_for(chrono::milliseconds(2000));

	a *= 2;
	
	cout << "ID: " << this_thread::get_id() << "----------DoWork STOR" << endl;
}


int main() {
	setlocale(LC_ALL, "RU");

	int q = 2;
	//DoWork(q);
	thread th(DoWork, std::ref(q));	//параметры передаются через запятую вместе с ссылкой на функцию

	for (size_t i = 0; i < 15; i++)
	{
		cout << "ID: " << this_thread::get_id() << "\tmain\t" << i << endl;
		this_thread::sleep_for(chrono::milliseconds(500)); //делает паузу благодаря библиотеке chrono в 1 сек
	}

	th.join(); //если использовать detach то есть верояятность что поток недовыполнится и тогда резульат вернётся неккоректным
	cout << "q = " << q << endl;


	return 0;
}