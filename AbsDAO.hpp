#include <exception>
#include <string>
using namespace std;

#ifndef __AbsDAO_hpp__
#define __AbsDAO_hpp__

namespace Model
{
	class AbsDAO;
}

namespace Model
{
	class AbsDAO
	{

		public: void dodajWpisDoRejestru(string pZdarzenie);

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
