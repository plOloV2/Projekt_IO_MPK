#include <exception>
#include <iostream>
#include <sstream>
using namespace std;

#include "ZgloszenieZakonczenia.hpp"
#include "AbsStrategiaAktualizacjiStanuKursu.hpp"

Kontroler::ZgloszenieZakonczenia::ZgloszenieZakonczenia() {
}

bool Kontroler::ZgloszenieZakonczenia::zatwierdzenieZakonczeniaKursu() {
	return true;
}

void Kontroler::ZgloszenieZakonczenia::zakonczenieAktualizacjiKursu(Model::AbsModel* pModel, int pIdKierowcy, int pIdKursu) {
	cout << "Konczenie kursu\n";
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
			bool decyzja = zatwierdzenieZakonczeniaKursu();
			if(decyzja){
				pModel->modyfikacjaKierowcy(-1);
				opisKursu = pModel->znalezienieKursu(pIdKursu);
				vector<string> atrybutyKursu;
				stringstream streamKursu(opisKursu);
				while(getline(streamKursu, helper, ';')){
					atrybutyKierowcy.push_back(helper);
				}
				opisKursu = atrybutyKursu.at(0) + ';' + atrybutyKursu.at(1) + ';' + atrybutyKursu.at(2) + ';';
				pModel->modyfikowanieKursu(opisKursu);
			}
		}
		else{
			cout << "Kierowca nie posiada rozpoczetego kursu\n";
		}
	}
	else{
		cout << "Kurs o tym ID nie zostal rozpoczety\n";
	}
	cout << "Kurs zostal zakonczony\n";
}

