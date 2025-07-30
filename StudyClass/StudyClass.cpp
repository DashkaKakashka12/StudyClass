#include <iostream>
#include <list>
#include "Sum.h"
#include "My.h"


using namespace std;

//многофайловые проекты. создаётся заголовочный файл Sum.h с прототипом функции. в основном файле Sum.cpp написана реализация. с помощью #include "Sum.h" подключаем для основного файла
//



int main() {
	setlocale(LC_ALL, "RU");

	cout << Sum(3, 4) << endl;
	My m;
	m.PrintMsg("Hello World");

	return 0;
}
