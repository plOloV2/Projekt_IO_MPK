#include <exception>
#include <string>
using namespace std;

#ifndef __FabrykaKursu_hpp__
#define __FabrykaKursu_hpp__

#include "Kurs.hpp"

namespace Model
{
	class Kurs;
	class FabrykaKursu;
}

namespace Model
{
	class FabrykaKursu
	{

		public: FabrykaKursu();

		public: Model::Kurs utworzKurs(string pOpis);
	};
}

#endif
