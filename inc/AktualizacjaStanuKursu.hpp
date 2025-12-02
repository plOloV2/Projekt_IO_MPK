#include <exception>
using namespace std;

#ifndef __AktualizacjaStanuKursu_hpp__
#define __AktualizacjaStanuKursu_hpp__

#include "AbsStrategiaAktualizacjiStanuKursu.hpp"

namespace Kontroler
{
	class AbsStrategiaAktualizacjiStanuKursu;
	class AktualizacjaStanuKursu;
}

namespace Kontroler
{
	class AktualizacjaStanuKursu
	{
		private: Kontroler::AbsStrategiaAktualizacjiStanuKursu _strategiaAktualizacjiStanuKursu;

		public: void aktualizacjaStanuKursu();

		private: int wprowadzenieIdKursu();

		private: void wyborOpcji();
	};
}

#endif
