#include <exception>
#include <string>
using namespace std;

#ifndef __FabrykaKursuZglaszajacego_hpp__
#define __FabrykaKursuZglaszajacego_hpp__

#include "AbsKurs.hpp"
#include "FabrykaKursu.hpp"

namespace Model
{
	class AbsKurs;
	// class FabrykaKursu;
	class FabrykaKursuZglaszajacego;
}

namespace Model
{
	class FabrykaKursuZglaszajacego: public Model::FabrykaKursu
	{
		private: Model::AbsKurs _kurs;

		public: FabrykaKursuZglaszajacego(Model::AbsKurs pKurs);

		public: Model::AbsKurs utworzKurs(string pOpis);
	};
}

#endif
