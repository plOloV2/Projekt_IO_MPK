#include <exception>
using namespace std;

#ifndef __KontrolerTablicy_hpp__
#define __KontrolerTablicy_hpp__

#include "AbsModel.hpp"
#include "AbsKontrolerTablicy.hpp"

class AbsModel;
namespace Kontroler
{
	// class AbsKontrolerTablicy;
	class KontrolerTablicy;
}

namespace Kontroler
{
	class KontrolerTablicy: public Kontroler::AbsKontrolerTablicy
	{
		private: Model::AbsModel _absModel;

		public: KontrolerTablicy(Model::AbsModel pModel);

		public: void odbiorInformacjiOGodzinachPrzyjazdow();
	};
}

#endif
