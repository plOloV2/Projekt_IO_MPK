#include <exception>
using namespace std;

#include "KontrolerKierowcy.hpp"
#include "AbsModel.hpp"
#include "AbsKontrolerKierowcy.hpp"
#include "AktualizacjaStanuKursu.hpp"

Kontroler::KontrolerKierowcy::KontrolerKierowcy(Model::AbsModel pModel) {
}

void Kontroler::KontrolerKierowcy::aktualizacjaStanuKursu() {
	int idKierowcy = 0;
	AktualizacjaStanuKursu aktualizacjaStanuKursu = AktualizacjaStanuKursu(_absModel, idKierowcy);
}

void Kontroler::KontrolerKierowcy::odbiorInformacjiOGodzinachPrzyjazdow() {
	throw "Not yet implemented";
}

