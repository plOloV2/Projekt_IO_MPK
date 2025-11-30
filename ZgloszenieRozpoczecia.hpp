#include <exception>
using namespace std;

#ifndef __ZgloszenieRozpoczecia_hpp__
#define __ZgloszenieRozpoczecia_hpp__

#include "IModel.hpp"
#include "AbsStrategiaAktualizacjiStanuKursu.hpp"

class IModel;
namespace Kontroler
{
	// class AbsStrategiaAktualizacjiStanuKursu;
	class ZgloszenieRozpoczecia;
}

namespace Kontroler
{
	class ZgloszenieRozpoczecia: public Kontroler::AbsStrategiaAktualizacjiStanuKursu
	{

		public: void zgloszenieRozpoczecia(int pIdKierowcy, int pIdKursu);

		private: bool zatwierdzenieRozpoczeciaKursu();

		public: void zakonczenieAktualizacjiStatusu(IModel pModel, int pIdKierowcy, int pIdKursu);
	};
}

#endif
