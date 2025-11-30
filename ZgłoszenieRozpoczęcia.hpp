#include <exception>
using namespace std;

#ifndef __ZgłoszenieRozpoczęcia_hpp__
#define __ZgłoszenieRozpoczęcia_hpp__

#include "IModel.hpp"
#include "AbsStrategiaAktualizacjiStanuKursu.hpp"

class IModel;
namespace Kontroler
{
	// class AbsStrategiaAktualizacjiStanuKursu;
	class ZgłoszenieRozpoczęcia;
}

namespace Kontroler
{
	class ZgłoszenieRozpoczęcia: public Kontroler::AbsStrategiaAktualizacjiStanuKursu
	{

		public: void zgloszenieRozpoczecia(int pIdKierowcy, int pIdKursu);

		private: bool zatwierdzenieRozpoczeciaKursu();

		public: void zakonczenieAktualizacjiStatusu(IModel pModel, int pIdKierowcy, int pIdKursu);
	};
}

#endif
