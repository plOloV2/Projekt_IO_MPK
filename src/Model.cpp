#include <exception>
#include <string>
#include <vector>
using namespace std;

#include "Model.hpp"
#include "AbsDAO.hpp"
#include "Inwentarz.hpp"
#include "AbsModel.hpp"

Model::Model::Model(Inwentarz pInwentarz, AbsDAO pDao) {
}

void Model::Model::dodawanieKursu() {
	throw "Not yet implemented";
}

void Model::Model::modyfikowanieKursu(string pKurs) {
	throw "Not yet implemented";
}

string Model::Model::znalezienieKursu(int pIdKursu) {
	Kurs kurs = _inwentarz.dajKurs(pIdKursu);
	string opisKursu = kurs.opisz();
	return opisKursu;
}

string Model::Model::znalezienieKierowcy(int pIdKierowcy) {
	Kierowca kierowca = _inwentarz.dajKierowce(pIdKierowcy);
	string opisKierowcy = kierowca.opisz();
	return opisKierowcy;
}

void Model::Model::modyfikacjaKierowcy(int pIdKierowcy) {
	
}

string* Model::Model::znalezienieKierowcow(int pIdKursow) {
	throw "Not yet implemented";
}

void Model::Model::wyslaniePowiadomien(vector<int> pIdKierowcow , string pPowiadomienie) {
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

string Model::Model::znalezienieKursuRozpoczetego(int pIdKursu) {
	Kurs kurs = _inwentarz.dajKursRozpoczety(pIdKursu);
	string opisKursu = kurs.opisz();
	return opisKursu;
}