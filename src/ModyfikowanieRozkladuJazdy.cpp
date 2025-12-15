#include <exception>
#include <vector>
#include <sstream>
#include <iostream>
#include <string>

#include "ModyfikowanieRozkladuJazdy.hpp"
#include "AbsModel.hpp"

using namespace std;

// Split string by delimiter
vector<string> Kontroler::ModyfikowanieRozkladuJazdy::podzielString(string dane, char dzielnik) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(dane);

    while(getline(tokenStream, token, dzielnik))
        tokens.push_back(token);

    return tokens;

}

// Parse "1,2,3" into vector<int>
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

// Parse "08:00,08:15" into vector<string>
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

    // Extract ID and DriverID immediately to preserve them throughout edits
    vector<string> fragmenty = podzielString(Kurs, ';');
    if (fragmenty.size() < 3) throw "Invalid data format";

    string currentDriverId = (fragmenty.size() > 3) ? fragmenty[3] : "";

    do {
        
        wyswietlTrase(Kurs);

        // 1. Modify Stops (Merged logic)
        vector<int> wszystkiePrzystanki = modyfikacjaListyPrzystankow(Kurs);

        // 2. Modify Times
        vector<string> godzinyPrzyjazdow = modyfikacjaGodzinPrzyjazdow(Kurs);

        // 3. Rebuild the string
        Kurs = wprowadzZmiany(fragmenty[0], wszystkiePrzystanki, godzinyPrzyjazdow, currentDriverId);

    } while(!sprawdzeniePoprawnosciKursu(Kurs));

    pModel->modyfikowanieKursu(Kurs);

}

void Kontroler::ModyfikowanieRozkladuJazdy::wyswietlTrase(string Kurs) {
    std::cout << "Obecny Kurs: " << Kurs << std::endl;
}

// Merged Function: Parses current stops and adds new ones
vector<int> Kontroler::ModyfikowanieRozkladuJazdy::modyfikacjaListyPrzystankow(string Kurs) {

    vector<int> przystanki;
    
    // Parse existing stops from the string
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

    // Parse existing times
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

    // Simple validation
    if(wszystkiePrzystanki.size() != godzinyPrzyjazdow.size()) {
        throw "Nie zgodna liczba przystankow i godzin przyjazdow";
    }

    stringstream ss;

    // 1. ID
    ss << IdKursu << ";";

    // 2. Stops
    for(size_t i = 0; i < wszystkiePrzystanki.size(); i++) {
        ss << wszystkiePrzystanki[i];
        if(i < wszystkiePrzystanki.size() - 1) ss << ",";
    }
    ss << ";";

    // 3. Times
    for(size_t i = 0; i < godzinyPrzyjazdow.size(); i++) {
        ss << godzinyPrzyjazdow[i];
        if(i < godzinyPrzyjazdow.size() - 1) ss << ",";
    }

    // 4. Driver ID (if exists)
    if(!IdKierowcy.empty()) {
        ss << ";" << IdKierowcy;
    }

    return ss.str();
}

bool Kontroler::ModyfikowanieRozkladuJazdy::sprawdzeniePoprawnosciKursu(string Kurs) {
    if(Kurs == "") return false;

    vector<string> sekcje = podzielString(Kurs, ';');
    
    // Must have at least ID, Stops, Times
    if(sekcje.size() < 3) return false;

    // Further validation: check if stops count matches times count
    vector<int> przystanki = parsePrzystanki(sekcje[1]);
    vector<string> czasy = parseCzasy(sekcje[2]);

    if(przystanki.size() != czasy.size()) return false;

    return true;
}
