#include <exception>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

#include "ZgloszenieIncydentu.hpp"
#include "AbsStrategiaAktualizacjiStanuKursu.hpp"

Kontroler::ZgloszenieIncydentu::ZgloszenieIncydentu() {
	cout << "Constructor\n";
}

int Kontroler::ZgloszenieIncydentu::wyborTypuIncydentu() {
	return rand() % 4;
}

string Kontroler::ZgloszenieIncydentu::wprowadzenieOpisuIncydentu() {
	return "Przykladowy opis incydentu...";
}

void Kontroler::ZgloszenieIncydentu::zakonczenieAktualizacjiKursu(Model::AbsModel* pModel, int pIdKierowcy, int pIdKursu) {
	cout << "zakonczenieAktualizacjiKursu()\n";
	string opisKursu = pModel->znalezienieKursuRozpoczetego(pIdKursu);
	if(opisKursu != "Brak"){
		string opisKierowcy = pModel->znalezienieKierowcy(pIdKierowcy);
		vector<string> atrybutyKierowcy;
		stringstream streamKierowcy(opisKierowcy);
		string helper;
		while(getline(streamKierowcy, helper, ';')){
			atrybutyKierowcy.push_back(helper);
		}
		if(stoi(atrybutyKierowcy.at(1)) == pIdKursu) {
			int typIncydentu = wyborTypuIncydentu();
			string opisIncydentu = wprowadzenieOpisuIncydentu();
			pModel->zglaszenieIncydentu(to_string(typIncydentu) + ';' + opisIncydentu + ';');
		}
		else{
			cout << "Kierowca nie posiada rozpoczetego kursu\n";
		}
	}
	else{
		cout << "Kurs o tym ID nie zostal rozpoczety\n";
	}
}

