#include <iostream>
#include <algorithm>

using namespace std;

//алгоритм for_each -- функция для перебора коллекции и получения доступ к каждому элементу
//третий параметр функция или лямбда. если лямбда то можно не прописывать элементарные функции
//и алгоритм и цифк принимают параметры по значению, если надо по ссылке, то в указываем по ссылке

//разницы в результате работы для вывода между циклом и алгоритмом нет

void Foo(int a) {
   
    cout << a << endl;
}


int main() {
    setlocale(LC_ALL, "RU");

    int arr[] = {1,2,7,4,};
  
    for_each(begin(arr), end(arr), [](int a) {
        cout << a << endl;});

    /*for (auto el : arr) {
        Foo(el);
    }*/

    return 0;
}