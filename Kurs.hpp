#include <exception>
#include <string>
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
		private: int _listaIdPrzystankow[*];
		private: string _listaGodzinPrzyjazdow[*];

		public: Kurs(int pIdKursu, int pListaIdPrzystankow[*] , string pListaGodzinPrzyjazdow[*] );

		public: int dajIdKursu();

		public: int* dajListaIdPrzystankow();

		public: string* dajListaGodzinPrzyjazdow();

		public: string opisz();
	};
}

#endif
