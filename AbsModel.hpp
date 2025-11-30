#include <exception>
#include <string>
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

		public: void modyfikacjaKierowcy(bool pStatusKierowcy[] );

		public: string* znalezienieKierowcow(int pIdKursow);

		public: void wyslaniePowiadomien(int pIdKierowcow[] , string pPowiadomienie);

		public: void zglaszenieIncydentu(string pIncydent);

		public: string* znajdzGodzinyPrzyjazdow(int pIdPrzystanku);

		public: void zarejestrowanieZdarzenia(string pZdarzenie);
	};
}

#endif
