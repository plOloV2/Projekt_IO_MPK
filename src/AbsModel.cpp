#include <exception>
#include <string>
#include <vector>
using namespace std;

#include "AbsModel.hpp"
void Model::AbsModel::dodawanieKursu() {
	throw "Not yet implemented";
}

void Model::AbsModel::modyfikowanieKursu(string pKurs) {
	throw "Not yet implemented";
}

string Model::AbsModel::znalezienieKursu(int pIdKursu) {
	return "Brak";
}

string Model::AbsModel::znalezienieKierowcy(int pIdKierowcy) {
	throw "Not yet implemented";
}

void Model::AbsModel::modyfikacjaKierowcy(vector<bool> pStatusKierowcy ) {
	throw "Not yet implemented";
}

string* Model::AbsModel::znalezienieKierowcow(int pIdKursow) {
	throw "Not yet implemented";
}

void Model::AbsModel::wyslaniePowiadomien(vector<int> pIdKierowcow , string pPowiadomienie) {
	throw "Not yet implemented";
}

void Model::AbsModel::zglaszenieIncydentu(string pIncydent) {
	throw "Not yet implemented";
}

string* Model::AbsModel::znajdzGodzinyPrzyjazdow(int pIdPrzystanku) {
	throw "Not yet implemented";
}

void Model::AbsModel::zarejestrowanieZdarzenia(string pZdarzenie) {
	throw "Not yet implemented";
}

