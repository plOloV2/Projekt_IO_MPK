#include <exception>
#include <string>
using namespace std;

#ifndef __DAO_hpp__
#define __DAO_hpp__

#include "AbsDAO.hpp"

namespace Model
{
	// class AbsDAO;
	class DAO;
}

namespace Model
{
	class DAO: public Model::AbsDAO
	{

		public: DAO();

		public: void dodajWpisDoRejestru(String pZdarzenie);

		public: int dodajKurs();

		public: void edytujKurs(string pKurs);

		public: string znajdzKurs(int pIdKursu);

		public: void edytujKierowce(bool pStatusKierowcy[] );

		public: string znajdzKierowce(int pIdKierowcy);

		public: string* znajdzKierowcow(int pIdKursu);

		public: void dodajPowiadomienie(int pIdKierowcow[] , string pPowiadomienie);

		public: string* znajdzPowiadomienia(int pIdKierowcy);

		public: void dodajIncydent(string pIncydent);

		public: string* znajdzIncydenty();

		public: void dodajWpisDoRejestruZdarzen(string pZdarzenie);
	};
}

#endif
