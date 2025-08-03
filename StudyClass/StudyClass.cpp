#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

//алгоритм -- набор функций для упрощения решения определённых задач
// find -- поиск определённого элемента, третим значением передаётся искомое число
// find_if -- поиск элемента по условию с использованием предикат(передаётся третьим параметром) 
// find_if_not -- инверсирует возвращённое значение результата find_if

class Person
{
public:
    Person(string name, double score) {
        this->Name = name;
        this->Score = score;
    }

    string Name;
    double Score;

};


int main() {
    setlocale(LC_ALL, "RU");

    vector<Person> people{
        Person("Вася", 181),
        Person("Петя", 30),
        Person("Маша", 179),
        Person("Даша", 200),
        Person("Катя", 198),
        Person("Андрей", 181),
        Person("Сергей", 50),
        Person("Иван", 150),
    };
    
    vector<int> v = { 6,4,4,12,2,1 };

   // auto result = find(v.begin(), v.end(), 7); //просто ищет один элемент в коллекции
   
    auto result = find_if(people.begin(), people.end(), [](const Person &p){
        return p.Score == 50 && p.Name== "Сергеаай";
        });


    if (result == people.end()) {
        cout << "-" << endl;
    }
    else {
        cout << "+" << endl;
    }

    return 0;
}