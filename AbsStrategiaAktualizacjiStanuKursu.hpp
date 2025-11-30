#include <exception>
using namespace std;

#ifndef __AbsStrategiaAktualizacjiStanuKursu_hpp__
#define __AbsStrategiaAktualizacjiStanuKursu_hpp__

#include "AbsModel.hpp"

class AbsModel;
namespace Kontroler
{
	class AbsStrategiaAktualizacjiStanuKursu;
}

namespace Kontroler
{
	class AbsStrategiaAktualizacjiStanuKursu
	{
		private: Model::AbsModel _absModel;
		private: int _idKursu;
		private: int _idKierowcy;

		public: void zakonczenieAktualizacjiKursu(Model::AbsModel pModel, int pIdKierowcy, int pIdKursu);
	};
}

#endif
