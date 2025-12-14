#include <exception>
#include <string>
using namespace std;

#include "FabrykaKursu.hpp"
#include "AbsKurs.hpp"
#include "AbsFabrykaKursu.hpp"

Model::FabrykaKursu::FabrykaKursu() {
}

Model::AbsKurs* Model::FabrykaKursu::utworzKurs(string pOpis) {
	throw "Not yet implemented";
}

