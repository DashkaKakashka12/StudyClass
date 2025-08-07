#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include "SimpleTimer.h"


using namespace std;

//recursive_mutex -- для рекурсивной функции и если нужно несколько раз вызвать mutex. объявляется как обычный глобально.
//освобождать надо столько же раз сколько мы его вызвали.
//в рекурсии при повторном вызове функции вызывается один и тот же mutex, поэтому его нельзя использовать, нужно recursive_mutex

mutex m;
recursive_mutex rm;

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
   
    this_thread::sleep_for(chrono::milliseconds(1));
    

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

}

void Print2 (){
    
   this_thread::sleep_for(chrono::milliseconds(1));
  

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

}

void Foo(int a) {
    rm.lock();
    cout << a << " ";
    this_thread::sleep_for(chrono::milliseconds(300));
    if (a <= 1) {
        cout << endl;
        rm.unlock();
        return; //если a = 1, то дальше код не выполниться, поэтому надо и в цикле m.unlock()
    }
    a--;
    Foo(a);
    rm.unlock();
}


int main() {
    setlocale(LC_ALL, "RU");

    //SimpleTimer t;

    //Foo(10);
    //rm.lock();

    thread t1(Foo, 10);
    thread t2(Foo, 10);

    t1.join();
    t2.join();


    //for (size_t i = 0; i <= 10; i++)
    //{
    //    cout << "ID: " << this_thread::get_id() << "\tmain\t" << i << endl;
    //    this_thread::sleep_for(chrono::milliseconds(500)); //делает паузу благодаря библиотеке chrono в 1 сек
    //}



    return 0;
}