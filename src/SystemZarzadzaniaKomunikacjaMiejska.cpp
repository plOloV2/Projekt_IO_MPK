#include <exception>
#include <string>
#include <iostream>
using namespace std;

#include "SystemZarzadzaniaKomunikacjaMiejska.hpp"
#include "AbsKontrolerPlanera.hpp"
#include "AbsKontrolerDystrybutora.hpp"
#include "AbsKontrolerTablicy.hpp"
#include "AbsKontrolerKierowcy.hpp"
#include "KontrolerKierowcy.hpp"
#include "Model.hpp"

void Kontroler::SystemZarzadzaniaKomunikacjaMiejska::main() {
    cout << "System Zarzadzania Komunikacja Miejska działa!" << endl;

    Model::AbsDAO dao;
    Model::Inwentarz inwentarz;
    Model::Model model(inwentarz, dao);

    KontrolerKierowcy _kontrolerKierowcy(model);
    _kontrolerKierowcy.aktualizacjaStanuKursu();
}

int main() {
    Kontroler::SystemZarzadzaniaKomunikacjaMiejska app;
    app.main();
    return 0;
}