#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>
using namespace std;

//алгоритм -- набор функций для упрощения решения определённых задач
//поиск минимального элемента(min_element) -- работает для всех контейнеров. Напоминание vector -- динамический массив, list -- двухсвязный список
//параметрами передаём начало и конец контейнера

//minmax_element -- для получения и минимального и максимального элементов. возвращает пару

class Person
{
public:
    Person(string name, double score) {
        this->Score = score;
        this->Name = name;
    }

    string Name;
    double Score;

};


int main() {
    setlocale(LC_ALL, "RU");

    vector<Person> people{
        Person("Ваня", 150),
        Person("Катя", 130),
        Person("Сергей", 50),
        Person("Арина", 10),
        Person("Маша", 30),
        Person("Даша", 200)
    };

    vector<int> v = { 1,3,44,5,2,6,5,1 };
    // list<int> l = { 3,5,8,90,45,6,7 };
    //const int size = 7;
    //int arr[size] = { 3,5,8,90,45,6,7 };
    
   auto el = minmax_element(v.begin(), v.end());

   cout << *el.first << "\t" << *el.second << endl; //first -- минимальный, second -- максимальный


    
   

    return 0;
}