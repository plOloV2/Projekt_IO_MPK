#include <exception>
#include <string>
using namespace std;

#ifndef __Powiadomienie_hpp__
#define __Powiadomienie_hpp__

namespace Model
{
	class Powiadomienie;
}

namespace Model
{
	class Powiadomienie
	{
		private: int _idKursow[];
		private: int _typIncydentu;
		private: string _opisIncydentu;

		public: Powiadomienie(int pIdKursow[] , int pTypIncydentu, string pOpisIncydent);

		public: int* dajIdKursow();

		public: int dajTypIncydentu();

		public: string dajOpisIncydentu();

		public: string opisz();
	};
}

#endif
