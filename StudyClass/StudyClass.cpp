#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;

//перечисляемый тип для объявления символических имён целочисленных констант
//может прописываться и вне самого классаю если в классе то ведёт себя как метод



class PC {
public:

	enum PcState
	{
		Off,
		On,
		Sleap
	};

	PcState GetState()
	{ 
		return State;
	}
	void SetState(PcState state) {
		this->State = state;
	}


private:
	PcState State;
}; 


int main() {
	setlocale(LC_ALL, "RU");


	PC pc;
	pc.SetState(pc.PcState::Off);
	/*if (pc.GetState() == PcState::On) {
		cout << "PC work" << endl;
	}*/
	

	switch (pc.GetState())
	{
	case pc.PcState::On:
		cout << "Включён" << endl;
		break;
	case pc.PcState::Off:
		cout << "Выключен" << endl;
		break; 
	case pc.PcState::Sleap:
		cout << "Спит" << endl;
		break;
	}

	/*PcState p;
	p = PcState::Off;*/
	
	return 0;
}
