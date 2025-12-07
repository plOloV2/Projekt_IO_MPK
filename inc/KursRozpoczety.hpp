#include <exception>
#include <string>
using namespace std;

#ifndef __KursRozpoczety_hpp__
#define __KursRozpoczety_hpp__

#include "AbsKurs.hpp"
#include "KartaKursu.hpp"

namespace Model
{
	// class AbsKurs;
	// class KartaKursu;
	class KursRozpoczety;
}

namespace Model
{
	class KursRozpoczety: public Model::KartaKursu
	{
		private: int _idKierowcy;

		public: KursRozpoczety(Model::AbsKurs pKurs, int pIdKierowcy);

		public: string opisz();
	};
}

#endif
