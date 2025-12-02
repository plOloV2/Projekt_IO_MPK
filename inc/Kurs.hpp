#include <exception>
#include <string>
#include <vector>
using namespace std;

#ifndef __Kurs_hpp__
#define __Kurs_hpp__

namespace Model
{
	class Kurs;
}

namespace Model
{
	class Kurs
	{
		private: int _idKursu;
		private: vector<int> _listaIdPrzystankow;
		private: vector<int> _listaGodzinPrzyjazdow;

		public: Kurs(int pIdKursu, vector<int> pListaIdPrzystankow , vector<string> pListaGodzinPrzyjazdow );

		public: int dajIdKursu();

		public: int* dajListaIdPrzystankow();

		public: string* dajListaGodzinPrzyjazdow();

		public: string opisz();
	};
}

#endif
