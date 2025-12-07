#include <exception>
#include <string>
using namespace std;

#ifndef __KartaKursu_hpp__
#define __KartaKursu_hpp__

#include "AbsKurs.hpp"

namespace Model
{
	// class AbsKurs;
	class KartaKursu;
}

namespace Model
{
	class KartaKursu: public Model::AbsKurs
	{
		protected: Model::AbsKurs _kurs;

		public: KartaKursu(Model::AbsKurs pKurs);

		public: int dajIdKursu();

		public: int* dajListaIdPrzystankow();

		public: string* dajListaGodzinprzyjazdow();

		public: string opisz();
	};
}

#endif
