#include <exception>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

#include "Kurs.hpp"
#include "AbsKurs.hpp"

Model::Kurs::Kurs(int pIdKursu, vector<int> pListaIdPrzystankow , vector<string> pListaGodzinPrzyjazdow ) {
	this->_idKursu = pIdKursu;
	this->_listaIdPrzystankow = pListaIdPrzystankow;
	this->_listaGodzinPrzyjazdow = pListaGodzinPrzyjazdow;
}

int Model::Kurs::dajIdKursu() {
	return _idKursu;
}

vector<int> Model::Kurs::dajListaIdPrzystankow() {
	return _listaIdPrzystankow;
}

vector<string> Model::Kurs::dajListaGodzinPrzyjazdow() {
	return _listaGodzinPrzyjazdow;
}

string Model::Kurs::opisz() {
	string opisKursu = to_string(_idKursu) + ';';
	for (int i = 0; i < _listaIdPrzystankow.size(); i++){
		if(i != 0){
			opisKursu = opisKursu + ',' + to_string(dajListaIdPrzystankow().at(i));
		}
		else {
			opisKursu = opisKursu + to_string(dajListaIdPrzystankow().at(i));
		}
	}
	opisKursu = opisKursu + ';';
	for (int i = 0; i < _listaGodzinPrzyjazdow.size(); i++){
		if(i != 0){
			opisKursu = opisKursu + ',' + dajListaGodzinPrzyjazdow().at(i);
		}
		else{
			opisKursu = opisKursu + dajListaGodzinPrzyjazdow().at(i);
		}
	}
	return opisKursu;
}

