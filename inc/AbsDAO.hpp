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
		public: virtual ~AbsDAO() = default;

		public: virtual void dodajWpisDoRejestru(string pZdarzenie) = 0;

		public: virtual void dodajKurs(string pKurs) = 0;

		public: virtual void edytujKurs(string pKurs) = 0;

		public: virtual string znajdzKurs(int pIdKursu) = 0;

		public: virtual vector<string> znajdzKursy(int pIdPrzystanku) = 0;

		public: virtual void edytujKierowce(int pIdKierowcy, int pIdKursu) = 0;

		public: virtual string znajdzKierowce(int pIdKierowcy) = 0;

		public: virtual vector<string> znajdzKierowcow(int pIdKursu) = 0;

		public: virtual void dodajPowiadomienie(vector<int> pIdKierowcow , string pPowiadomienie) = 0;

		public: virtual vector<string> znajdzPowiadomienia(int pIdKierowcy) = 0;

		public: virtual void dodajIncydent(string pIncydent) = 0;

		public: virtual vector<string> znajdzIncydenty() = 0;

		public: virtual void dodajWpisDoRejestruZdarzen(string pZdarzenie) = 0;
	};
}

#endif
