#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include "SimpleTimer.h"


using namespace std;

//deadlock -- взаимная блокировка. 
//если оба потока пытаются вызвать одну и туже функцию вместе, то обе ожидают её выполнения( из-зи mutex и задержки), ничего не работает
//надо поменять порядок мьютексов чтобы он был одинаковым и тогда оба потока будут получать доступ к функции только если она свободна 

mutex m1;
mutex m2;


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

void Print() {

    m1.lock();   
    this_thread::sleep_for(chrono::milliseconds(1));
    m2.lock();

    for (int i = 0; i < 5; i++)
        {
            for (int i = 0; i < 10; i++)
            {
                cout << "*";
                this_thread::sleep_for(chrono::milliseconds(10));
            }
            cout << endl;
        }
       cout << endl;

       m2.unlock();
       m1.unlock();
}


void Print2 (){
    

   m1.lock();
   this_thread::sleep_for(chrono::milliseconds(1));
   m2.lock();

   for (int i = 0; i < 5; i++)
   {
       for (int i = 0; i < 10; i++)
       {
            cout << "#";
            this_thread::sleep_for(chrono::milliseconds(20));
       }
        cout << endl;
   }
   cout << endl;

   m2.unlock();
   m1.unlock();
}

int main() {
    setlocale(LC_ALL, "RU");

    SimpleTimer t;

    thread first(Print);
    thread second(Print2);

    first.join();
    second.join();

    //for (size_t i = 0; i <= 10; i++)
    //{
    //    cout << "ID: " << this_thread::get_id() << "\tmain\t" << i << endl;
    //    this_thread::sleep_for(chrono::milliseconds(500)); //делает паузу благодаря библиотеке chrono в 1 сек
    //}



    return 0;
}