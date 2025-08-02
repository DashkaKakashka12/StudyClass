#include <iostream>
#include <thread>
#include <chrono>


using namespace std;

//время выполнения участка кода
//chrono можно использовать дял измерения времени участков кода без потоком. по умолчанию в thread подключена chrono

//для участка кода
/*auto start = chrono::high_resolution_clock::now(); -- в начале выполнения
auto end = chrono::high_resolution_clock::now(); -- в конце выполнения
chrono::duration<float> duration = end - start;
cout << "duration: " << duration.count() << " s" << endl;*/

class SimpleTimer
{
public:
    SimpleTimer() {
        start = std::chrono::high_resolution_clock::now();
    };
    ~SimpleTimer() {
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> duration = end - start;
        cout << "duration: " << duration.count() << " s" << endl;
    };

private:
    std::chrono::steady_clock::time_point start, end;

};


int Sum(int a, int b) {
    SimpleTimer st;
    this_thread::sleep_for(chrono::milliseconds(3000));
    cout << "---Sum START---" << endl;
    this_thread::sleep_for(chrono::milliseconds(7000));
    cout << "---Sum STOP---" << endl;

    return a + b;
}

int main() {
    setlocale(LC_ALL, "RU");

    SimpleTimer st;

    //auto start = chrono::high_resolution_clock::now();
    //int a = Sum(2, 3); //15.6205 s, без задержви во времени  5.62594 s
    int res;

    thread th([&res](){ res = Sum(2, 3); } ); //10.0235 s

    for (size_t i = 0; i<=10; i++)
    {
        cout << "ID: " << this_thread::get_id() << "\tmain\t" << i << endl;
        this_thread::sleep_for(chrono::milliseconds(500)); 
    }
    
   th.join();
    cout <<"res: "<< res << endl;


    //auto end = chrono::high_resolution_clock::now();
   // chrono::duration<float> duration = end - start;
   // cout << "duration: " << duration.count() << " s" << endl;

    return 0;
}