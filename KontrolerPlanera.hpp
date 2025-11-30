#include <exception>
using namespace std;

#ifndef __KontrolerPlanera_hpp__
#define __KontrolerPlanera_hpp__

#include "AbsModel__1.hpp"
#include "IModel.hpp"
#include "AbsKontrolerPlanera.hpp"

class AbsModel__1;
class IModel;
namespace Kontroler
{
	// class AbsKontrolerPlanera;
	class KontrolerPlanera;
}

namespace Kontroler
{
	class KontrolerPlanera: public Kontroler::AbsKontrolerPlanera
	{
		private: AbsModel__1 _absModel;

		public: KontrolerPlanera(IModel pModel);

		public: void tworzenieRozkladuJazdy();

		public: void modyfikowanieRozkladuJazdy();
	};
}

#endif
