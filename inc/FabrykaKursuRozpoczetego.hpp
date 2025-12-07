#include <exception>
#include <string>
using namespace std;

#ifndef __FabrykaKursuRozpoczetego_hpp__
#define __FabrykaKursuRozpoczetego_hpp__

#include "AbsKurs.hpp"
#include "FabrykaKursu.hpp"

namespace Model
{
	class AbsKurs;
	// class FabrykaKursu;
	class FabrykaKursuRozpoczetego;
}

namespace Model
{
	class FabrykaKursuRozpoczetego: public Model::FabrykaKursu
	{
		private: Model::AbsKurs _kurs;

		public: FabrykaKursuRozpoczetego(Model::AbsKurs pKurs);

		public: Model::AbsKurs utworzKurs(string pOpis);
	};
}

#endif
