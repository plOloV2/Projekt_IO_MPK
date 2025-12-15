#include <exception>
#include <vector>
using namespace std;

#ifndef __ModyfikowanieRozkladuJazdy_hpp__
#define __ModyfikowanieRozkladuJazdy_hpp__

#include "AbsModel.hpp"

class AbsModel__1;
namespace Kontroler
{
	class ModyfikowanieRozkladuJazdy;
}

namespace Kontroler
{
	class ModyfikowanieRozkladuJazdy
	{
		private: Model::AbsModel* _absModel;

		public: void modyfikowanieRozkladuJazdy(Model::AbsModel* pModel, int pIdKursu);

		private: void wyswietlTrase(string Kurs);

		private: vector<int> modyfikacjaListyPrzystankow(string Kurs);

		private: vector<string> modyfikacjaGodzinPrzyjazdow(string Kurs);

		private: string wprowadzZmiany(string IdKursu, vector<int> wszystkiePrzystanki, vector<string> godzinyPrzyjazdow, string IdKierowcy);

		private: bool sprawdzeniePoprawnosciKursu(string Kurs);

		private: vector<string> podzielString(string dane, char dzielnik);

		private: vector<int> parsePrzystanki(string dane);

		private: vector<string> parseCzasy(string dane);

	};
}

#endif
