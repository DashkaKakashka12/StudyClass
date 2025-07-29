#include <iostream>
#include <string>
#include <thread>
#include <chrono>




using namespace std;

void doWork() {
	for (size_t i = 0; i < 10; i++)
	{
		cout << "ID: " << this_thread::get_id() << "\tdoWork\t" << i<<endl;
		this_thread::sleep_for(chrono::milliseconds(1000)); //делает паузу благодаря библиотеке chrono в 1 сек
	}
}


int main() {
	setlocale(LC_ALL, "RU");

	thread th(doWork); //создание нового потока. параметром передаём то что будет выполняться в другом потоке
	//th.detach(); //поток закроется не дожидаясь замершения работы метода dowork


	for (size_t i = 0; i < 10; i++)
	{
		cout << "ID: " << this_thread::get_id() << "\tmain\t"<<i << endl;
		this_thread::sleep_for(chrono::milliseconds(500)); //делает паузу благодаря библиотеке chrono в 1 сек
	}


	th.join(); //надо вызывать в самом конце

	return 0;
}
