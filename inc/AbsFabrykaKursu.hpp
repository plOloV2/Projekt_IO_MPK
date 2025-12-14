#include <exception>
#include <string>
using namespace std;

#ifndef __AbsFabrykaKursu_hpp__
#define __AbsFabrykaKursu_hpp__

#include "AbsKurs.hpp"

namespace Model
{
	class AbsKurs;
	class AbsFabrykaKursu;
}

namespace Model
{
	class AbsFabrykaKursu
	{

		public: Model::AbsKurs* utworzKurs(string pOpis);
	};
}

#endif
