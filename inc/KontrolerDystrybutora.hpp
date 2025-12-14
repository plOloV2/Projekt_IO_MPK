#include <exception>
using namespace std;

#ifndef __KontrolerDystrybutora_hpp__
#define __KontrolerDystrybutora_hpp__

#include "AbsModel.hpp"
#include "AbsKontrolerDystrybutora.hpp"

class AbsModel;
namespace Kontroler
{
	// class AbsKontrolerDystrybutora;
	class KontrolerDystrybutora;
}

namespace Kontroler
{
	class KontrolerDystrybutora: public Kontroler::AbsKontrolerDystrybutora
	{
		private: Model::AbsModel* _absModel;

		public: KontrolerDystrybutora(Model::AbsModel* pModel);

		public: void modyfikowanieRozkladuJazdy();

		public: void wysylanieInformacjiOUtrudnieniach();
	};
}

#endif
