#include <exception>
#include <string>
#include <iostream>
using namespace std;

#include "SystemZarzadzaniaKomunikacjaMiejska.hpp"
#include "AbsKontrolerPlanera.hpp"
#include "AbsKontrolerDystrybutora.hpp"
#include "AbsKontrolerTablicy.hpp"
#include "AbsKontrolerKierowcy.hpp"

void Kontroler::SystemZarzadzaniaKomunikacjaMiejska::main() {
    cout << "System Zarzadzania Komunikacja Miejska działa!" << endl;

    _kontrolerKierowcy.aktualizacjaStanuKursu();
}

int main() {
    Kontroler::SystemZarzadzaniaKomunikacjaMiejska app;
    app.main();
    return 0;
}