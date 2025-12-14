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
	throw "Not yet implemented";
}

vector<int> Model::Kurs::dajListaIdPrzystankow() {
	throw "Not yet implemented";
}

vector<string> Model::Kurs::dajListaGodzinPrzyjazdow() {
	throw "Not yet implemented";
}

string Model::Kurs::opisz() {
	cout << "opisz()\n";
	string opisKursu = to_string(_idKursu) + ';';
	for (int i = 0; i < _listaIdPrzystankow.size(); i++){
		opisKursu = opisKursu + ',' + to_string(_listaIdPrzystankow.at(i));
	}
	opisKursu = opisKursu + ';';
	for (int i = 0; i < _listaGodzinPrzyjazdow.size(); i++){
		opisKursu = opisKursu + ',' + _listaGodzinPrzyjazdow.at(i);
	}
	opisKursu = opisKursu + ';';
	return opisKursu;
}

