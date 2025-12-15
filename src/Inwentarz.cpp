#include <exception>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

#include "Inwentarz.hpp"
#include "AbsDAO.hpp"
#include "Kierowca.hpp"
#include "Powiadomienie.hpp"
#include "AbsKurs.hpp"
#include "Incydent.hpp"
#include "Kurs.hpp"
#include "KursRozpoczety.hpp"
#include "Kierowca.hpp"

Model::Inwentarz::Inwentarz() {
}

Model::Inwentarz::Inwentarz(AbsDAO pDao) {
}

void Model::Inwentarz::modyfikujKurs(string pKurs) {
	cout << "Zmodyfikowano kurs\n";
}

Model::Kurs Model::Inwentarz::dajKurs(int pIdKursu) {
	vector<int> listaPrzystankow;
	vector<string> listaGodzinPrzyjazdow;
	return Kurs(pIdKursu, listaPrzystankow, listaGodzinPrzyjazdow);
}

Model::Kierowca Model::Inwentarz::dajKierowce(int pIdKierowcy) {
	int idKursu = -1;
	return Kierowca(pIdKierowcy, idKursu);
}

void Model::Inwentarz::modyfikujKierowce(int pIdKierowcy) {
	cout << "Zmodyfikowano kierowce\n";
}

Model::Kierowca* Model::Inwentarz::dajKierowcow(int pIdKursu) {
	throw "Not yet implemented";
}

void Model::Inwentarz::dodajPowiadomienie(vector<int> pIdKierowcow , string pPowiadmienie) {
	throw "Not yet implemented";
}

void Model::Inwentarz::dodajIncydent(string pIncydent) {
	cout << "Dodano incydent\n";
}

vector<Model::Kurs> Model::Inwentarz::dajGodzinyPrzyjazdow(int pIdPrzystanku) {
	vector<Model::Kurs> godzinyPrzyjazdow;
	return godzinyPrzyjazdow;
}

Model::KursRozpoczety Model::Inwentarz::dajKursRozpoczety(int pIdKursu) {
	vector<int> listaPrzystankow;
	vector<string> listaGodzinPrzyjazdow;
	Kurs* kurs = new Kurs(pIdKursu, listaPrzystankow, listaGodzinPrzyjazdow);
	int idKierowcy = rand() % 10;
	return KursRozpoczety(kurs, idKierowcy);
}