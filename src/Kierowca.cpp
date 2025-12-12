#include <exception>
#include <string>
using namespace std;

#include "Kierowca.hpp"
Model::Kierowca::Kierowca(int pIdKierowcy, int pIdKursu) {
	this->_idKierowcy = pIdKierowcy;
	this->_idKursu = pIdKursu;
}

int Model::Kierowca::dajIdKierowcy() {
	return _idKierowcy;
}

int Model::Kierowca::dajIdKursu() {
	return _idKursu;
}

string Model::Kierowca::opisz() {
	string opis = to_string(_idKierowcy) + ";" + to_string(_idKursu) + ";";
	return opis;
}

