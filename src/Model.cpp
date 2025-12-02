#include <exception>
#include <string>
using namespace std;

#include "Model.hpp"
#include "Inwentarz.hpp"
#include "AbsDAO.hpp"
#include "AbsModel.hpp"

void Model::Model::dodawanieKursu() {
	throw "Not yet implemented";
}

void Model::Model::modyfikowanieKursu(string pKurs) {
	throw "Not yet implemented";
}

string Model::Model::znalezienieKursu(int pIdKursu) {
	throw "Not yet implemented";
}

string Model::Model::znalezienieKierowcy(int pIdKierowcy) {
	throw "Not yet implemented";
}

void Model::Model::modyfikacjaKierowcy(bool pStatusKierowcy[] ) {
	throw "Not yet implemented";
}

string* Model::Model::znalezienieKierowcow(int pIdKursow) {
	throw "Not yet implemented";
}

void Model::Model::wyslaniePowiadomien(int pIdKierowcow[] , string pPowiadomienie) {
	throw "Not yet implemented";
}

void Model::Model::zglaszenieIncydentu(string pIncydent) {
	throw "Not yet implemented";
}

string* Model::Model::znajdzGodzinyPrzyjazdow(int pIdPrzystanku) {
	throw "Not yet implemented";
}

void Model::Model::zarejestrowanieZdarzenia(string pZdarzenie) {
	throw "Not yet implemented";
}

