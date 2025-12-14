#include <exception>
using namespace std;

#ifndef __KontrolerPlanera_hpp__
#define __KontrolerPlanera_hpp__

#include "AbsModel.hpp"
#include "AbsKontrolerPlanera.hpp"

class AbsModel;
namespace Kontroler
{
	// class AbsKontrolerPlanera;
	class KontrolerPlanera;
}

namespace Kontroler
{
	class KontrolerPlanera: public Kontroler::AbsKontrolerPlanera
	{
		private: Model::AbsModel* _absModel;

		public: KontrolerPlanera(Model::AbsModel* pModel);

		public: void tworzenieRozkladuJazdy();

		public: void modyfikowanieRozkladuJazdy();
	};
}

#endif
