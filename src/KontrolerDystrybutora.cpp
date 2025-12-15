#include <exception>
#include <iostream>
using namespace std;

#include "KontrolerDystrybutora.hpp"
#include "AbsModel.hpp"
#include "AbsKontrolerDystrybutora.hpp"
#include "ModyfikowanieRozkladuJazdy.hpp"

Kontroler::KontrolerDystrybutora::KontrolerDystrybutora(Model::AbsModel* pModel) {
	this->_absModel = pModel;
}

void Kontroler::KontrolerDystrybutora::modyfikowanieRozkladuJazdy() {

	int idKursu = 0;

	std::cout<<"Podaj id kursu do modyfikacji: ";
	std::cin>>idKursu;

	ModyfikowanieRozkladuJazdy mrj =  ModyfikowanieRozkladuJazdy();
	mrj.modyfikowanieRozkladuJazdy(_absModel, idKursu);
	
}

void Kontroler::KontrolerDystrybutora::wysylanieInformacjiOUtrudnieniach() {
	throw "Not yet implemented";
}

