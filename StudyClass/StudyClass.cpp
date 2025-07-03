#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;

//fstream библиотека для чтение и запись одновременно

//ifstrim класс чтение записей из файла
//ofstream класс сохранение записей в файл


int main() {
	setlocale(LC_ALL, "RU");
	
	//!ВАЖНО. Файл должен быть сохранён в кодировке ANSI, автоматически он создаётся в кодировке  UTF-8

	string path = "myFile.txt";

	ifstream fin;
	fin.open(path);

	if (!fin.is_open()) {
		cout << "Ошибка открытия файла" << endl;

	}
	else {
		cout << "файл открыт " << endl;
		cout << "---------------- " << endl;
		char ch;
		string str;

		while (getline(fin, str)) { //читаем строку до endl. Самый хороший вариант потому что проверяем сразу смогли ли считать строку
			cout << str << endl;
		}


		//while (!fin.eof()) {
		//	//str = " "; //читает строку до пробела, поэтому нужно "затереть" строку
		//	//fin >> str; 
		
		//	getline(fin, str);
		//	cout << str<<endl;
		//}


		//while (fin.get(ch)) {//посимвольное считывание из файла и сохранение символа в переменную. get не работает со строками, только с символами
		//	cout << ch;
		//}
	}

	fin.close();

	/*ofstream fout;

	fout.open(path, ofstream::app); //создание файла в папке проекта. если нет такого файла функция open создаёт его. ofstream::app дописывает в существующий файл новую информацию без потери предыдущей

	if (!fout.is_open())
	{
		cout << "Ошибка открытия файла" << endl;
	}else {
		for (int i = 0; i < 4; i++)
		{
			cout << "Введите число: ";
			int a;
			cin >> a;
			fout << a << "\n"; //запись информации в файл(указывается название файла + управление потоком)
		}
		
	}

	fout.close();*/


	return 0;
}
