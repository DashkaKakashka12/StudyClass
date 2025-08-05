#include <iostream>
#include <thread>
#include <chrono>


using namespace std;

//


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




int main() {
    setlocale(LC_ALL, "RU");

    int result;
    MyClass m;

    //thread th([&]() {result = m.Sum(2, 3); }); //передача метода класса в поток(Sum и Dowork)
    //thread th([&]() {&MyClass::DoWork, m; }); //для Dowork так как не нужен возврат результата
    thread th(&MyClass::DoWork2, m, 5);

    for (size_t i = 0; i <= 10; i++)
    {
        cout << "ID: " << this_thread::get_id() << "\tmain\t" << i << endl;
        this_thread::sleep_for(chrono::milliseconds(500)); //делает паузу благодаря библиотеке chrono в 1 сек
    }

    th.join();
    //cout << "result: "<< result << endl;

    return 0;
}