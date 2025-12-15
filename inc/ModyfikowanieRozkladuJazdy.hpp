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

		private: vector<int> edycjaPrzystankowKoncowych();

		private: void wyswietlTrase(string kurs);

		private: vector<int> modyfikacjaListyPrzystankow();

		private: vector<int> modyfikacjaGodzinPrzyjazdow();

		private: bool sprawdzeniePoprawnosciKursu(string kurs);
	};
}

#endif
