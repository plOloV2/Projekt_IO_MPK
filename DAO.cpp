#include <exception>
#include <string>
using namespace std;

#include "DAO.hpp"
#include "AbsDAO.hpp"

Model::DAO::DAO() {
}

void Model::DAO::dodajWpisDoRejestru(String pZdarzenie) {
	throw "Not yet implemented";
}

int Model::DAO::dodajKurs() {
	throw "Not yet implemented";
}

void Model::DAO::edytujKurs(string pKurs) {
	throw "Not yet implemented";
}

string Model::DAO::znajdzKurs(int pIdKursu) {
	throw "Not yet implemented";
}

void Model::DAO::edytujKierowce(bool pStatusKierowcy[*] ) {
	throw "Not yet implemented";
}

string Model::DAO::znajdzKierowce(int pIdKierowcy) {
	throw "Not yet implemented";
}

string* Model::DAO::znajdzKierowcow(int pIdKursu) {
	throw "Not yet implemented";
}

void Model::DAO::dodajPowiadomienie(int pIdKierowcow[*] , string pPowiadomienie) {
	throw "Not yet implemented";
}

string* Model::DAO::znajdzPowiadomienia(int pIdKierowcy) {
	throw "Not yet implemented";
}

void Model::DAO::dodajIncydent(string pIncydent) {
	throw "Not yet implemented";
}

string* Model::DAO::znajdzIncydenty() {
	throw "Not yet implemented";
}

void Model::DAO::dodajWpisDoRejestruZdarzen(string pZdarzenie) {
	throw "Not yet implemented";
}

