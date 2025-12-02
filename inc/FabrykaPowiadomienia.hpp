#include <exception>
#include <string>
using namespace std;

#ifndef __FabrykaPowiadomienia_hpp__
#define __FabrykaPowiadomienia_hpp__

#include "Powiadomienie.hpp"

namespace Model
{
	class Powiadomienie;
	class FabrykaPowiadomienia;
}

namespace Model
{
	class FabrykaPowiadomienia
	{

		public: FabrykaPowiadomienia();

		public: Model::Powiadomienie utworzPowiadomienie(string pOpis);
	};
}

#endif
