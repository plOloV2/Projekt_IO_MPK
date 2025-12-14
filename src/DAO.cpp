#include <exception>
#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

#include "DAO.hpp"
#include "AbsDAO.hpp"

Model::DAO::DAO() {
	_bazaKierowcow[1] = "1;-1;";
	_bazaKierowcow[2] = "2;1;";
	_bazaKierowcow[3] = "3;-1;";
	_bazaKierowcow[4] = "4;3;";
	_bazaKierowcow[5] = "5;5;";
	_ostatniNrKierowcy = 5;
	_bazaKursow[1] = "1;1,2;10:00,11:00;1;";
	_bazaKursow[2] = "2;2,3,4;10:30,10:45,11:00;";
	_bazaKursow[3] = "3;4,1;12:00,13:00;4;";
	_bazaKursow[4] = "4;1,5;12:00,12:30;";
	_bazaKursow[5] = "5;2,3,5;10:00,11:00,12:00;5;";
	_ostatniNrKursu = 5;
	_bazaIncydentow[1] = "0;Silnik nie dziala;";
	_bazaIncydentow[2] = "1;Wykoleilem sie;";
	_bazaIncydentow[3] = "2;Potracilem kogos;";
	_bazaIncydentow[4] = "1;Zderzylem sie z tramwajem;";
	_bazaIncydentow[5] = "3;Droga jest zablokowana;";
	_ostatniNrIncydentu = 5;
	_bazaPowiadomien[1] = "1,3;0;Omijaj przystanek 1;";
	_bazaPowiadomien[2] = "1,2,5;1;Omijaj przystanek 2;";
	_bazaPowiadomien[3] = "2,5;2;Omijaj przystanek 3;";
	_bazaPowiadomien[4] = "2,3;1;Omijaj przystanek 4;";
	_bazaPowiadomien[5] = "4,5;3;Omijaj przystanek 5;";
	_ostatniNrPowiadomienia = 5;
}

void Model::DAO::dodajWpisDoRejestru(string pZdarzenie) {
	throw "Not yet implemented";
}

int Model::DAO::dodajKurs(string pKurs) {
	_ostatniNrKursu++;
	_bazaKursow[_ostatniNrKursu] = pKurs;
}

void Model::DAO::edytujKurs(string pKurs) {
	stringstream kursStream(pKurs);
	string idKursu;
	getline(kursStream, idKursu, ';');
	if(stoi(idKursu) <= _ostatniNrKursu){
		_bazaKursow[stoi(idKursu)] = pKurs;
	}
}

string Model::DAO::znajdzKurs(int pIdKursu) {
	if(pIdKursu <= _ostatniNrKursu){
		return _bazaKursow[pIdKursu];
	}
	else{
		return "Brak";
	}
}

void Model::DAO::edytujKierowce(int pIdKierowcy, int pIdKursu) {
	if(pIdKierowcy <= _ostatniNrKierowcy){
		string kierowca = to_string(pIdKierowcy) + ';' + to_string(pIdKursu) + ';';
		_bazaKierowcow[pIdKierowcy] = kierowca;
	}
}

string Model::DAO::znajdzKierowce(int pIdKierowcy) {
	if(pIdKierowcy <= _ostatniNrKierowcy){
		return _bazaKierowcow[pIdKierowcy];
	}
	else{
		return "Brak";
	}
}

vector<string> Model::DAO::znajdzKierowcow(int pIdKursu) {
	vector<string> kierowcy;
	for(int i = 0; i <= _ostatniNrKierowcy; i++){
		vector<int> kierowca;
		stringstream kursStream(_bazaKierowcow[i]);
		string helper;
		while(getline(kursStream, helper, ';')){
			kierowca.push_back(stoi(helper));
		}
		if(kierowca.at(1) == pIdKursu){
			kierowcy.push_back(_bazaKierowcow[i]);
		}
	}
	return kierowcy;
}

void Model::DAO::dodajPowiadomienie(vector<int> pIdKierowcow , string pPowiadomienie) {
	_ostatniNrPowiadomienia++;
	string powiadomienie;
	for(int i = 0; i < pIdKierowcow.size(); i++){
		powiadomienie = powiadomienie + to_string(pIdKierowcow.at(i));
		if(i < pIdKierowcow.size() - 1){
			powiadomienie = powiadomienie + ',';
		}
	}
	powiadomienie = powiadomienie + ';' + pPowiadomienie + ';';
	_bazaPowiadomien[_ostatniNrPowiadomienia] = powiadomienie;
}

vector<string> Model::DAO::znajdzPowiadomienia(int pIdKierowcy) {
	vector<string> powiadomienia;
	for(int i = 0; i <= _ostatniNrPowiadomienia; i++){
		vector<string> powiadomienie;
		stringstream powiadomienieStream(_bazaPowiadomien[i]);
		string helper;
		while(getline(powiadomienieStream, helper, ';')){
			powiadomienie.push_back(helper);
		}
		vector<int> idKierowcow;
		stringstream idStream(powiadomienie.at(0));
		string helper;
		while(getline(idStream, helper, ',')){
			idKierowcow.push_back(stoi(helper));
		}
		for(int j = 0; j < idKierowcow.size(); j++){
			if(idKierowcow.at(j) == pIdKierowcy) {
				powiadomienia.push_back(_bazaPowiadomien[i]);
				break;
			}
		}
	}
	return powiadomienia;
}

void Model::DAO::dodajIncydent(string pIncydent) {
	_ostatniNrIncydentu++;
	_bazaIncydentow[_ostatniNrIncydentu] = pIncydent;
}

vector<string> Model::DAO::znajdzIncydenty() {
	vector<string> incydenty;
	for(int i = 0; i <= _ostatniNrIncydentu; i++){
		incydenty.push_back(_bazaIncydentow[i]);
	}
	return incydenty;
}

void Model::DAO::dodajWpisDoRejestruZdarzen(string pZdarzenie) {
	throw "Not yet implemented";
}

