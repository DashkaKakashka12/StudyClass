#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>
#include <numeric>
using namespace std;


//accunulate -- сумма и произведение элементов массива. обязатлеьно подключить библиотеку numeric. третий параметр- значение к которому прибавится результат вычисления
//стандартное поведение сложение.
//для умножения четвёртым параметром предикат, в него передаём 2 параметра и перемножаем в return

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
    

    //auto result = accumulate(begin(v), end(v), 0); //можно использовать begin, end из stl
    //auto result = accumulate(begin(v), end(v), 1, [](int a, int b) {return a * b; });//первый параметр -- сумма на текущий момент. второй - то что мы будем домножать
    /*auto result = accumulate(begin(v), end(v), 0, [](int a, int b) {
        if (b % 2 == 0) {
            return a + b;
        }
        else return a;

    }); */

   

    string result = accumulate(next(begin(v)), end(v), to_string(v[0]), [](string a, int b) { //
        return a + "--" + to_string(b);
    });
    //точка отсчёта to_string(v[0]) -- первый элемент, приведённый к стринге, первый параметр предикаты уже строка. 
    //так как начинали считать уже с первого элемента, используем next (сдвигает начало коллекции на 1 элемент)


    cout << result << endl;

    return 0;
}