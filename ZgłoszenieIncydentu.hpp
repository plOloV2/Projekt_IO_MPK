#include <exception>
#include <string>
using namespace std;

#ifndef __ZgłoszenieIncydentu_hpp__
#define __ZgłoszenieIncydentu_hpp__

#include "IModel.hpp"
#include "AbsStrategiaAktualizacjiStanuKursu.hpp"

class IModel;
namespace Kontroler
{
	// class AbsStrategiaAktualizacjiStanuKursu;
	class ZgłoszenieIncydentu;
}

namespace Kontroler
{
	class ZgłoszenieIncydentu: public Kontroler::AbsStrategiaAktualizacjiStanuKursu
	{

		public: void zgloszenieIncydentu(int pIdKierowcy, int pIdKursu);

		private: int wyborTypuIncydentu();

		private: string wprowadzenieOpisuIncydentu();

		public: void zakonczenieAktualizacjiStatusu(IModel pModel, int pIdKierowcy, int pIdKursu);
	};
}

#endif
