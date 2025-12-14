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

		public: virtual int dajIdKursu() = 0;

		public: virtual vector<int> dajListaIdPrzystankow() = 0;

		public: virtual vector<string> dajListaGodzinPrzyjazdow() = 0;

		public: virtual string opisz() = 0;
	};
}

#endif
