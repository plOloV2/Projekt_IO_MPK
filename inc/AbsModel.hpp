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

		public: void dodawanieKursu();

		public: void modyfikowanieKursu(string pKurs);

		public: string znalezienieKursu(int pIdKursu);

		public: string znalezienieKierowcy(int pIdKierowcy);

		public: void modyfikacjaKierowcy(int pIdKierowcy);

		public: string* znalezienieKierowcow(int pIdKursow);

		public: void wyslaniePowiadomien(vector<int> pIdKierowcow , string pPowiadomienie);

		public: void zglaszenieIncydentu(string pIncydent);

		public: string* znajdzGodzinyPrzyjazdow(int pIdPrzystanku);

		public: void zarejestrowanieZdarzenia(string pZdarzenie);

		public: string znalezienieKursuRozpoczetego(int pIdKursu);
	};
}

#endif
