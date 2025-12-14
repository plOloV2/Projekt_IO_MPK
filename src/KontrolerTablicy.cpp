#include <exception>
using namespace std;

#include "KontrolerTablicy.hpp"
#include "AbsModel.hpp"
#include "AbsKontrolerTablicy.hpp"
#include "OdbiorInformacjiOGodzinachPrzyjazdow.hpp"

Kontroler::KontrolerTablicy::KontrolerTablicy(Model::AbsModel* pModel) {
	this->_absModel = pModel;
}

void Kontroler::KontrolerTablicy::odbiorInformacjiOGodzinachPrzyjazdow() {
	int idPrzystanku = 0;
	OdbiorInformacjiOGodzinachPrzyjazdow oiogp = OdbiorInformacjiOGodzinachPrzyjazdow(_absModel);
	oiogp.odbiorInformacjiOGodzinachPrzyjazdow2(idPrzystanku);
}

