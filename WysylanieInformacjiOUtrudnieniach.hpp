#include <exception>
#include <string>
using namespace std;

#ifndef __WysylanieInformacjiOUtrudnieniach_hpp__
#define __WysylanieInformacjiOUtrudnieniach_hpp__

#include "AbsModel.hpp"

class AbsModel;
namespace Kontroler
{
	class WysylanieInformacjiOUtrudnieniach;
}

namespace Kontroler
{
	class WysylanieInformacjiOUtrudnieniach
	{
		private: Model::AbsModel _absModel;

		public: void wyslanieInformacjiOUtrudnieniach(Model::AbsModel pModel, int pTypIncydentu, string pOpisIncydentu);

		private: int* wyborIdKursow();
	};
}

#endif
