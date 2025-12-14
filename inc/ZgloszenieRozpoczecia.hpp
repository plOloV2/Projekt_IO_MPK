#include <exception>
using namespace std;

#ifndef __ZgloszenieRozpoczecia_hpp__
#define __ZgloszenieRozpoczecia_hpp__

#include "AbsStrategiaAktualizacjiStanuKursu.hpp"

namespace Kontroler
{
	// class AbsStrategiaAktualizacjiStanuKursu;
	class ZgloszenieRozpoczecia;
}

namespace Kontroler
{
	class ZgloszenieRozpoczecia: public Kontroler::AbsStrategiaAktualizacjiStanuKursu
	{

		public: ZgloszenieRozpoczecia();

		private: bool zatwierdzenieRozpoczeciaKursu();

		public: void zakonczenieAktualizacjiKursu(Model::AbsModel* pModel, int pIdKierowcy, int pIdKursu) override;
	};
}

#endif
