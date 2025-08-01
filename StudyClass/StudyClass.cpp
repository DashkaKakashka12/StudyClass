#include <iostream>
#include <thread>
#include <chrono>


using namespace std;

//получение результата рабоыт из потока
//чтобы получить результат который возвращает функция надо объявить при создании потока лямбда функцию, переменная в которой получит результат работы первой функции 
//thread th([&res](){ res = Sum(2, 3); } );

int Sum(int a, int b) {

    this_thread::sleep_for(chrono::milliseconds(3000));
    cout << "---Sum START---" << endl;
    this_thread::sleep_for(chrono::milliseconds(7000));
    cout << "---Sum STOP---" << endl;

    return a + b;
}


int main() {
    setlocale(LC_ALL, "RU");

    int res;

    thread th([&res](){ res = Sum(2, 3); } );


    for (size_t i = 0; i<=10; i++)
    {
        cout << "ID: " << this_thread::get_id() << "\tmain\t" << i << endl;
        this_thread::sleep_for(chrono::milliseconds(500)); //делает паузу благодаря библиотеке chrono в 1 сек
    }

   th.join();
   cout <<"res: "<< res << endl;

    return 0;
}