#include <iostream>
using namespace std;

//функторы -- функциональные объекты. объекты класса у которых перегружен оператор (), из-за чего может вести себя как функция
//может использоваться для подсчёта count.

class MyFunctor {
public:
    int operator() (int a, int b) 
    { //operstor() -- вместо названия объекта, так как он может принимать парамтры
        cout << "я функтор " <<endl;
        return a+b;
    }

private:
    int count = 0;
};



int main() {
    setlocale(LC_ALL, "RU");
    MyFunctor f;
    int result = f(2, 2);
    cout <<result;


    return 0;
}