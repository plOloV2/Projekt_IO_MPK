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
		protected: Model::AbsKurs* _kurs;

		public: KartaKursu(Model::AbsKurs* pKurs);

		public: int dajIdKursu() override;

		public: vector<int> dajListaIdPrzystankow() override;

		public: vector<string> dajListaGodzinPrzyjazdow() override;

		public: string opisz() override;
	};
}

#endif
