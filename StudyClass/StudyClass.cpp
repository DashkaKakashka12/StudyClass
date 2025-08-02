#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//предикаты -- функтор(объект класса который используется как функция) который возвращает булевое значение
//по факту предикат это просто функция возвращающая bool. если в классе то это булевый функтор

//count_if(v.begin(), v.end(), Null) -- алгоритм используется для получения количества элементов по условию, объявленному в предикате
//видос 147 пример предиката как функтора в классе


bool MinNull(int a) {
    return a > 0;
}

bool MoreNull(int a) {
    return a < 0;
}


int main() {
    setlocale(LC_ALL, "RU");

    vector<int> v = { -1, -4, 8, 9, 89, 2 };
   
    auto count = count_if(v.begin(), v.end(), MoreNull); //count_if алгоритм библиотеки algorithm для подсчёта кол-ва элементов stl коллекции
    cout << count << endl;

    return 0;
}