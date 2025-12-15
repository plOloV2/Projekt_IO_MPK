#include <exception>
#include <string>
#include <iostream>
using namespace std;

#include "SystemZarzadzaniaKomunikacjaMiejska.hpp"
#include "AbsKontrolerPlanera.hpp"
#include "AbsKontrolerDystrybutora.hpp"
#include "AbsKontrolerTablicy.hpp"
#include "AbsKontrolerKierowcy.hpp"
#include "KontrolerDystrybutora.hpp"
#include "KontrolerKierowcy.hpp"
#include "KontrolerTablicy.hpp"
#include "Model.hpp"
#include "DAO.hpp"

void Kontroler::SystemZarzadzaniaKomunikacjaMiejska::main() {
    cout << "System Zarzadzania Komunikacja Miejska dziala!" << endl;

    Model::DAO* dao = new Model::DAO();
    Model::Inwentarz* inwentarz = new Model::Inwentarz(dao);
    Model::Model model(inwentarz, dao);

    KontrolerKierowcy _kontrolerKierowcy(&model);
    KontrolerTablicy _kontrolerTablicy(&model);
    KontrolerDystrybutora _kontrolerDystrybutora(&model);

    dao->wyswietlBaze();

    _kontrolerDystrybutora.modyfikowanieRozkladuJazdy();
    for(int i = 0; i < 3; i++) {
        _kontrolerKierowcy.aktualizacjaStanuKursu();
    }
    _kontrolerKierowcy.odbiorInformacjiOGodzinachPrzyjazdow();
    _kontrolerTablicy.odbiorInformacjiOGodzinachPrzyjazdow();

    dao->wyswietlBaze();
}

int main() {
    srand(time(0));
    Kontroler::SystemZarzadzaniaKomunikacjaMiejska app;
    app.main();
    return 0;
}