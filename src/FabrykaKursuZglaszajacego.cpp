#include <exception>
#include <string>
using namespace std;

#include "FabrykaKursuZglaszajacego.hpp"
#include "AbsKurs.hpp"
#include "AbsFabrykaKursu.hpp"

Model::FabrykaKursuZglaszajacego::FabrykaKursuZglaszajacego(Model::AbsKurs* pKurs) {
}

Model::AbsKurs* Model::FabrykaKursuZglaszajacego::utworzKurs(string pOpis) {
	throw "Not yet implemented";
}

