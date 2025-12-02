#include <exception>
#include <string>
using namespace std;

#ifndef __FabrykaKierowcy_hpp__
#define __FabrykaKierowcy_hpp__

#include "Kierowca.hpp"

namespace Model
{
	class Kierowca;
	class FabrykaKierowcy;
}

namespace Model
{
	class FabrykaKierowcy
	{

		public: void fabrykaKieorwcy();

		public: Model::Kierowca utworzKierowce(string pOpis);
	};
}

#endif
