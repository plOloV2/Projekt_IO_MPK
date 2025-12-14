#include <exception>
#include <string>
#include <vector>
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

		public: int dodajKurs(string pKurs);

		public: void edytujKurs(string pKurs);

		public: string znajdzKurs(int pIdKursu);

		public: void edytujKierowce(int pIdKierowcy, int pIdKursu);

		public: string znajdzKierowce(int pIdKierowcy);

		public: vector<string> znajdzKierowcow(int pIdKursu);

		public: void dodajPowiadomienie(vector<int> pIdKierowcow , string pPowiadomienie);

		public: vector<string> znajdzPowiadomienia(int pIdKierowcy);

		public: void dodajIncydent(string pIncydent);

		public: vector<string> znajdzIncydenty();

		public: void dodajWpisDoRejestruZdarzen(string pZdarzenie);
	};
}

#endif
