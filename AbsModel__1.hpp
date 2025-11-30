#include <exception>
#include <string>
using namespace std;

#ifndef __AbsModel__1_hpp__
#define __AbsModel__1_hpp__

class AbsModel__1;

class AbsModel__1
{

	public: void dodawanieKursu();

	public: void modyfikowanieKursu(string pKurs);

	public: string znalezienieKursu(int pIdKursu);

	public: string znalezienieKierowcy(int pIdKierowcy);

	public: void modyfikacjaKierowcy(bool pStatusKierowcy[] );

	public: string* znalezienieKierowcow(int pIdKursu[] );

	public: void wyslaniePowiadomien(int pIdKierowcow[] , string pPowiadomienei);

	public: void zglaszenieIncydentu(string pIncydent);

	public: string* znalezienieGodzinPrzyjazdow(int pIdPrzystanku);
};

#endif
