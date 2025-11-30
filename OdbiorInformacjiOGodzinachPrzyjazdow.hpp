#include <exception>
using namespace std;

#ifndef __OdbiorInformacjiOGodzinachPrzyjazdow_hpp__
#define __OdbiorInformacjiOGodzinachPrzyjazdow_hpp__

#include "AbsModel__1.hpp"
#include "IModel.hpp"

class AbsModel__1;
class IModel;
namespace Kontroler
{
	class OdbiorInformacjiOGodzinachPrzyjazdow;
}

namespace Kontroler
{
	class OdbiorInformacjiOGodzinachPrzyjazdow
	{
		private: AbsModel__1 _absModel;

		public: void odbiorInformacjiOGodzinachPrzyjazdow(IModel pModel, int pIdKursu);

		public: void odbiorInformacjiOGodzinachPrzyjazdow2(IModel pModel, int pIdPrzystanku);
	};
}

#endif
