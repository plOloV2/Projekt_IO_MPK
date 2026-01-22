#ifndef __MockAbsModel_hpp__
#define __MockAbsModel_hpp__

#include "gmock/gmock.h"
#include "../inc/AbsModel.hpp"

namespace Model {

    class MockAbsModel : public AbsModel {
        public:
            // Metody wymagane przez logikę ModyfikowanieRozkladuJazdy
            MOCK_METHOD(string, znalezienieKursu, (int pIdKursu), (override));
            MOCK_METHOD(void, modyfikowanieKursu, (string pKurs), (override));

            // Pozostałe metody
            MOCK_METHOD(void, dodawanieKursu, (), (override));
            MOCK_METHOD(string, znalezienieKierowcy, (int pIdKierowcy), (override));
            MOCK_METHOD(void, modyfikacjaKierowcy, (int pIdKierowcy, int pIdKursu), (override));
            MOCK_METHOD(string*, znalezienieKierowcow, (int pIdKursow), (override));
            MOCK_METHOD(void, wyslaniePowiadomien, (vector<int> pIdKierowcow , string pPowiadomienie), (override));
            MOCK_METHOD(void, zglaszenieIncydentu, (string pIncydent), (override));
            MOCK_METHOD(vector<string>, znajdzGodzinyPrzyjazdow, (int pIdPrzystanku), (override));
            MOCK_METHOD(void, zarejestrowanieZdarzenia, (string pZdarzenie), (override));
            MOCK_METHOD(string, znalezienieKursuRozpoczetego, (int pIdKursu), (override));
    };

}

#endif
