#include <exception>
#include <string>
using namespace std;

#ifndef __Kierowca_hpp__
#define __Kierowca_hpp__

namespace Model
{
	class Kierowca;
}

namespace Model
{
	class Kierowca
	{
		private: int _idKierowcy;
		private: int _idKursu;

		public: Kierowca(int pIdKierowcy, int pIdKursu);

		public: int dajIdKierowcy();

		public: int dajIdKursu();

		public: string opisz();
	};
}

#endif
