#include <exception>
#include <vector>
#include <sstream>
#include <iostream>
#include <string>

#include "ModyfikowanieRozkladuJazdy.hpp"
#include "AbsModel.hpp"

using namespace std;

// Split string by delimiter
vector<string> split(const string& s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);

    while(getline(tokenStream, token, delimiter))
        tokens.push_back(token);

    return tokens;

}

// Parse "1,2,3" into vector<int>
vector<int> parsePrzystanki(const string& stopsStr) {
    vector<int> result;
    if (stopsStr.empty()) return result;
    
    vector<string> items = split(stopsStr, ',');
    for(const auto& item : items){

        try {

            result.push_back(stoi(item));

        } catch (...) { continue; }
		
    }

    return result;

}

// Parse "08:00,08:15" into vector<string>
vector<string> parseCzasy(const string& timesStr) {
    if (timesStr.empty()) return {};
    return split(timesStr, ',');
}

void Kontroler::ModyfikowanieRozkladuJazdy::modyfikowanieRozkladuJazdy(Model::AbsModel* pModel, int pIdKursu) {

    string kurs = pModel->znalezienieKursu(pIdKursu);

    if(kurs == ""){
        throw "Brak kursu o podanym ID";
        return;
    }

    // Extract ID and DriverID immediately to preserve them throughout edits
    vector<string> initialParts = split(kurs, ';');
    if (initialParts.size() < 3) throw "Invalid data format";

    string currentId = initialParts[0];
    string currentDriverId = (initialParts.size() > 3) ? initialParts[3] : "";

    do {
        wyswietlTrase(kurs);

        // 1. Modify Stops (Merged logic)
        vector<int> wszystkiePrzystanki = modyfikacjaListyPrzystankow(kurs);

        // 2. Modify Times
        vector<string> godzinyPrzyjazdow = modyfikacjaGodzinPrzyjazdow(kurs);

        // 3. Rebuild the string
        kurs = wprowadzZmiany(currentId, wszystkiePrzystanki, godzinyPrzyjazdow, currentDriverId);

    } while(!sprawdzeniePoprawnosciKursu(kurs));

    pModel->modyfikowanieKursu(kurs);
}

void Kontroler::ModyfikowanieRozkladuJazdy::wyswietlTrase(string kurs) {
    std::cout << "Obecny kurs: " << kurs << std::endl;
}

// Merged Function: Parses current stops and adds new ones
vector<int> Kontroler::ModyfikowanieRozkladuJazdy::modyfikacjaListyPrzystankow(string kurs) {

    vector<int> przystanki;
    
    // Parse existing stops from the string
    vector<string> sections = split(kurs, ';');
    if(sections.size() >= 2) {
        przystanki = parsePrzystanki(sections[1]);
    }

    przystanki.push_back(3);
    przystanki.push_back(5);
    przystanki.push_back(6);
    przystanki.push_back(21);

    return przystanki;
}

vector<string> Kontroler::ModyfikowanieRozkladuJazdy::modyfikacjaGodzinPrzyjazdow(string kurs) {

    vector<string> sections = split(kurs, ';');
    vector<string> czasy;

    // Parse existing times
    if(sections.size() >= 3) {
        czasy = parseCzasy(sections[2]);
    }

    czasy.push_back("10:00");
    czasy.push_back("10:15");
    czasy.push_back("10:30");
    czasy.push_back("10:45");
    
    return czasy;
}

string Kontroler::ModyfikowanieRozkladuJazdy::wprowadzZmiany(string id, vector<int> wszystkiePrzystanki, vector<string> godzinyPrzyjazdow, string driverId) {

    // Simple validation
    if(wszystkiePrzystanki.size() != godzinyPrzyjazdow.size()) {
        throw "Nie zgodna liczba przystankow i godzin przyjazdow";
    }

    stringstream ss;

    // 1. ID
    ss << id << ";";

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
    if(!driverId.empty()) {
        ss << ";" << driverId;
    }

    return ss.str();
}

bool Kontroler::ModyfikowanieRozkladuJazdy::sprawdzeniePoprawnosciKursu(string kurs) {
    if(kurs == "") return false;

    vector<string> sections = split(kurs, ';');
    
    // Must have at least ID, Stops, Times
    if(sections.size() < 3) return false;

    // Further validation: check if stops count matches times count
    vector<int> s = parsePrzystanki(sections[1]);
    vector<string> t = parseCzasy(sections[2]);

    if(s.size() != t.size()) return false;

    return true;
}
