#include <exception>
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
		private: Model::AbsModel _absModel;

		public: void modyfikowanieRozkladuJazdy(Model::AbsModel pModel, int pIdKursu);

		private: int edycjaPrzystankowKoncowych();

		private: void modyfikacjaTrasy();

		private: int* modyfikacjaListyPrzystankow();

		private: int modyfikacjaGodzinPrzyjazdow();
	};
}

#endif
