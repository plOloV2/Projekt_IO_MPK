#include <exception>
#include <string>
#include <vector>
using namespace std;

#include "AbsDAO.hpp"
void Model::AbsDAO::dodajWpisDoRejestru(string pZdarzenie) {
	throw "Not yet implemented";
}

void Model::AbsDAO::dodajKurs(string pKurs) {
	throw "Not yet implemented";
}

void Model::AbsDAO::edytujKurs(string pKurs) {
	throw "Not yet implemented";
}

string Model::AbsDAO::znajdzKurs(int pIdKursu) {
	throw "Not yet implemented";
}

vector<string> Model::AbsDAO::znajdzKursy(int pIdPrzystanku) {
	throw "Not yet implemented";
}

void Model::AbsDAO::edytujKierowce(int pIdKierowcy, int pIdKursu) {
	throw "Not yet implemented";
}

string Model::AbsDAO::znajdzKierowce(int pIdKierowcy) {
	throw "Not yet implemented";
}

vector<string> Model::AbsDAO::znajdzKierowcow(int pIdKursu) {
	throw "Not yet implemented";
}

void Model::AbsDAO::dodajPowiadomienie(vector<int> pIdKierowcow , string pPowiadomienie) {
	throw "Not yet implemented";
}

vector<string> Model::AbsDAO::znajdzPowiadomienia(int pIdKierowcy) {
	throw "Not yet implemented";
}

void Model::AbsDAO::dodajIncydent(string pIncydent) {
	throw "Not yet implemented";
}

vector<string> Model::AbsDAO::znajdzIncydenty() {
	throw "Not yet implemented";
}

void Model::AbsDAO::dodajWpisDoRejestruZdarzen(string pZdarzenie) {
	throw "Not yet implemented";
}

