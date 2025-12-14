#include <exception>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

#include "Model.hpp"
#include "AbsDAO.hpp"
#include "Inwentarz.hpp"
#include "AbsModel.hpp"

Model::Model::Model(Inwentarz pInwentarz, AbsDAO pDao) {
}

void Model::Model::dodawanieKursu()  {
	throw "Not yet implemented";
}

void Model::Model::modyfikowanieKursu(string pKurs)  {
	_inwentarz.modyfikujKurs(pKurs);
}

string Model::Model::znalezienieKursu(int pIdKursu)  {
	Kurs kurs = _inwentarz.dajKurs(pIdKursu);
	string opisKursu = kurs.opisz();
	return opisKursu;
}

string Model::Model::znalezienieKierowcy(int pIdKierowcy)  {
	Kierowca kierowca = _inwentarz.dajKierowce(pIdKierowcy);
	string opisKierowcy = kierowca.opisz();
	return opisKierowcy;
}

void Model::Model::modyfikacjaKierowcy(int pIdKierowcy)  {
	_inwentarz.modyfikujKierowce(pIdKierowcy);
}

string* Model::Model::znalezienieKierowcow(int pIdKursow)  {
	throw "Not yet implemented";
}

void Model::Model::wyslaniePowiadomien(vector<int> pIdKierowcow , string pPowiadomienie)  {
	throw "Not yet implemented";
}

void Model::Model::zglaszenieIncydentu(string pIncydent)  {
	_inwentarz.dodajIncydent(pIncydent);
}

vector<string> Model::Model::znajdzGodzinyPrzyjazdow(int pIdPrzystanku)  {
	vector<Kurs> kursy = _inwentarz.dajGodzinyPrzyjazdow(pIdPrzystanku);
	vector<string> opisyKursow;
	for(int i = 0; i < kursy.size(); i++){
		opisyKursow.push_back(kursy.at(i).opisz());
	}
	return opisyKursow;
}

void Model::Model::zarejestrowanieZdarzenia(string pZdarzenie)  {
	throw "Not yet implemented";
}

string Model::Model::znalezienieKursuRozpoczetego(int pIdKursu)  {
	KursRozpoczety kurs = _inwentarz.dajKursRozpoczety(pIdKursu);
	string opisKursu = kurs.opisz();
	return opisKursu;
}