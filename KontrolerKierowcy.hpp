#include <exception>
using namespace std;

#ifndef __KontrolerKierowcy_hpp__
#define __KontrolerKierowcy_hpp__

#include "AbsModel__1.hpp"
#include "IModel.hpp"
#include "AbsKontrolerKierowcy.hpp"

class AbsModel__1;
class IModel;
namespace Kontroler
{
	// class AbsKontrolerKierowcy;
	class KontrolerKierowcy;
}

namespace Kontroler
{
	class KontrolerKierowcy: public Kontroler::AbsKontrolerKierowcy
	{
		private: AbsModel__1 _absModel;

		public: KontrolerKierowcy(IModel pModel);

		public: void aktualizacjaStanuKursu();

		public: void odbiorInformacjiOGodzinachPrzyjazdow();
	};
}

#endif
