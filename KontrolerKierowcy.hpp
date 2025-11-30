#include <exception>
using namespace std;

#ifndef __KontrolerKierowcy_hpp__
#define __KontrolerKierowcy_hpp__

#include "AbsModel.hpp"
#include "AbsKontrolerKierowcy.hpp"

class AbsModel;
namespace Kontroler
{
	// class AbsKontrolerKierowcy;
	class KontrolerKierowcy;
}

namespace Kontroler
{
	class KontrolerKierowcy: public Kontroler::AbsKontrolerKierowcy
	{
		private: Model::AbsModel _absModel;

		public: KontrolerKierowcy(Model::AbsModel pModel);

		public: void aktualizacjaStanuKursu();

		public: void odbiorInformacjiOGodzinachPrzyjazdow();
	};
}

#endif
