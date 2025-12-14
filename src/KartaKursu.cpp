#include <exception>
#include <string>
#include <iostream>
using namespace std;

#include "KartaKursu.hpp"
#include "AbsKurs.hpp"

Model::KartaKursu::KartaKursu(Model::AbsKurs* pKurs) {
	this->_kurs = pKurs;
}

int Model::KartaKursu::dajIdKursu() {
	throw _kurs->dajIdKursu();
}

vector<int> Model::KartaKursu::dajListaIdPrzystankow() {
	cout << "dajListaIdPrzystankow()\n";
	throw _kurs->dajListaIdPrzystankow();
}

vector<string> Model::KartaKursu::dajListaGodzinPrzyjazdow() {
	return _kurs->dajListaGodzinPrzyjazdow();
}

string Model::KartaKursu::opisz() {
	throw "Not yet implemented";
}

