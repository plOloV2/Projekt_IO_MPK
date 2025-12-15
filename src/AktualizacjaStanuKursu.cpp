#include <exception>
#include <iostream>
using namespace std;

#include "AktualizacjaStanuKursu.hpp"
#include "AbsStrategiaAktualizacjiStanuKursu.hpp"
#include "Model.hpp"
#include "ZgloszenieRozpoczecia.hpp"
#include "ZgloszenieZakonczenia.hpp"
#include "ZgloszenieIncydentu.hpp"

Kontroler::AktualizacjaStanuKursu::AktualizacjaStanuKursu(Model::AbsModel* pModel, int pIdKierowcy) {
	cout << "Aktualizowanie statusu kursu\n";
	this->_absModel = pModel;
	this->_idKierowcy = pIdKierowcy;
	int idKursu = wprowadzenieIdKursu();
	string kurs = _absModel->znalezienieKursu(idKursu);
	if(kurs != ""){
		wyborOpcji();
		_strategiaAktualizacjiStanuKursu->zakonczenieAktualizacjiKursu(_absModel, _idKierowcy, idKursu);
	}
	cout << "Stan kursu zostal zaktualizowany\n";
}

int Kontroler::AktualizacjaStanuKursu::wprowadzenieIdKursu() {
	int idKursu;
	cout << "\nPodaj ID Kursu: ";
	cin >> idKursu;
	return idKursu;
}

void Kontroler::AktualizacjaStanuKursu::wyborOpcji() {
	int opcja;
	cout << "\nWybierz opcję:\n";
	cout << "1. Rozpocznij kurs\n";
	cout << "2. Zakoncz kurs\n";
	cout << "3. Zglos incydent\n";
	cin >> opcja;
	if(opcja == 1){
		_strategiaAktualizacjiStanuKursu = new ZgloszenieRozpoczecia();
	}
	else if(opcja == 2){
		_strategiaAktualizacjiStanuKursu = new ZgloszenieZakonczenia();
	}
	else{
		_strategiaAktualizacjiStanuKursu = new ZgloszenieIncydentu();
	}
}

