#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//алгоритм random_shuffle -- располагает элементы в рандомном порядке
//для генерации уникальных порядков использовать random_shuffle


//позволяет выполнить переопределённый метод наследников класса в рандомном порядке



int main() {
    setlocale(LC_ALL, "RU");
    srand(time(NULL));

    int arr[] = {1,2,3, 4,5};

    for (auto el : arr) {
        cout << el << " ";
    }

    cout << endl;

    random_shuffle(begin(arr), end(arr));
   
    for (auto el : arr) {
        cout << el << " ";
    }
    
    return 0;
}