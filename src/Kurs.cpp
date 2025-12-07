#include <exception>
#include <string>
#include <vector>
using namespace std;

#include "Kurs.hpp"
#include "AbsKurs.hpp"

Model::Kurs::Kurs(int pIdKursu, vector<int> pListaIdPrzystankow , vector<string> pListaGodzinPrzyjazdow ) {
}

int Model::Kurs::dajIdKursu() {
	throw "Not yet implemented";
}

int* Model::Kurs::dajListaIdPrzystankow() {
	throw "Not yet implemented";
}

string* Model::Kurs::dajListaGodzinPrzyjazdow() {
	throw "Not yet implemented";
}

string Model::Kurs::opisz() {
	throw "Not yet implemented";
}

