#include <exception>
#include <string>
using namespace std;

#ifndef __FabrykaKursu_hpp__
#define __FabrykaKursu_hpp__

#include "AbsKurs.hpp"
#include "AbsFabrykaKursu.hpp"

namespace Model
{
	class AbsKurs;
	// class AbsFabrykaKursu;
	class FabrykaKursu;
}

namespace Model
{
	class FabrykaKursu: public Model::AbsFabrykaKursu
	{

		public: FabrykaKursu();

		public: Model::AbsKurs* utworzKurs(string pOpis);
	};
}

#endif
