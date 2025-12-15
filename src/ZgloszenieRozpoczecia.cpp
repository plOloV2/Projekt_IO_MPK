#include <exception>
#include <sstream>
#include <iostream>
using namespace std;

#include "ZgloszenieRozpoczecia.hpp"
#include "AbsStrategiaAktualizacjiStanuKursu.hpp"
#include "Model.hpp"

Kontroler::ZgloszenieRozpoczecia::ZgloszenieRozpoczecia() {
}

bool Kontroler::ZgloszenieRozpoczecia::zatwierdzenieRozpoczeciaKursu() {
	return true;
}

void Kontroler::ZgloszenieRozpoczecia::zakonczenieAktualizacjiKursu(Model::AbsModel* pModel, int pIdKierowcy, int pIdKursu) {
	cout << "Rozpoczynanie kursu\n";
	string opisKursu = pModel->znalezienieKursuRozpoczetego(pIdKursu);
	if(opisKursu == ""){
		string opisKierowcy = pModel->znalezienieKierowcy(pIdKierowcy);
		vector<string> atrybutyKierowcy;
		stringstream streamKierowcy(opisKierowcy);
		string helper;
		while(getline(streamKierowcy, helper, ';')){
			atrybutyKierowcy.push_back(helper);
		}
		if(stoi(atrybutyKierowcy.at(1)) == -1) {
			bool decyzja = zatwierdzenieRozpoczeciaKursu();
			if(decyzja){
				pModel->modyfikacjaKierowcy(pIdKierowcy, pIdKursu);
				opisKursu = pModel->znalezienieKursu(pIdKursu) + ';' + to_string(pIdKierowcy);
				pModel->modyfikowanieKursu(opisKursu);
			}
		}
		else{
			cout << "Nie zakonczono kursu o ID: " << atrybutyKierowcy.at(1) << endl;
		}
	}
	else{
		cout << "Kurs zostal juz rozpoczety\n";
	}
	cout << "Kurs zostal rozpoczety\n";
}

