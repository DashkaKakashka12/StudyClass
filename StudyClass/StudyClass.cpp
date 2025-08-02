#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

//алгоритм -- набор функций для упрощения решения определённых задач
// для sort нужен обязательно бинарный преикат
// sort(v.begin(), v.end(), [](int a, int b) {return a > b;});

//148 пример большой сортировки коллекции. 
//показано что в классе для sort должен быть перегружен оператор сравнения, если не ипользуется предикат


bool MinNull(int a) {
    return a > 0;
}

bool MoreNull(int a) {
    return a < 0;
}



int main() {
    setlocale(LC_ALL, "RU");

    vector<int> v = { 1, 4, 8, 9, 89, 2 };
    sort(v.begin(), v.end(), [](int a, int b) {return a > b;});
    // sort(v.begin(), v.end()); -- сортировка от меньшего к большему по умолчанию
    //третий параметр это предикат. анонимный предикат = булевый. бинарный -- принимающий два параметра 
   
    
    for (auto el : v) {
        cout << el << endl;

    }

    cout << "-----------" << endl;

    const int size = 6;
    int arr[size] = {1, 4, 8, 9, 89, 2};

    sort(arr, arr + size, [](int a, int b) {return a > b;});

    for (auto el : arr) {
        cout << el << endl;
    }


    
    

    return 0;
}