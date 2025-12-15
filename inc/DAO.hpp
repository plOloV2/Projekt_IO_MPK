#include <exception>
#include <string>
#include <vector>
#include <map>
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
	class DAO: public AbsDAO
	{
		private: map<int, string> _bazaKierowcow;

		private: int _ostatniNrKierowcy;
		
		private: map<int, string> _bazaKursow;

		private: int _ostatniNrKursu;
		
		private: map<int, string> _bazaIncydentow;

		private: int _ostatniNrIncydentu;
		
		private: map<int, string> _bazaPowiadomien;

		private: int _ostatniNrPowiadomienia;

		public: DAO();

		public: void dodajWpisDoRejestru(string pZdarzenie);

		public: void dodajKurs(string pKurs);

		public: void edytujKurs(string pKurs);

		public: string znajdzKurs(int pIdKursu);

		public: vector<string> znajdzKursy(int pIdPrzystanku);

		public: void edytujKierowce(int pIdKierowcy, int pIdKursu);

		public: string znajdzKierowce(int pIdKierowcy);

		public: vector<string> znajdzKierowcow(int pIdKursu);

		public: void dodajPowiadomienie(vector<int> pIdKierowcow , string pPowiadomienie);

		public: vector<string> znajdzPowiadomienia(int pIdKierowcy);

		public: void dodajIncydent(string pIncydent);

		public: vector<string> znajdzIncydenty();

		public: void dodajWpisDoRejestruZdarzen(string pZdarzenie);

		public: void wyswietlBaze();
	};
}

#endif
