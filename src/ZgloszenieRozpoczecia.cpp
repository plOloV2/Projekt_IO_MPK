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

void Kontroler::ZgloszenieRozpoczecia::zakonczenieAktualizacjiKursu(Model::AbsModel pModel, int pIdKierowcy, int pIdKursu) {
	string opisKursu = pModel.znalezienieKursuRozpoczetego(pIdKursu);
	if(opisKursu != "Brak"){
		string opisKierowcy = pModel.znalezienieKierowcy(pIdKierowcy);
		vector<string> atrybutyKierowcy;
		stringstream ss(opisKierowcy);
		string helper;
		while(getline(ss, helper, ';')){
			atrybutyKierowcy.push_back(helper);
		}
		if(stoi(atrybutyKierowcy.at(1)) == INT_MAX) {
			bool decyzja = zatwierdzenieRozpoczeciaKursu();
			if(decyzja){
				pModel.modyfikacjaKierowcy(pIdKursu);
				opisKursu = pModel.znalezienieKursu(pIdKursu) + ';' + to_string(pIdKierowcy) + ';';
				pModel.modyfikowanieKursu(opisKursu);
			}
		}
		else{
			cout << "Nie zakonczono kursu o ID: " << atrybutyKierowcy.at(1) << endl;
		}
	}
	else{
		cout << "Kurs zostal juz rozpoczety\n";
	}
}

