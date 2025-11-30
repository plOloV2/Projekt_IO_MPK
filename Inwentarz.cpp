#include <exception>
#include <string>
using namespace std;

#include "Inwentarz.hpp"
#include "AbsDAO.hpp"
#include "Kierowca.hpp"
#include "Powiadomienie.hpp"
#include "Kurs.hpp"
#include "Incydent.hpp"

Model::Inwentarz::Inwentarz(Model::AbsDAO pDao) {
}

void Model::Inwentarz::modyfikujKurs(string pKurs) {
	throw "Not yet implemented";
}

Model::Kurs Model::Inwentarz::dajKurs(int pIdKursu) {
	throw "Not yet implemented";
}

Model::Kierowca Model::Inwentarz::dajKierowce(int pIdKierowcy) {
	throw "Not yet implemented";
}

void Model::Inwentarz::modyfikujKierowce(bool pStatusKierowcy[] ) {
	throw "Not yet implemented";
}

Kierowcy* Model::Inwentarz::dajKierowcow(int pIdKursu) {
	throw "Not yet implemented";
}

void Model::Inwentarz::dodajPowiadomienie(int pIdKierowcow[] , string pPowiadmienie) {
	throw "Not yet implemented";
}

void Model::Inwentarz::dodajIncydent(string pIncydent) {
	throw "Not yet implemented";
}

Model::Kurs* Model::Inwentarz::dajGodzinyPrzyjazdow(int pIdPrzystanku) {
	throw "Not yet implemented";
}

