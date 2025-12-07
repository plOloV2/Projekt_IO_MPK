#include <exception>
using namespace std;

#ifndef __ZgloszenieZakonczenia_hpp__
#define __ZgloszenieZakonczenia_hpp__

#include "AbsStrategiaAktualizacjiStanuKursu.hpp"

class IModel;
namespace Kontroler
{
	// class AbsStrategiaAktualizacjiStanuKursu;
	class ZgloszenieZakonczenia;
}

namespace Kontroler
{
	class ZgloszenieZakonczenia: public Kontroler::AbsStrategiaAktualizacjiStanuKursu
	{

		public: void zgloszenieZakonczenia(int pIdKierowcy, int pIdKursu);

		private: bool zatwierdzenieZakonczeniaKursu();

		public: void zakonczenieAktualizacjiKursu(Model::AbsModel pModel, int pIdKierowcy, int pIdKursu);
	};
}

#endif
