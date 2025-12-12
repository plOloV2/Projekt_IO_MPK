#include <exception>
#include <string>
#include <vector>
using namespace std;

#ifndef __Inwentarz_hpp__
#define __Inwentarz_hpp__

#include "AbsDAO.hpp"
#include "Kierowca.hpp"
#include "Powiadomienie.hpp"
#include "AbsKurs.hpp"
#include "Incydent.hpp"
#include "Kurs.hpp"
#include "KursRozpoczety.hpp"

namespace Model
{
	class AbsDAO;
	class Kierowca;
	class Powiadomienie;
	class AbsKurs;
	class Incydent;
	class Kurs;
	class Inwentarz;
	class KursRozpoczety;
}

namespace Model
{
	class Inwentarz
	{
		private: AbsDAO _dao;
		private: vector<Kierowca> _kierowcy;
		private: vector<Powiadomienie> _powiadomienia;
		private: vector<AbsKurs> _kursy;
		private: vector<Incydent> _incydenty;

		public: Inwentarz();

		public: Inwentarz(AbsDAO pDao);

		public: void modyfikujKurs(string pKurs);

		public: Kurs dajKurs(int pIdKursu);

		public: Kierowca dajKierowce(int pIdKierowcy);

		public: void modyfikujKierowce(int pIdKierowcy);

		public: Kierowca* dajKierowcow(int pIdKursu);

		public: void dodajPowiadomienie(vector<int> pIdKierowcow , string pPowiadmienie);

		public: void dodajIncydent(string pIncydent);

		public: Kurs* dajGodzinyPrzyjazdow(int pIdPrzystanku);

		public: KursRozpoczety dajKursRozpoczety(int pIdKursu);
	};
}

#endif
