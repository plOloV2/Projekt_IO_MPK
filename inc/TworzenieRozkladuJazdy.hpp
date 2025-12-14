#include <exception>
using namespace std;

#ifndef __TworzenieRozkladuJazdy_hpp__
#define __TworzenieRozkladuJazdy_hpp__

#include "AbsModel.hpp"

class AbsModel;
namespace Kontroler
{
	class TworzenieRozkladuJazdy;
}

namespace Kontroler
{
	class TworzenieRozkladuJazdy
	{
		private: int _idKursu;
		private: Model::AbsModel* _absModel;

		public: void tworzenieRozkladuJazdy(Model::AbsModel* pModel);
	};
}

#endif
