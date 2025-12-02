#include <exception>
#include <string>
using namespace std;

#ifndef __Incydent_hpp__
#define __Incydent_hpp__

namespace Model
{
	class Incydent;
}

namespace Model
{
	class Incydent
	{
		private: int _typIncydentu;
		private: string _opisIncydentu;

		public: Incydent(int pTypIncydentu, string pOpisIncydentu);

		public: int dajTypIncydentu();

		public: string dajOpisIncydentu();

		public: string opisz();
	};
}

#endif
