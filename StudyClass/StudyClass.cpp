#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>
#include <numeric>
using namespace std;


//equal -- возвращает логическое значение. 4 параметра: начало и конец обоих коллекций. сравнивает по индексам, если необходимо по значениям юз sort
//mismath -- помимо проверки на неравенство возвращает пару элементов, первое несоответствие в коллекциях

//можно сравнивать разные контейнеры

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

    vector<int> v = { 3,3,2 };
    int arr[] = {3,3,2};
    int arr2[] = {3,1,2,4,4};

    //bool result = equal(begin(v), end(v), begin(arr), end(arr));

    auto result = mismatch(begin(v), end(v), begin(arr), end(arr)); //
    if (result.first == end(v) && result.second == end(arr)) {
        cout << "+" << endl;
    
    } else cout << "-" << endl;

    
    return 0;
}