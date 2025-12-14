#include <exception>
#include <string>
#include <vector>
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
		public: virtual ~AbsKurs() = default;

		public: virtual int dajIdKursu();

		public: virtual vector<int> dajListaIdPrzystankow();

		public: virtual vector<string> dajListaGodzinPrzyjazdow();

		public: virtual string opisz();
	};
}

#endif
