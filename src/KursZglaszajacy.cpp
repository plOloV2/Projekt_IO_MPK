#include <exception>
#include <string>
using namespace std;

#include "KursZglaszajacy.hpp"
#include "Incydent.hpp"
#include "AbsKurs.hpp"
#include "KartaKursu.hpp"

Model::KursZglaszajacy::KursZglaszajacy(Model::AbsKurs* pKurs, Model::Incydent* pIncydent) : Model::KartaKursu(pKurs), _incydent(pIncydent) {
	this->_kurs = pKurs;
	this->_incydent = pIncydent;
}

string Model::KursZglaszajacy::opisz() {
	throw "Not yet implemented";
}

