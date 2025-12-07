#include <exception>
#include <string>
using namespace std;

#ifndef __KursZglaszajacy_hpp__
#define __KursZglaszajacy_hpp__

#include "Incydent.hpp"
#include "AbsKurs.hpp"
#include "KartaKursu.hpp"

namespace Model
{
	class Incydent;
	// class AbsKurs;
	// class KartaKursu;
	class KursZglaszajacy;
}

namespace Model
{
	class KursZglaszajacy: public Model::KartaKursu
	{
		private: Model::Incydent _incydent;

		public: KursZglaszajacy(Model::AbsKurs pKurs, Model::Incydent pIncydent);

		public: string opisz();
	};
}

#endif
