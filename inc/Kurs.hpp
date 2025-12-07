#include <exception>
#include <string>
#include <vector>
using namespace std;

#ifndef __Kurs_hpp__
#define __Kurs_hpp__

#include "AbsKurs.hpp"

namespace Model
{
	// class AbsKurs;
	class Kurs;
}

namespace Model
{
	class Kurs: public Model::AbsKurs
	{
		private: int _idKursu;
		private: vector<int> _listaIdPrzystankow;
		private: vector<string> _listaGodzinPrzyjazdow;

		public: Kurs(int pIdKursu, vector<int> pListaIdPrzystankow , vector<string> pListaGodzinPrzyjazdow );

		public: int dajIdKursu();

		public: int* dajListaIdPrzystankow();

		public: string* dajListaGodzinPrzyjazdow();

		public: string opisz();
	};
}

#endif
