#include <exception>
#include <string>
using namespace std;

#ifndef __FabrykaKursuZglaszajacego_hpp__
#define __FabrykaKursuZglaszajacego_hpp__

#include "AbsKurs.hpp"
#include "AbsFabrykaKursu.hpp"

namespace Model
{
	class AbsKurs;
	// class AbsFabrykaKursu;
	class FabrykaKursuZglaszajacego;
}

namespace Model
{
	class FabrykaKursuZglaszajacego: public Model::AbsFabrykaKursu
	{
		private: Model::AbsKurs _kurs;

		public: FabrykaKursuZglaszajacego(Model::AbsKurs pKurs);

		public: Model::AbsKurs utworzKurs(string pOpis);
	};
}

#endif
