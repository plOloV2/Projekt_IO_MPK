#include <exception>
using namespace std;

#ifndef __KontrolerTablicy_hpp__
#define __KontrolerTablicy_hpp__

#include "AbsModel__1.hpp"
#include "IModel.hpp"
#include "AbsKontrolerTablicy.hpp"

class AbsModel__1;
class IModel;
namespace Kontroler
{
	// class AbsKontrolerTablicy;
	class KontrolerTablicy;
}

namespace Kontroler
{
	class KontrolerTablicy: public Kontroler::AbsKontrolerTablicy
	{
		private: AbsModel__1 _absModel;

		public: KontrolerTablicy(IModel pModel);

		public: void odbiorInformacjiOGodzinachPrzyjazdow();
	};
}

#endif
