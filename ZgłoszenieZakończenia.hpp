#include <exception>
using namespace std;

#ifndef __ZgłoszenieZakończenia_hpp__
#define __ZgłoszenieZakończenia_hpp__

#include "IModel.hpp"
#include "AbsStrategiaAktualizacjiStanuKursu.hpp"

class IModel;
namespace Kontroler
{
	// class AbsStrategiaAktualizacjiStanuKursu;
	class ZgłoszenieZakończenia;
}

namespace Kontroler
{
	class ZgłoszenieZakończenia: public Kontroler::AbsStrategiaAktualizacjiStanuKursu
	{

		public: void zgloszenieZakonczenia(int pIdKierowcy, int pIdKursu);

		private: bool zatwierdzenieZakonczeniaKursu();

		public: void zakonczenieAktualizacjiStatusu(IModel pModel, int pIdKierowcy, int pIdKursu);
	};
}

#endif
