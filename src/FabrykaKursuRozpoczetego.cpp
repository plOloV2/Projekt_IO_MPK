#include <exception>
#include <string>
using namespace std;

#include "FabrykaKursuRozpoczetego.hpp"
#include "AbsKurs.hpp"
#include "AbsFabrykaKursu.hpp"

Model::FabrykaKursuRozpoczetego::FabrykaKursuRozpoczetego(Model::AbsKurs* pKurs) {
}

Model::AbsKurs* Model::FabrykaKursuRozpoczetego::utworzKurs(string pOpis) {
	throw "Not yet implemented";
}

