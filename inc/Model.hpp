#include <exception>
#include <string>
#include <vector>
using namespace std;

#ifndef __Model_hpp__
#define __Model_hpp__

#include "AbsDAO.hpp"
#include "Inwentarz.hpp"
#include "AbsModel.hpp"

namespace Model
{
	class AbsDAO;
	class Inwentarz;
	class AbsModel;
	class Model;
}

namespace Model
{
	class Model: public AbsModel
	{
		private: AbsDAO _dao;
		private: Inwentarz _inwentarz;

		public: Model(Inwentarz pInwentarz, AbsDAO pDao);

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
