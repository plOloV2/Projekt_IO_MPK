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

		public: void dodawanieKursu()  override;

		public: void modyfikowanieKursu(string pKurs)  override;

		public: string znalezienieKursu(int pIdKursu)  override;

		public: string znalezienieKierowcy(int pIdKierowcy)  override;

		public: void modyfikacjaKierowcy(int pIdKierowcy)  override;

		public: string* znalezienieKierowcow(int pIdKursow)  override;

		public: void wyslaniePowiadomien(vector<int> pIdKierowcow , string pPowiadomienie)  override;

		public: void zglaszenieIncydentu(string pIncydent)  override;

		public: vector<string> znajdzGodzinyPrzyjazdow(int pIdPrzystanku)  override;

		public: void zarejestrowanieZdarzenia(string pZdarzenie)  override;

		public: string znalezienieKursuRozpoczetego(int pIdKursu)  override;
	};
}

#endif
