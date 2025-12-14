#include <exception>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

#include "KursRozpoczety.hpp"
#include "AbsKurs.hpp"
#include "KartaKursu.hpp"

Model::KursRozpoczety::KursRozpoczety(Model::AbsKurs* pKurs, int pIdKierowcy) : Model::KartaKursu(pKurs), _idKierowcy(pIdKierowcy) {
	this->_kurs = pKurs;
	this->_idKierowcy = pIdKierowcy;
}

string Model::KursRozpoczety::opisz() {
	cout << "opisz()R\n";
	string opisKursu = to_string(_kurs->dajIdKursu()) + ';';
	for (int i = 0; i < _kurs->dajListaIdPrzystankow().size(); i++){
		opisKursu = opisKursu + ',' + to_string(_kurs->dajListaIdPrzystankow().at(i));
	}
	opisKursu = opisKursu + ';';
	for (int i = 0; i < _kurs->dajListaGodzinPrzyjazdow().size(); i++){
		opisKursu = opisKursu + ',' + _kurs->dajListaGodzinPrzyjazdow().at(i);
	}
	opisKursu = opisKursu + ';' + to_string(_idKierowcy) + ';';
	return opisKursu;
}

