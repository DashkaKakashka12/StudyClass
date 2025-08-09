#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include "SimpleTimer.h"

using namespace std;

//вспомни lock_guard<mutex> lg(m) ограничивает доступ к функции если к ней уже обращён один поток
//unique_lock -- работает также как и lock_guard, но есть методы, которые позволяет ограничить часть кода без {}, а с unlock
//используется вместо lock_guard когда есть часть кода внутри которая может быть выполнена двумя и более потоками одновременно


mutex m;
void Print(char ch) {
    
        //lock_guard<mutex> lg(m);

        unique_lock<mutex> ul(m, defer_lock); //defer_lock не вызовет метод lock при создании. надо прописать самим там где нужно

        this_thread::sleep_for(chrono::milliseconds(2000));
        ul.lock();
        for (int i = 0; i < 5; i++)
        {
            for (int i = 0; i < 10; i++)
            {
                cout << ch;
                this_thread::sleep_for(chrono::milliseconds(10));
            }
            cout << endl;
        }
        cout << endl;
        ul.unlock();
        this_thread::sleep_for(chrono::milliseconds(2000));

}



int main() {
    setlocale(LC_ALL, "RU");

    SimpleTimer t;

    thread t1(Print, '*');
    thread t2(Print, '-');

    t1.join();
    t2.join();

    return 0;
}