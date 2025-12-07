#include <exception>
#include <string>
using namespace std;

#ifndef __AbsKurs_hpp__
#define __AbsKurs_hpp__

namespace Model
{
	class AbsKurs;
}

namespace Model
{
	class AbsKurs
	{

		public: int dajIdKursu();

		public: int* dajListaIdPrzystankow();

		public: string* dajListaGodzinPrzyjazdow();

		public: string opisz();
	};
}

#endif
