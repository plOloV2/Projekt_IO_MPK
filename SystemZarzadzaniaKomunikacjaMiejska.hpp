#include <exception>
#include <string>
using namespace std;

#ifndef __SystemZarzadzaniaKomunikacjaMiejska_hpp__
#define __SystemZarzadzaniaKomunikacjaMiejska_hpp__

#include "AbsKontrolerPlanera.hpp"
#include "AbsKontrolerDystrybutora.hpp"
#include "AbsKontrolerTablicy.hpp"
#include "AbsKontrolerKierowcy.hpp"

namespace Kontroler
{
	class AbsKontrolerPlanera;
	class AbsKontrolerDystrybutora;
	class AbsKontrolerTablicy;
	class AbsKontrolerKierowcy;
	class SystemZarzadzaniaKomunikacjaMiejska;
}

namespace Kontroler
{
	class SystemZarzadzaniaKomunikacjaMiejska
	{
		private: Kontroler::AbsKontrolerPlanera _kontrolerPlanera;
		private: Kontroler::AbsKontrolerDystrybutora _kontrolerDystrybutora;
		private: Kontroler::AbsKontrolerTablicy _kontrolerTablicy;
		private: Kontroler::AbsKontrolerKierowcy _kontrolerKierowcy;

		public: void main(string pArgs[] );
	};
}

#endif
