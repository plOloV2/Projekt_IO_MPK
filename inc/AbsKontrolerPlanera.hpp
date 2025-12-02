#include <exception>
using namespace std;

#ifndef __AbsKontrolerPlanera_hpp__
#define __AbsKontrolerPlanera_hpp__

namespace Kontroler
{
	class AbsKontrolerPlanera;
}

namespace Kontroler
{
	class AbsKontrolerPlanera
	{

		public: void tworzenieRozkladuJazdy();

		public: void modyfikowanieRozkladuJazdy();
	};
}

#endif
