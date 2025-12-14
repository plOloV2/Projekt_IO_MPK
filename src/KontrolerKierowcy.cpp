#include <exception>
#include <iostream>
using namespace std;

#include "KontrolerKierowcy.hpp"
#include "AbsModel.hpp"
#include "AbsKontrolerKierowcy.hpp"
#include "AktualizacjaStanuKursu.hpp"
#include "OdbiorInformacjiOGodzinachPrzyjazdow.hpp"

Kontroler::KontrolerKierowcy::KontrolerKierowcy(Model::AbsModel *pModel) {
	this->_absModel = pModel;
}

void Kontroler::KontrolerKierowcy::aktualizacjaStanuKursu() {
	int idKierowcy = 0;
	AktualizacjaStanuKursu aktualizacjaStanuKursu = AktualizacjaStanuKursu(_absModel, idKierowcy);
}

void Kontroler::KontrolerKierowcy::odbiorInformacjiOGodzinachPrzyjazdow() {
	int idKursu = 0;
	OdbiorInformacjiOGodzinachPrzyjazdow oiogp = OdbiorInformacjiOGodzinachPrzyjazdow(_absModel);
	oiogp.odbiorInformacjiOGodzinachPrzyjazdow(idKursu);
}

