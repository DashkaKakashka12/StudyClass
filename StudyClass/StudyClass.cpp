#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include "SimpleTimer.h"


using namespace std;

//mutex, lock_quard -- класс, задача которго при создании объектазахватить mutex в конструкторе и освободить при удалении в деструкторе
//с помощью {} ограничивается облась видимости lock_quard. lock_quard захватывает в контект всё что после него по умолчанию

class MyClass
{
public:

    void DoWork() {
        this_thread::sleep_for(chrono::milliseconds(2000));
        cout << "---DoWork START---" << endl;
        this_thread::sleep_for(chrono::milliseconds(5000));
        cout << "---DoWork STOP---" << endl;
    }

    void DoWork2(int a) {
        this_thread::sleep_for(chrono::milliseconds(2000));
        cout << "---DoWork2 START---" << endl;
        this_thread::sleep_for(chrono::milliseconds(5000));
        cout << "DoWork2 значение параметра: " << a << endl;
        cout << "---DoWork2 STOP---" << endl;
    }

    int Sum(int a, int b) {

        this_thread::sleep_for(chrono::milliseconds(3000));
        cout << "---Sum START---" << endl;
        this_thread::sleep_for(chrono::milliseconds(7000));
        cout << "---Sum STOP---" << endl;

        return a + b;
    }


};

mutex m;

void Print(char ch) {
    {
        lock_guard<mutex> guard(m);
        for (int i = 0; i < 5; i++)
        {
            for (int i = 0; i < 10; i++)
            {
                cout << ch;
                this_thread::sleep_for(chrono::milliseconds(20));
            }
            cout << endl;
        }
        cout << endl;
    }
}

int main() {
    setlocale(LC_ALL, "RU");

    SimpleTimer t;
    thread first(Print, '*');
    thread second(Print, '#');

    first.join();
    second.join();

    //for (size_t i = 0; i <= 10; i++)
    //{
    //    cout << "ID: " << this_thread::get_id() << "\tmain\t" << i << endl;
    //    this_thread::sleep_for(chrono::milliseconds(500)); //делает паузу благодаря библиотеке chrono в 1 сек
    //}



    return 0;
}