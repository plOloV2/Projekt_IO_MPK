#include <exception>
#include <string>
using namespace std;

#ifndef __Inwentarz_hpp__
#define __Inwentarz_hpp__

#include "AbsDAO.hpp"
#include "Kierowca.hpp"
// #include "Powiadomienie.hpp"
#include "Kurs.hpp"
// #include "Incydent.hpp"

namespace Model
{
	class AbsDAO;
	class Kierowca;
	class Powiadomienie;
	class Kurs;
	class Incydent;
	class Inwentarz;
}

namespace Model
{
	class Inwentarz
	{
		private: Model::AbsDAO _dao;
		private: Model::Kierowca _kierowcy[];
		private: Model::Powiadomienie _powiadomienia[];
		private: Model::Kurs _kursy[];
		private: Model::Incydent _incydenty[];

		public: Inwentarz(Model::AbsDAO pDao);

		public: void modyfikujKurs(string pKurs);

		public: Model::Kurs dajKurs(int pIdKursu);

		public: Model::Kierowca dajKierowce(int pIdKierowcy);

		public: void modyfikujKierowce(bool pStatusKierowcy[] );

		public: Kierowcy* dajKierowcow(int pIdKursu);

		public: void dodajPowiadomienie(int pIdKierowcow[] , string pPowiadmienie);

		public: void dodajIncydent(string pIncydent);

		public: Model::Kurs* dajGodzinyPrzyjazdow(int pIdPrzystanku);
	};
}

#endif
