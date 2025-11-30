#include <exception>
using namespace std;

#ifndef __KontrolerDystrybutora_hpp__
#define __KontrolerDystrybutora_hpp__

#include "AbsModel__1.hpp"
#include "IModel.hpp"
#include "AbsKontrolerDystrybutora.hpp"

class AbsModel__1;
class IModel;
namespace Kontroler
{
	// class AbsKontrolerDystrybutora;
	class KontrolerDystrybutora;
}

namespace Kontroler
{
	class KontrolerDystrybutora: public Kontroler::AbsKontrolerDystrybutora
	{
		private: AbsModel__1 _absModel;

		public: KontrolerDystrybutora(IModel pModel);

		public: void modyfikowanieRozkladuJazdy();

		public: void wysylanieInformacjiOUtrudnieniach();
	};
}

#endif
