#include <exception>
using namespace std;

#ifndef __OdbiorInformacjiOGodzinachPrzyjazdow_hpp__
#define __OdbiorInformacjiOGodzinachPrzyjazdow_hpp__

#include "AbsModel.hpp"

class AbsModel;
namespace Kontroler
{
	class OdbiorInformacjiOGodzinachPrzyjazdow;
}

namespace Kontroler
{
	class OdbiorInformacjiOGodzinachPrzyjazdow
	{
		private: Model::AbsModel _absModel;

		public: void odbiorInformacjiOGodzinachPrzyjazdow(Model::AbsModel pModel, int pIdKursu);

		public: void odbiorInformacjiOGodzinachPrzyjazdow2(Model::AbsModel pModel, int pIdPrzystanku);
	};
}

#endif
