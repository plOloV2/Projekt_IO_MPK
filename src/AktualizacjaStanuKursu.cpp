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
	cout << "Aktualizowanie statusu kursu\n";
	this->_absModel = pModel;
	this->_idKierowcy = pIdKierowcy;
	int idKursu = wprowadzenieIdKursu();
	string kurs = _absModel->znalezienieKursu(idKursu);
	if(kurs != "Brak"){
		wyborOpcji();
		_strategiaAktualizacjiStanuKursu->zakonczenieAktualizacjiKursu(_absModel, _idKierowcy, idKursu);
	}
	cout << "Stan kursu zostal zaktualizowany\n";
}

int Kontroler::AktualizacjaStanuKursu::wprowadzenieIdKursu() {
	return 1;//rand() % 10;
}

void Kontroler::AktualizacjaStanuKursu::wyborOpcji() {
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

