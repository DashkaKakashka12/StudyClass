#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include "SimpleTimer.h"


using namespace std;

//mutex -- защита разделяемх данных -- пример со студентами и яишницей -- какой-то сигнал что ресурс занят другим потоком и его нельзя использовать
//синхронизация потоков -- позволяет разделять выполнение потоков(дожидться выполнени одного перед выполнением другого)
// m.lock и unlock окружают код который не может выполняться параллельно. код выполняется дольше т.к остальные потоки ожидают


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
        cout << "DoWork2 значение параметра: "<< a << endl;
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
    m.lock();
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
    m.unlock();
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

/* for (int i = 0; i < 5; i++)
    {

        if (i == 0 || i == 4) {
            for (int i = 0; i < 10; i++)
            {
                cout << ch;
                this_thread::sleep_for(chrono::milliseconds(20));
            }
            cout << endl;
        }
        else {
            for (int i = 0; i < 2; i++)
            {
                cout << ch;
                for (int i = 0; i < 8; i++)
                {
                    cout << " ";
                    this_thread::sleep_for(chrono::milliseconds(20));
                }
            }
            cout << endl;
        }
        
    }*/