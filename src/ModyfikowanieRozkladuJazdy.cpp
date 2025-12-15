#include <exception>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

#include "ModyfikowanieRozkladuJazdy.hpp"
#include "AbsModel.hpp"

vector<int> parseKurs(const string kurs, bool selectFirst) {

    vector<int> result;
    stringstream ss(kurs);
    string line;

    while(getline(ss, line)){

        stringstream lineStream(line);
        int first, second;
        char dash; 

        if(lineStream >> first >> dash >> second){

            if(selectFirst){

                result.push_back(first);

            }else {

                result.push_back(second);

            }

        }

    }

    return result;

}

void Kontroler::ModyfikowanieRozkladuJazdy::modyfikowanieRozkladuJazdy(Model::AbsModel* pModel, int pIdKursu) {

	string kurs = pModel->znalezienieKursu(pIdKursu);

	if(kurs == ""){
		throw "Brak kursu o podanym ID";
		return;
	}

	do{

		wyswietlTrase(kurs);

		vector<int> przystankiKoncowe = edycjaPrzystankowKoncowych(kurs);
		
		vector<int> wszystkiePrzystanki = modyfikacjaListyPrzystankow(przystankiKoncowe);

		vector<int> godzinyPrzyjazdow = modyfikacjaGodzinPrzyjazdow(kurs);

		kurs = wprowadzZmiany(wszystkiePrzystanki, godzinyPrzyjazdow);


	}while(!sprawdzeniePoprawnosciKursu(kurs));

	pModel->modyfikowanieKursu(kurs);

}

vector<int> Kontroler::ModyfikowanieRozkladuJazdy::edycjaPrzystankowKoncowych(string kurs) {

	vector<int> przystankiKon = parseKurs(kurs, true);

	przystankiKon.push_back(3);
	przystankiKon.push_back(5);

	return przystankiKon;

}

void Kontroler::ModyfikowanieRozkladuJazdy::wyswietlTrase(string kurs) {
	std::cout<<kurs<<std::endl;
}

vector<int> Kontroler::ModyfikowanieRozkladuJazdy::modyfikacjaListyPrzystankow(vector<int> przystankiKoncowe) {

	przystankiKoncowe.push_back(6);
	przystankiKoncowe.push_back(21);

	return przystankiKoncowe;
}

vector<int> Kontroler::ModyfikowanieRozkladuJazdy::modyfikacjaGodzinPrzyjazdow(string kurs) {

	vector<int> godzinyPrzyjazdow = parseKurs(kurs, false);

	godzinyPrzyjazdow.push_back(4);
	godzinyPrzyjazdow.push_back(5);
	godzinyPrzyjazdow.push_back(22);
	godzinyPrzyjazdow.push_back(55);

	return godzinyPrzyjazdow;

}

string Kontroler::ModyfikowanieRozkladuJazdy::wprowadzZmiany(vector<int> wszystkiePrzystanki, vector<int> godzinyPrzyjazdow) {

	if(wszystkiePrzystanki.size() != godzinyPrzyjazdow.size())
		return "";

	string nowyKurs = "";

	for(int i = 0; i < wszystkiePrzystanki.size(); i++)
		nowyKurs += to_string(wszystkiePrzystanki[i]) + " - " + to_string(godzinyPrzyjazdow[i]) + "\n";

	return nowyKurs;

}

bool Kontroler::ModyfikowanieRozkladuJazdy::sprawdzeniePoprawnosciKursu(string kurs) {

	if(kurs == "")
		return false;

	return true;

}
