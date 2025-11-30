#include <exception>
using namespace std;

#ifndef __AbsStrategiaAktualizacjiStanuKursu_hpp__
#define __AbsStrategiaAktualizacjiStanuKursu_hpp__

#include "AbsModel__1.hpp"
#include "IModel.hpp"

class AbsModel__1;
class IModel;
namespace Kontroler
{
	class AbsStrategiaAktualizacjiStanuKursu;
}

namespace Kontroler
{
	class AbsStrategiaAktualizacjiStanuKursu
	{
		private: AbsModel__1 _absModel;
		private: int _idKursu;
		private: int _idKierowcy;

		public: void zakonczenieAktualizacjiKursu(IModel pModel, int pIdKierowcy, int pIdKursu);
	};
}

#endif
