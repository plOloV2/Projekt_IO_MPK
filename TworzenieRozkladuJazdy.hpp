#include <exception>
using namespace std;

#ifndef __TworzenieRozkladuJazdy_hpp__
#define __TworzenieRozkladuJazdy_hpp__

#include "AbsModel__1.hpp"
#include "IModel.hpp"

class AbsModel__1;
class IModel;
namespace Kontroler
{
	class TworzenieRozkladuJazdy;
}

namespace Kontroler
{
	class TworzenieRozkladuJazdy
	{
		private: int _idKursu;
		private: AbsModel__1 _absModel;

		public: void tworzenieRozkladuJazdy(IModel pModel);
	};
}

#endif
