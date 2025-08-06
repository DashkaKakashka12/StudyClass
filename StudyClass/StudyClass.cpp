#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>
#include <numeric>
using namespace std;


//equal -- возвращает логическое значение. 4 параметра: начало и конец обоих коллекций. сравнивает по индексам, если необходимо по значениям юз sort
//

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

class Point {
public:

    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    int x, y;
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

    vector<Point> arr { 
        Point(1,3),
        Point(4,5),
        Point(5,7),
    };

    vector<Point> arr2 {
        Point(1,3),
        Point(3,5),
        Point(5,7),
    };
   

    bool result = equal(begin(arr), end(arr), begin(arr2), end(arr2), [](const Point& p1, const Point& p2) {
        return p1.x == p2.x && p1.y == p2.y;}
    );

    cout << result << endl;


    return 0;
}