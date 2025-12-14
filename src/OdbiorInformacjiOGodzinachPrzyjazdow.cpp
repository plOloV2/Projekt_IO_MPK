#include <exception>
#include <sstream>
#include <algorithm>
#include <iostream>
using namespace std;

#include "OdbiorInformacjiOGodzinachPrzyjazdow.hpp"
#include "AbsModel.hpp"

Kontroler::OdbiorInformacjiOGodzinachPrzyjazdow::OdbiorInformacjiOGodzinachPrzyjazdow(Model::AbsModel* pModel) {
	this->_absModel = pModel;
}

void Kontroler::OdbiorInformacjiOGodzinachPrzyjazdow::odbiorInformacjiOGodzinachPrzyjazdow(int pIdKursu) {
	string opisKursu = _absModel->znalezienieKursu(pIdKursu);
	vector<string> atrybutyKursu;
	stringstream streamKursu(opisKursu);
	string helper;
	while(getline(streamKursu, helper, ';')){
		atrybutyKursu.push_back(helper);
	}
	vector<string> listaIdPrzystankow;
	stringstream streamId(atrybutyKursu.at(1));
	while(getline(streamId, helper, ',')){
		atrybutyKursu.push_back(helper);
	}
	vector<string> listaGodzinPrzyjazdow;
	stringstream streamGodzin(atrybutyKursu.at(2));
	while(getline(streamGodzin, helper, ',')){
		atrybutyKursu.push_back(helper);
	}
	for(int i = 0; i < listaIdPrzystankow.size(); i++){
		cout << "Przystanek " << listaIdPrzystankow.at(i) << ": " << listaGodzinPrzyjazdow.at(i) << endl;
	}
}

void Kontroler::OdbiorInformacjiOGodzinachPrzyjazdow::odbiorInformacjiOGodzinachPrzyjazdow2(int pIdPrzystanku) {
	vector<string> opisyKursow = _absModel->znajdzGodzinyPrzyjazdow(pIdPrzystanku);
	for(int i = 0; i < opisyKursow.size(); i++){
		vector<string> atrybutyKursu;
		stringstream streamKursu(opisyKursow.at(i));
		string helper;
		while(getline(streamKursu, helper, ';')){
			atrybutyKursu.push_back(helper);
		}
		vector<string> listaIdPrzystankow;
		stringstream streamId(atrybutyKursu.at(1));
		while(getline(streamId, helper, ',')){
			atrybutyKursu.push_back(helper);
		}
		vector<string> listaGodzinPrzyjazdow;
		stringstream streamGodzin(atrybutyKursu.at(2));
		while(getline(streamGodzin, helper, ',')){
			atrybutyKursu.push_back(helper);
		}
		auto iterator = find(listaIdPrzystankow.begin(), listaIdPrzystankow.end(), to_string(pIdPrzystanku));
		cout << "Kurs " << atrybutyKursu.at(0) << ": " << listaGodzinPrzyjazdow.at(distance(listaIdPrzystankow.begin(), iterator)) << endl;
	}
}

