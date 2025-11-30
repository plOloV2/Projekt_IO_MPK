#include <exception>
#include <string>
using namespace std;

#ifndef __Model_hpp__
#define __Model_hpp__

#include "AbsDAO.hpp"
#include "Model__AbsModel__2.hpp"

namespace Model
{
	class AbsDAO;
	// class AbsModel__2;
	class Model;
}

namespace Model
{
	class Model: public Model::AbsModel__2
	{
		private: Model::AbsDAO _dao;

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
