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
#include "ZgloszenieRozpoczecia.hpp"

// Mock Model
class FakeModel : public Model::AbsModel {
public:
    std::map<int, std::string> bazaKursow;
    std::map<int, std::string> bazaKierowcow;

    void ustawKursTestowy(int id, std::string dane) {
        bazaKursow[id] = dane;
    }

    void ustawKierowceTestowego(int id, std::string dane) {
        bazaKierowcow[id] = dane;
    }

    std::string znalezienieKursu(int pIdKursu) override {
        if (bazaKursow.find(pIdKursu) != bazaKursow.end()) {
            return bazaKursow[pIdKursu];
        }
        return "";
    }

    std::string znalezienieKierowcy(int pIdKierowcy) override {
        if (bazaKierowcow.find(pIdKierowcy) != bazaKierowcow.end()) {
            return bazaKierowcow[pIdKierowcy];
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

    void modyfikacjaKierowcy(int pIdKierowcy, int pIdKursu) override {
        try {
            string kierowca = to_string(pIdKierowcy) + ';' + to_string(pIdKursu);
            bazaKierowcow[pIdKierowcy] = kierowca;
        } catch (...) {}
    }

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

static FakeModel* fakeModel = nullptr;
static Kontroler::ZgloszenieRozpoczecia* kontroler = nullptr;

static int inputIdKursu = 0;
static int inputIdKierowcy = 0;
static char inputDaneKursu[512];
static char inputDaneKierowcy[512];

extern "C" {

    // Konstruktor
    void* ZglosRozpoczecie_Create(StatementExecutor* executor, SlimList* args) {
        if (fakeModel == nullptr) fakeModel = new FakeModel();
        if (kontroler == nullptr) kontroler = new Kontroler::ZgloszenieRozpoczecia();
        
        inputIdKursu = 0;
        inputIdKierowcy = 0;
        memset(inputDaneKursu, 0, sizeof(inputDaneKursu));
        memset(inputDaneKierowcy, 0, sizeof(inputDaneKierowcy));
        
        return fakeModel;
    }

    void ZglosRozpoczecie_Destroy(void* self) {
    }

    // Setter: id kursu
    const char* ZglosRozpoczecie_setIdKursu(void* self, SlimList* args) {
        // Pobieramy pierwszy argument jako string i konwertujemy na int
        const char* arg = SlimList_GetStringAt(args, 0);
        inputIdKursu = atoi(arg);
        return "";
    }

    // Setter: obecny kurs
    const char* ZglosRozpoczecie_setObecnyKurs(void* self, SlimList* args) {
        const char* arg = SlimList_GetStringAt(args, 0);
        strcpy(inputDaneKursu, arg);
        // Aktualizujemy fake model
        fakeModel->ustawKursTestowy(inputIdKursu, std::string(inputDaneKursu));
        return "";
    }

    // Setter: id kursu
    const char* ZglosRozpoczecie_setIdKierowcy(void* self, SlimList* args) {
        // Pobieramy pierwszy argument jako string i konwertujemy na int
        const char* arg = SlimList_GetStringAt(args, 0);
        inputIdKierowcy = atoi(arg);
        return ""; // Zwracamy pusty string (void w fitnesse)
    }

    // Setter: obecny kurs
    const char* ZglosRozpoczecie_setObecnyKierowca(void* self, SlimList* args) {
        const char* arg = SlimList_GetStringAt(args, 0);
        strcpy(inputDaneKursu, arg);
        // Aktualizujemy fake model
        fakeModel->ustawKierowceTestowego(inputIdKierowcy, std::string(inputDaneKierowcy));
        return "";
    }

    // Action: wykonaj
    const char* ZglosRozpoczecie_wykonajModyfikacje(void* self, SlimList* args) {
        try {
            kontroler->zakonczenieAktualizacjiKursu(fakeModel, inputIdKierowcy, inputIdKursu);
        } catch (const char* msg) {
            std::cout << "Wyjatek: " << msg << std::endl;
        } catch (...) {
            std::cout << "Nieznany wyjatek" << std::endl;
        }
        return "";
    }

    // Getter: kurs po zmianie
    const char* ZglosRozpoczecie_kursPoZmianie(void* self, SlimList* args) {
        static char buffer[1024];
        std::string wynik = fakeModel->znalezienieKursu(inputIdKursu);
        strncpy(buffer, wynik.c_str(), 1023);
        buffer[1023] = '\0';
        return buffer;
    }

    // Getter: kierowca po zmianie
    const char* ZglosRozpoczecie_kierowcaPoZmianie(void* self, SlimList* args) {
        static char buffer[1024];
        std::string wynik = fakeModel->znalezienieKierowcy(inputIdKierowcy);
        strncpy(buffer, wynik.c_str(), 1023);
        buffer[1023] = '\0';
        return buffer;
    }


    // Rejestracja
    SLIM_CREATE_FIXTURE(ZglosRozpoczecie)
        StatementExecutor_RegisterMethod(executor, fixtureName, "setIdKursu", ZglosRozpoczecie_setIdKursu);
        StatementExecutor_RegisterMethod(executor, fixtureName, "setObecnyKierowca", ZglosRozpoczecie_setObecnyKierowca);
        StatementExecutor_RegisterMethod(executor, fixtureName, "setIdKierowcy", ZglosRozpoczecie_setIdKierowcy);
        StatementExecutor_RegisterMethod(executor, fixtureName, "setObecnyKurs", ZglosRozpoczecie_setObecnyKurs);
        StatementExecutor_RegisterMethod(executor, fixtureName, "wykonajModyfikacje", ZglosRozpoczecie_wykonajModyfikacje);
        StatementExecutor_RegisterMethod(executor, fixtureName, "kursPoZmianie", ZglosRozpoczecie_kursPoZmianie);
    SLIM_END

}
