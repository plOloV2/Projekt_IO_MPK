#include <exception>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

#include "Inwentarz.hpp"
#include "AbsDAO.hpp"
#include "Kierowca.hpp"
#include "Powiadomienie.hpp"
#include "AbsKurs.hpp"
#include "Incydent.hpp"
#include "Kurs.hpp"
#include "KursRozpoczety.hpp"
#include "Kierowca.hpp"

Model::Inwentarz::Inwentarz() {
}

Model::Inwentarz::Inwentarz(AbsDAO* pDao) {
	this->_dao = pDao;
}

void Model::Inwentarz::modyfikujKurs(string pKurs) {
	_dao->edytujKurs(pKurs);
}

Model::Kurs Model::Inwentarz::dajKurs(int pIdKursu) {
	vector<string> atrybutyKursu;
	string opisKursu = _dao->znajdzKurs(pIdKursu);
	stringstream kursStream(opisKursu);
	string helper;
	while(getline(kursStream, helper, ';')) {
		atrybutyKursu.push_back(helper);
	}
	vector<int> listaId;
	stringstream idStream(atrybutyKursu.at(1));
	while(getline(idStream, helper, ';')) {
		listaId.push_back(stoi(helper));
	}
	vector<string> listaGodzin;
	stringstream godzinyStream(atrybutyKursu.at(1));
	while(getline(godzinyStream, helper, ';')) {
		listaGodzin.push_back(helper);
	}
	Kurs kurs(stoi(atrybutyKursu.at(0)), listaId, listaGodzin);
	return kurs;
}

Model::Kierowca Model::Inwentarz::dajKierowce(int pIdKierowcy) {
	vector<int> atrybutyKierowcy;
	string opisKierowcy = _dao->znajdzKierowce(pIdKierowcy);
	stringstream kierowcaStream(opisKierowcy);
	string helper;
	while(getline(kierowcaStream, helper, ';')) {
		atrybutyKierowcy.push_back(stoi(helper));
	}
	Kierowca kierowca(atrybutyKierowcy.at(0), atrybutyKierowcy.at(1));
	return kierowca;
}

void Model::Inwentarz::modyfikujKierowce(int pIdKierowcy, int pIdKursu) {
	_dao->edytujKierowce(pIdKierowcy, pIdKursu);
}

vector<Model::Kierowca> Model::Inwentarz::dajKierowcow(int pIdKursu) {
	vector<Kierowca> kierowcy;
	vector<string> opisyKierowcow = _dao->znajdzKierowcow(pIdKursu);
	for(int i = 0; i < opisyKierowcow.size(); i++){	
		vector<int> atrybutyKierowcy;
		stringstream kierowcaStream(opisyKierowcow.at(i));
		string helper;
		while(getline(kierowcaStream, helper, ';')) {
			atrybutyKierowcy.push_back(stoi(helper));
		}
		Kierowca kierowca(atrybutyKierowcy.at(0), atrybutyKierowcy.at(1));
		kierowcy.push_back(kierowca);
	}
	return kierowcy;
}

void Model::Inwentarz::dodajPowiadomienie(vector<int> pIdKierowcow , string pPowiadmienie) {
	_dao->dodajPowiadomienie(pIdKierowcow, pPowiadmienie);
}

void Model::Inwentarz::dodajIncydent(string pIncydent) {
	_dao->dodajIncydent(pIncydent);
}

vector<Model::Kurs> Model::Inwentarz::dajGodzinyPrzyjazdow(int pIdPrzystanku) {
	vector<Model::Kurs> godzinyPrzyjazdow;
	_dao->znajdzKursy(pIdPrzystanku);
	return godzinyPrzyjazdow;
}

Model::KursRozpoczety Model::Inwentarz::dajKursRozpoczety(int pIdKursu) {
	vector<string> atrybutyKursu;
	string opisKursu = _dao->znajdzKurs(pIdKursu);
	stringstream kursStream(opisKursu);
	string helper;
	while(getline(kursStream, helper, ';')) {
		atrybutyKursu.push_back(helper);
	}
	vector<int> listaId;
	stringstream idStream(atrybutyKursu.at(1));
	while(getline(idStream, helper, ';')) {
		listaId.push_back(stoi(helper));
	}
	vector<string> listaGodzin;
	stringstream godzinyStream(atrybutyKursu.at(1));
	while(getline(godzinyStream, helper, ';')) {
		listaGodzin.push_back(helper);
	}
	Kurs* kurs = new Kurs(stoi(atrybutyKursu.at(0)), listaId, listaGodzin);
	if(atrybutyKursu.size() == 4){
		KursRozpoczety kursRozpoczety(kurs, stoi(atrybutyKursu.at(3)));
		return kursRozpoczety;
	}
	else{
		KursRozpoczety kursRozpoczety(kurs, -1);
		return kursRozpoczety;
	}
}