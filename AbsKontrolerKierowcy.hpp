#include <exception>
using namespace std;

#ifndef __AbsKontrolerKierowcy_hpp__
#define __AbsKontrolerKierowcy_hpp__

#include "AbsKontrolerTablicy.hpp"

namespace Kontroler
{
	// class AbsKontrolerTablicy;
	class AbsKontrolerKierowcy;
}

namespace Kontroler
{
	class AbsKontrolerKierowcy: public Kontroler::AbsKontrolerTablicy
	{

		public: void aktualizacjaStanuKursu();
	};
}

#endif
