#include <exception>
#include <string>
using namespace std;

#ifndef __FabrykaKursuRozpoczetego_hpp__
#define __FabrykaKursuRozpoczetego_hpp__

#include "AbsKurs.hpp"
#include "AbsFabrykaKursu.hpp"

namespace Model
{
	class AbsKurs;
	// class AbsFabrykaKursu;
	class FabrykaKursuRozpoczetego;
}

namespace Model
{
	class FabrykaKursuRozpoczetego: public Model::AbsFabrykaKursu
	{
		private: Model::AbsKurs* _kurs;

		public: FabrykaKursuRozpoczetego(Model::AbsKurs* pKurs);

		public: Model::AbsKurs* utworzKurs(string pOpis);
	};
}

#endif
