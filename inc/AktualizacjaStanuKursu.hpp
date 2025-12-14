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
		private: Kontroler::AbsStrategiaAktualizacjiStanuKursu* _strategiaAktualizacjiStanuKursu;

		private: Model::AbsModel* _absModel;

		private: int _idKierowcy;

		public: AktualizacjaStanuKursu(Model::AbsModel* pModel, int pIdKierowcy);

		private: int wprowadzenieIdKursu();

		private: void wyborOpcji();
	};
}

#endif
