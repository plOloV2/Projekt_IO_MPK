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
    for(int i = 0; i < 10; i++) {
        _kontrolerKierowcy.aktualizacjaStanuKursu();
    }
    _kontrolerKierowcy.odbiorInformacjiOGodzinachPrzyjazdow();
    _kontrolerTablicy.odbiorInformacjiOGodzinachPrzyjazdow();

}

int main() {
    srand(time(0));
    Kontroler::SystemZarzadzaniaKomunikacjaMiejska app;
    app.main();
    return 0;
}