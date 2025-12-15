#include <exception>
#include <vector>
using namespace std;

#include "ModyfikowanieRozkladuJazdy.hpp"
#include "AbsModel.hpp"

void Kontroler::ModyfikowanieRozkladuJazdy::modyfikowanieRozkladuJazdy(Model::AbsModel* pModel, int pIdKursu) {

	string kurs = pModel->znalezienieKursu(pIdKursu);

	if(kurs == ""){
		throw "Brak kursu o podanym ID";
		return;
	}

	do{

		wyswietlTrase(kurs);
		

	}while(!sprawdzeniePoprawnosciKursu(kurs));

	vector<int> przystankiKoncowe = edycjaPrzystankowKoncowych();


}

vector<int> Kontroler::ModyfikowanieRozkladuJazdy::edycjaPrzystankowKoncowych() {
	throw "Not yet implemented";
}

void Kontroler::ModyfikowanieRozkladuJazdy::wyswietlTrase(string kurs) {
	throw "Not yet implemented";
}

vector<int> Kontroler::ModyfikowanieRozkladuJazdy::modyfikacjaListyPrzystankow() {
	throw "Not yet implemented";
}

vector<int> Kontroler::ModyfikowanieRozkladuJazdy::modyfikacjaGodzinPrzyjazdow() {
	throw "Not yet implemented";
}

bool Kontroler::ModyfikowanieRozkladuJazdy::sprawdzeniePoprawnosciKursu(string kurs) {
	return true;
}
