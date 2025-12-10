#include <exception>
#include <iostream>
using namespace std;

#include "AktualizacjaStanuKursu.hpp"
#include "AbsStrategiaAktualizacjiStanuKursu.hpp"
#include "Model.hpp"
#include "ZgloszenieRozpoczecia.hpp"
#include "ZgloszenieZakonczenia.hpp"
#include "ZgloszenieIncydentu.hpp"

Kontroler::AktualizacjaStanuKursu::AktualizacjaStanuKursu(Model::AbsModel pModel, int pIdKierowcy) {
	this->_absModel = pModel;
	this->_idKierowcy = pIdKierowcy;
	int idKursu = wprowadzenieIdKursu();
	cout << idKursu << endl;
	string kurs = _absModel.znalezienieKursu(idKursu);
	if(kurs != "Brak"){
		wyborOpcji();
		_strategiaAktualizacjiStanuKursu.zakonczenieAktualizacjiKursu(_absModel, _idKierowcy, idKursu);
	}
}

int Kontroler::AktualizacjaStanuKursu::wprowadzenieIdKursu() {
	return rand() % 10;
}

void Kontroler::AktualizacjaStanuKursu::wyborOpcji() {
	int opcja = rand() % 3;
	if(opcja == 0){
		_strategiaAktualizacjiStanuKursu = ZgloszenieRozpoczecia();
	}
	else if(opcja == 1){
		_strategiaAktualizacjiStanuKursu = ZgloszenieZakonczenia();
	}
	else{
		_strategiaAktualizacjiStanuKursu = ZgloszenieIncydentu();
	}
}

