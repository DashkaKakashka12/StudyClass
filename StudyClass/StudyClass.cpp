#include <iostream>
#include <list>
#include <thread>
#include <chrono>




using namespace std;

//передача параметров в поток


void doWork(int a, int b) {

	this_thread::sleep_for(chrono::milliseconds(3000));
	cout << "----------DoWork START" << endl;
	this_thread::sleep_for(chrono::milliseconds(2000));
	cout << "a+b: " << a + b << endl;
	this_thread::sleep_for(chrono::milliseconds(3000));
	cout << "----------DoWork STOR" << endl;
}


int main() {
	setlocale(LC_ALL, "RU");

	
	//doWork(2, 3);
	thread th(doWork, 2, 3);//параметры передаются через запятую вместе с ссылкой на функцию
	
	for (size_t i = 0; true; i++)
	{
		cout << "ID: " << this_thread::get_id() << "\tmain\t" << i << endl;
		this_thread::sleep_for(chrono::milliseconds(500)); //делает паузу благодаря библиотеке chrono в 1 сек
	}

	th.join();

	return 0;
}
