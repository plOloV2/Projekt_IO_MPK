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

		private: void wyswietlTrase(string kurs);

		private: vector<int> modyfikacjaListyPrzystankow(string kurs);

		private: vector<string> modyfikacjaGodzinPrzyjazdow(string kurs);

		private: string wprowadzZmiany(string id, vector<int> wszystkiePrzystanki, vector<string> godzinyPrzyjazdow, string driverId);

		private: bool sprawdzeniePoprawnosciKursu(string kurs);

		private: vector<string> podzielString(const string& s, char delimiter);

		private: vector<int> parsePrzystanki(const string& stopsStr);

		private: vector<string> parseCzasy(const string& timesStr);

	};
}

#endif
