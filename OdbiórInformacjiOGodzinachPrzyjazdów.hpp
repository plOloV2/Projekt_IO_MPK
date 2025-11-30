#include <exception>
using namespace std;

#ifndef __OdbiórInformacjiOGodzinachPrzyjazdów_hpp__
#define __OdbiórInformacjiOGodzinachPrzyjazdów_hpp__

#include "AbsModel__1.hpp"
#include "IModel.hpp"

class AbsModel__1;
class IModel;
namespace Kontroler
{
	class OdbiórInformacjiOGodzinachPrzyjazdów;
}

namespace Kontroler
{
	class OdbiórInformacjiOGodzinachPrzyjazdów
	{
		private: AbsModel__1 _absModel;

		public: void odbiorInformacjiOGodzinachPrzyjazdow(IModel pModel, int pIdKursu);

		public: void odbiorInformacjiOGodzinachPrzyjazdow2(IModel pModel, int pIdPrzystanku);
	};
}

#endif
