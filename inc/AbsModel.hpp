#include <exception>
#include <string>
#include <vector>
using namespace std;

#ifndef __AbsModel_hpp__
#define __AbsModel_hpp__

namespace Model
{
	class AbsModel;
}

namespace Model
{
	class AbsModel
	{
		public: virtual ~AbsModel() = default;

		public: virtual void dodawanieKursu() = 0;

		public: virtual void modyfikowanieKursu(string pKurs) = 0;

		public: virtual string znalezienieKursu(int pIdKursu) = 0;

		public: virtual string znalezienieKierowcy(int pIdKierowcy) = 0;

		public: virtual void modyfikacjaKierowcy(int pIdKierowcy) = 0;

		public: virtual string* znalezienieKierowcow(int pIdKursow) = 0;

		public: virtual void wyslaniePowiadomien(vector<int> pIdKierowcow , string pPowiadomienie) = 0;

		public: virtual void zglaszenieIncydentu(string pIncydent) = 0;

		public: virtual vector<string> znajdzGodzinyPrzyjazdow(int pIdPrzystanku) = 0;

		public: virtual void zarejestrowanieZdarzenia(string pZdarzenie) = 0;

		public: virtual string znalezienieKursuRozpoczetego(int pIdKursu) = 0;
	};
}

#endif
