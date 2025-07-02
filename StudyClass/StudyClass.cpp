#include <iostream>
#include <string>

using namespace std;

class Component {
public:
	string companyNamy;

	Component() {
		cout << "конструктор Component" << endl;
	}

};

class GPU : public virtual Component {
public:
	GPU(string companyNamy) : Component() { //Component — виртуальный базовый класс. Виртуальные базовые классы не инициализируются в промежуточных классах. Классы наследники не владеют собственной отдельной копией Component 


		cout << "конструктор GPU" << endl;
	}
};


class Memory : public virtual Component {
public:
	Memory(string companyNamy) : Component() { //конструктор Component не вызывается, но Memory имеет доступ к членам Component
		cout << "конструктор Memory" << endl;
	}
};

class GraphicCard : public GPU, public Memory { //только тут вызывается Component() именно при создании GraphicCard
public:
	GraphicCard(string GPUcompanyNamy, string MemorycompanyNamy): GPU(GPUcompanyNamy), Memory(MemorycompanyNamy) {
		cout << "конструктор GraphicCard" << endl;
	}
};

int main() {
	setlocale(LC_ALL, "RU");
	
	GraphicCard g("AMD", "Samsung");



	return 0;
}
