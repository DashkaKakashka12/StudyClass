#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

//алгоритм -- набор функций для упрощения решения определённых задач
//remove -- не удаляет, а перемещает все элементы указанные 3 параметром в конец вектора. нужно использовать erase
//remove_if -- не удаляет, а перемещает все элементы по условию предикаты(передаётся третьим параметром)

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

    // vector<int> v = {1,2,5,77,89,6,7,6};
    //auto result =  remove(v.begin(), v.end(), 6); //result указывает на первый ненужный элемент
    //v.erase(result, v.end()); //окончательно удаление элементов. result граница нужных эл-тов, end граница всех эл-тов

   auto result = remove_if(people.begin(), people.end(), [](const Person& p) {return p.Score < 50; });
   people.erase(result, people.end());

   sort(people.begin(), people.end(), [](const Person& p1, const Person& p2) {return p1.Score > p2.Score; });

    cout << "Количество элементов: " << people.size() << endl;

    for (auto el : people) {
        cout << el.Name << "\t" << el.Score << endl;
    }

    
   

    return 0;
}