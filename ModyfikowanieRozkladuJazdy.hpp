#include <exception>
using namespace std;

#ifndef __ModyfikowanieRozkladuJazdy_hpp__
#define __ModyfikowanieRozkladuJazdy_hpp__

#include "AbsModel__1.hpp"
#include "IModel.hpp"

class AbsModel__1;
class IModel;
namespace Kontroler
{
	class ModyfikowanieRozkladuJazdy;
}

namespace Kontroler
{
	class ModyfikowanieRozkladuJazdy
	{
		private: AbsModel__1 _absModel;

		public: void modyfikowanieRozkladuJazdy(IModel pModel, int pIdKursu);

		private: int edycjaPrzystankowKoncowych();

		private: void modyfikacjaTrasy();

		private: int* modyfikacjaListyPrzystankow();

		private: int modyfikacjaGodzinPrzyjazdow();
	};
}

#endif
