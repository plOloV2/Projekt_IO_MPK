#include <exception>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

#include "KursRozpoczety.hpp"
#include "AbsKurs.hpp"
#include "KartaKursu.hpp"

Model::KursRozpoczety::KursRozpoczety(Model::AbsKurs* pKurs, int pIdKierowcy) : Model::KartaKursu(pKurs), _idKierowcy(pIdKierowcy) {}

string Model::KursRozpoczety::opisz() {
	string opisKursu = to_string(_kurs->dajIdKursu()) + ';';
	for (int i = 0; i < _kurs->dajListaIdPrzystankow().size(); i++){
		if(i != 0){
			opisKursu = opisKursu + ',' + to_string(_kurs->dajListaIdPrzystankow().at(i));
		}
		else {
			opisKursu = opisKursu + to_string(_kurs->dajListaIdPrzystankow().at(i));
		}
	}
	opisKursu = opisKursu + ';';
	for (int i = 0; i < _kurs->dajListaGodzinPrzyjazdow().size(); i++){
		if(i != 0){
			opisKursu = opisKursu + ',' + _kurs->dajListaGodzinPrzyjazdow().at(i);
		}
		else{
			opisKursu = opisKursu + _kurs->dajListaGodzinPrzyjazdow().at(i);
		}
	}
	opisKursu = opisKursu + ';' + to_string(_idKierowcy);
	return opisKursu;
}

int Model::KursRozpoczety::dajIdKierowcy(){
	return _idKierowcy;
}

