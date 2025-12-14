#include <exception>
#include <iostream>
using namespace std;

#include "AktualizacjaStanuKursu.hpp"
#include "AbsStrategiaAktualizacjiStanuKursu.hpp"
#include "Model.hpp"
#include "ZgloszenieRozpoczecia.hpp"
#include "ZgloszenieZakonczenia.hpp"
#include "ZgloszenieIncydentu.hpp"

Kontroler::AktualizacjaStanuKursu::AktualizacjaStanuKursu(Model::AbsModel* pModel, int pIdKierowcy) {
	cout << "AktualizacjaStanuKursu()\n";
	this->_absModel = pModel;
	this->_idKierowcy = pIdKierowcy;
	int idKursu = wprowadzenieIdKursu();
	string kurs = _absModel->znalezienieKursu(idKursu);
	cout << kurs << endl;
	if(kurs != "Brak"){
		wyborOpcji();
		_strategiaAktualizacjiStanuKursu->zakonczenieAktualizacjiKursu(_absModel, _idKierowcy, idKursu);
	}
}

int Kontroler::AktualizacjaStanuKursu::wprowadzenieIdKursu() {
	cout << "wprowadzenieIdKursu()\n";
	return rand() % 10;
}

void Kontroler::AktualizacjaStanuKursu::wyborOpcji() {
	cout << "wyborOpcji()\n";
	int opcja = rand() % 3;
	if(opcja == 0){
		_strategiaAktualizacjiStanuKursu = new ZgloszenieRozpoczecia();
	}
	else if(opcja == 1){
		_strategiaAktualizacjiStanuKursu = new ZgloszenieZakonczenia();
	}
	else{
		_strategiaAktualizacjiStanuKursu = new ZgloszenieIncydentu();
	}
}

