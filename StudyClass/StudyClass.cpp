#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;

class Point {
public:

	Point() {
		x = y = z = 0;
	}

	Point(int x, int y, int z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
	

private:
	int x;
	int y;
	int z;

	friend ostream& operator <<(ostream& os, const Point& point);
	friend istream& operator >>(istream& is, Point& point);
		;

};

ostream& operator <<(ostream& os, const Point& point)
{
	os << point.x << " " << point.y << " " << point.z;
	return os;
}

istream& operator >>(istream& is, Point& point)
{
	is >> point.x >> point.y >> point.z;
	return is;
}


int main() {
	setlocale(LC_ALL, "RU");

	//Point p(7, 8, 9);

	//cout << p;
	
	string path = "myFile.txt";

	fstream fs;
	fs.open(path, fstream::in | fstream::out | fstream::app); 

	if (!fs.is_open()) {
		cout << "Файл не удалось открыть " << endl;
	}
	else {

		cout << "Файл открыт" << endl;
		//fs << p << "\n";

		while (true) {

			Point p;
			fs >> p;
			if (fs.eof()) break;
			cout << p << endl;
		}

		
	}

	fs.close();
	
	return 0;
}
