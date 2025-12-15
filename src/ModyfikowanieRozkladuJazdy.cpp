#include <exception>
using namespace std;

#include "ModyfikowanieRozkladuJazdy.hpp"
#include "AbsModel.hpp"

void Kontroler::ModyfikowanieRozkladuJazdy::modyfikowanieRozkladuJazdy(Model::AbsModel* pModel, int pIdKursu) {

	string kurs = pModel->znalezienieKursu(pIdKursu);

	if(kurs == ""){
		throw "Brak kursu o podanym ID";
		return;
	}

	int przystankiKoncowe[] = Kontroler::ModyfikowanieRozkladuJazdy::edycjaPrzystankowKoncowych();


}

int* Kontroler::ModyfikowanieRozkladuJazdy::edycjaPrzystankowKoncowych() {
	throw "Not yet implemented";
}

void Kontroler::ModyfikowanieRozkladuJazdy::modyfikacjaTrasy() {
	throw "Not yet implemented";
}

int* Kontroler::ModyfikowanieRozkladuJazdy::modyfikacjaListyPrzystankow() {
	throw "Not yet implemented";
}

int Kontroler::ModyfikowanieRozkladuJazdy::modyfikacjaGodzinPrzyjazdow() {
	throw "Not yet implemented";
}

bool Kontroler::ModyfikowanieRozkladuJazdy::sprawdzeniePoprawnosciKursu() {
	throw "Not yet implemented";
}
