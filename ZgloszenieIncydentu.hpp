#include <exception>
#include <string>
using namespace std;

#ifndef __ZgloszenieIncydentu_hpp__
#define __ZgloszenieIncydentu_hpp__

#include "AbsStrategiaAktualizacjiStanuKursu.hpp"

namespace Kontroler
{
	// class AbsStrategiaAktualizacjiStanuKursu;
	class ZgloszenieIncydentu;
}

namespace Kontroler
{
	class ZgloszenieIncydentu: public Kontroler::AbsStrategiaAktualizacjiStanuKursu
	{

		public: void zgloszenieIncydentu(int pIdKierowcy, int pIdKursu);

		private: int wyborTypuIncydentu();

		private: string wprowadzenieOpisuIncydentu();

		public: void zakonczenieAktualizacjiStatusu(Model::AbsModel pModel, int pIdKierowcy, int pIdKursu);
	};
}

#endif
