#include <exception>
#include <vector>
#include <sstream>
#include <iostream>
#include <string>

#include "ModyfikowanieRozkladuJazdy.hpp"
#include "AbsModel.hpp"

using namespace std;

vector<string> Kontroler::ModyfikowanieRozkladuJazdy::podzielString(string dane, char dzielnik) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(dane);

    while(getline(tokenStream, token, dzielnik))
        tokens.push_back(token);

    return tokens;

}

vector<int> Kontroler::ModyfikowanieRozkladuJazdy::parsePrzystanki(string dane) {
    vector<int> result;
    if (dane.empty()) return result;
    
    vector<string> items = podzielString(dane, ',');
    for(const auto& item : items){

        try {

            result.push_back(stoi(item));

        } catch (...) { continue; }
		
    }

    return result;

}

vector<string> Kontroler::ModyfikowanieRozkladuJazdy::parseCzasy(string dane) {
    if (dane.empty()) return {};
    return podzielString(dane, ',');
}

void Kontroler::ModyfikowanieRozkladuJazdy::modyfikowanieRozkladuJazdy(Model::AbsModel* pModel, int pIdKursu) {

    string Kurs = pModel->znalezienieKursu(pIdKursu);

    if(Kurs == ""){
        throw "Brak Kursu o podanym ID";
        return;
    }

    vector<string> fragmenty = podzielString(Kurs, ';');
    if (fragmenty.size() < 3) throw "Invalid data format";

    string currentDriverId = (fragmenty.size() > 3) ? fragmenty[3] : "";

    do {
        
        wyswietlTrase(Kurs);

        vector<int> wszystkiePrzystanki = modyfikacjaListyPrzystankow(Kurs);

        vector<string> godzinyPrzyjazdow = modyfikacjaGodzinPrzyjazdow(Kurs);

        Kurs = wprowadzZmiany(fragmenty[0], wszystkiePrzystanki, godzinyPrzyjazdow, currentDriverId);

    } while(!sprawdzeniePoprawnosciKursu(Kurs));

    pModel->modyfikowanieKursu(Kurs);

}

void Kontroler::ModyfikowanieRozkladuJazdy::wyswietlTrase(string Kurs) {
    std::cout << "Obecny Kurs: " << Kurs << std::endl;
}

vector<int> Kontroler::ModyfikowanieRozkladuJazdy::modyfikacjaListyPrzystankow(string Kurs) {

    vector<int> przystanki;
    
    vector<string> sekcje = podzielString(Kurs, ';');
    if(sekcje.size() >= 2) {
        przystanki = parsePrzystanki(sekcje[1]);
    }

    przystanki.push_back(3);
    przystanki.push_back(5);
    przystanki.push_back(6);
    przystanki.push_back(21);

    return przystanki;
}

vector<string> Kontroler::ModyfikowanieRozkladuJazdy::modyfikacjaGodzinPrzyjazdow(string Kurs) {

    vector<string> sekcje = podzielString(Kurs, ';');
    vector<string> czasy;

    if(sekcje.size() >= 3) {
        czasy = parseCzasy(sekcje[2]);
    }

    czasy.push_back("10:00");
    czasy.push_back("10:15");
    czasy.push_back("10:30");
    czasy.push_back("10:45");
    
    return czasy;
}

string Kontroler::ModyfikowanieRozkladuJazdy::wprowadzZmiany(string IdKursu, vector<int> wszystkiePrzystanki, vector<string> godzinyPrzyjazdow, string IdKierowcy) {

    if(wszystkiePrzystanki.size() != godzinyPrzyjazdow.size()) {
        throw "Nie zgodna liczba przystankow i godzin przyjazdow";
    }

    stringstream ss;

    ss << IdKursu << ";";

    for(size_t i = 0; i < wszystkiePrzystanki.size(); i++) {
        ss << wszystkiePrzystanki[i];
        if(i < wszystkiePrzystanki.size() - 1) ss << ",";
    }
    ss << ";";

    for(size_t i = 0; i < godzinyPrzyjazdow.size(); i++) {
        ss << godzinyPrzyjazdow[i];
        if(i < godzinyPrzyjazdow.size() - 1) ss << ",";
    }

    if(!IdKierowcy.empty()) {
        ss << ";" << IdKierowcy;
    }

    return ss.str();
}

bool Kontroler::ModyfikowanieRozkladuJazdy::sprawdzeniePoprawnosciKursu(string Kurs) {
    if(Kurs == "") return false;

    vector<string> sekcje = podzielString(Kurs, ';');
    
    if(sekcje.size() < 3) return false;

    vector<int> przystanki = parsePrzystanki(sekcje[1]);
    vector<string> czasy = parseCzasy(sekcje[2]);

    if(przystanki.size() != czasy.size()) return false;

    return true;
}
