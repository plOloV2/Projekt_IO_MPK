#include <exception>
#include <string>
using namespace std;

#ifndef __Model__AbsModel__2_hpp__
#define __Model__AbsModel__2_hpp__

namespace Model
{
	class AbsModel__2;
}

namespace Model
{
	class AbsModel__2
	{

		public: void dodawanieKursu();

		public: void modyfikowanieKursu(string pKurs);

		public: string znalezienieKursu(int pIdKursu);

		public: string znalezienieKierowcy(int pIdKierowcy);

		public: void modyfikacjaKierowcy(bool pStatusKierowcy[*] );

		public: string* znalezienieKierowcow(int pIdKursow);

		public: void wyslaniePowiadomien(int pIdKierowcow[*] , string pPowiadomienie);

		public: void zglaszenieIncydentu(string pIncydent);

		public: string* znajdzGodzinyPrzyjazdow(int pIdPrzystanku);

		public: void zarejestrowanieZdarzenia(string pZdarzenie);
	};
}

#endif
