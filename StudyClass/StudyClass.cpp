#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//алгоритм unique -- для удаления повторяющихся элементов. как remove, не удаляет а преносит элементы в конец не меняя кол-ва элементов коллекции
//для вывода эл-тов до границы используем for_each, для удаления ненужных элементов используем erase(result, v.end())

//uniqu_copy -- позволяет скопировать уникальные элементы в новый контецнер
//не обязательно чтобы два контейнер абыли одинаковы для uniqu_copy, важен тип данных



int main() {
    setlocale(LC_ALL, "RU");

    vector<int> arr = {1,2,7,4,4,7,8,1};
    vector<int> arr2;

    for (auto el : arr) {
        cout << el << " ";
    }

    cout << endl;
    //auto result = unique(begin(arr), end(arr));
    auto result = unique_copy(begin(arr), end(arr), back_inserter(arr2));
    for_each(begin(arr2), end(arr2), [](int a) {cout << a << " ";});
    //for_each(begin(arr), result, [](int a) {cout << a << " ";});
    
   

    return 0;
}