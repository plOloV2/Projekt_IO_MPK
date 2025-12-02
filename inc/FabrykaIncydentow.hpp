#include <exception>
#include <string>
using namespace std;

#ifndef __FabrykaIncydentow_hpp__
#define __FabrykaIncydentow_hpp__

#include "Incydent.hpp"

namespace Model
{
	class Incydent;
	class FabrykaIncydentow;
}

namespace Model
{
	class FabrykaIncydentow
	{

		public: FabrykaIncydentow();

		public: Model::Incydent utworzIncydent(string pOpis);
	};
}

#endif
