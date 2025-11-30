#include <exception>
#include <string>
using namespace std;

#ifndef __WysyłanieInformacjiOUtrudnieniach_hpp__
#define __WysyłanieInformacjiOUtrudnieniach_hpp__

#include "AbsModel__1.hpp"
#include "IModel.hpp"

class AbsModel__1;
class IModel;
namespace Kontroler
{
	class WysyłanieInformacjiOUtrudnieniach;
}

namespace Kontroler
{
	class WysyłanieInformacjiOUtrudnieniach
	{
		private: AbsModel__1 _absModel;

		public: void wyslanieInformacjiOUtrudnieniach(IModel pModel, int pTypIncydentu, string pOpisIncydentu);

		private: int* wyborIdKursow();
	};
}

#endif
