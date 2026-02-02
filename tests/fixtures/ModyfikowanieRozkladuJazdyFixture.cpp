#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <cstring>
#include <cstdlib>

#include "CSlim/Slim.h"
#include "CSlim/Fixtures.h"
#include "CSlim/SlimList.h"
#include "CSlim/StatementExecutor.h"

#include "AbsModel.hpp"
#include "ModyfikowanieRozkladuJazdy.hpp"

// Mock Model
class FakeModel : public Model::AbsModel {
public:
    std::map<int, std::string> bazaKursow;

    void ustawKursTestowy(int id, std::string dane) {
        bazaKursow[id] = dane;
    }

    std::string znalezienieKursu(int pIdKursu) override {
        if (bazaKursow.find(pIdKursu) != bazaKursow.end()) {
            return bazaKursow[pIdKursu];
        }
        return "";
    }

    void modyfikowanieKursu(std::string pKurs) override {
        std::stringstream ss(pKurs);
        std::string segment;
        if(std::getline(ss, segment, ';')) {
            try {
                int id = std::stoi(segment);
                bazaKursow[id] = pKurs;
            } catch (...) {}
        }
    }

    // Zaślepki
    void dodawanieKursu() override {}
    std::string znalezienieKierowcy(int) override { return ""; }
    void modyfikacjaKierowcy(int, int) override {}
    std::string* znalezienieKierowcow(int) override { return nullptr; }
    void wyslaniePowiadomien(std::vector<int>, std::string) override {}
    void zglaszenieIncydentu(std::string) override {}
    std::vector<std::string> znajdzGodzinyPrzyjazdow(int) override { return {}; }
    void zarejestrowanieZdarzenia(std::string) override {}
    std::string znalezienieKursuRozpoczetego(int) override { return ""; }
};

// --- Zmienne globalne ---
static FakeModel* fakeModel = nullptr;
static Kontroler::ModyfikowanieRozkladuJazdy* kontroler = nullptr;

static int inputIdKursu = 0;
static char inputDaneKursu[512];

extern "C" {

    // Konstruktor
    void* ModyfikujRozklad_Create(StatementExecutor* executor, SlimList* args) {
        if (fakeModel == nullptr) fakeModel = new FakeModel();
        if (kontroler == nullptr) kontroler = new Kontroler::ModyfikowanieRozkladuJazdy();
        
        inputIdKursu = 0;
        memset(inputDaneKursu, 0, sizeof(inputDaneKursu));
        
        return fakeModel;
    }

    void ModyfikujRozklad_Destroy(void* self) {
    }

    // Setter: id kursu
    const char* ModyfikujRozklad_setIdKursu(void* self, SlimList* args) {
        // Pobieramy pierwszy argument jako string i konwertujemy na int
        const char* arg = SlimList_GetStringAt(args, 0);
        inputIdKursu = atoi(arg);
        return ""; // Zwracamy pusty string (void w fitnesse)
    }

    // Setter: obecny kurs
    const char* ModyfikujRozklad_setObecnyKurs(void* self, SlimList* args) {
        const char* arg = SlimList_GetStringAt(args, 0);
        strcpy(inputDaneKursu, arg);
        // Aktualizujemy fake model
        fakeModel->ustawKursTestowy(inputIdKursu, std::string(inputDaneKursu));
        return "";
    }

    // Action: wykonaj
    const char* ModyfikujRozklad_wykonajModyfikacje(void* self, SlimList* args) {
        try {
            kontroler->modyfikowanieRozkladuJazdy(fakeModel, inputIdKursu);
        } catch (const char* msg) {
            std::cout << "Wyjatek: " << msg << std::endl;
        } catch (...) {
            std::cout << "Nieznany wyjatek" << std::endl;
        }
        return "";
    }

    // Getter: kurs po zmianie
    const char* ModyfikujRozklad_kursPoZmianie(void* self, SlimList* args) {
        static char buffer[1024];
        std::string wynik = fakeModel->znalezienieKursu(inputIdKursu);
        strncpy(buffer, wynik.c_str(), 1023);
        buffer[1023] = '\0';
        return buffer;
    }


    // Rejestracja
    SLIM_CREATE_FIXTURE(ModyfikujRozklad)
        StatementExecutor_RegisterMethod(executor, fixtureName, "setIdKursu", ModyfikujRozklad_setIdKursu);
        StatementExecutor_RegisterMethod(executor, fixtureName, "setObecnyKurs", ModyfikujRozklad_setObecnyKurs);
        StatementExecutor_RegisterMethod(executor, fixtureName, "wykonajModyfikacje", ModyfikujRozklad_wykonajModyfikacje);
        StatementExecutor_RegisterMethod(executor, fixtureName, "kursPoZmianie", ModyfikujRozklad_kursPoZmianie);
    SLIM_END

}
