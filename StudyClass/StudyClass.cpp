#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

//алгоритм -- набор функций для упрощения решения определённых задач

// copy -- копирование элементов из одной коллекции в другую
// третьим параметром передаётся back_inserter -- помещение всех элементов в другую коллекцию

//copy_if -- позволяет копировать элементы по определённому условию. четвёртым параметром принимает предикат

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
    
    vector<Person> result;

    //copy(people.begin(), people.end(), back_inserter(result));

    copy_if(people.begin(), people.end(), back_inserter(result), [](const Person&p) {
        return p.Score >= 150;
        });

    sort(result.begin(), result.end(), [](const Person& p, const Person& p2) {
        return p.Score>p2.Score;
        });

    cout << "всего элементов " << result.size() << endl;

    for (auto el : result) {
        cout << el.Name << "\t"<< el.Score << endl;
    }

    return 0;
}