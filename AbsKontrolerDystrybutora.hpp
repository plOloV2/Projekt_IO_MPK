#include <exception>
using namespace std;

#ifndef __AbsKontrolerDystrybutora_hpp__
#define __AbsKontrolerDystrybutora_hpp__

namespace Kontroler
{
	class AbsKontrolerDystrybutora;
}

namespace Kontroler
{
	class AbsKontrolerDystrybutora
	{

		public: void modyfikowanieRozkladuJazdy();

		public: void wysylanieInformacjiOUtrudnieniach();
	};
}

#endif
