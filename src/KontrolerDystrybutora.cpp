#include <exception>
using namespace std;

#include "KontrolerDystrybutora.hpp"
#include "AbsModel.hpp"
#include "AbsKontrolerDystrybutora.hpp"

Kontroler::KontrolerDystrybutora::KontrolerDystrybutora(Model::AbsModel* pModel) {
	this->_absModel = pModel;
}

void Kontroler::KontrolerDystrybutora::modyfikowanieRozkladuJazdy() {
	// modyfikowanieRozkladuJazdy
}

void Kontroler::KontrolerDystrybutora::wysylanieInformacjiOUtrudnieniach() {
	throw "Not yet implemented";
}

