#include <exception>
#include <string>
using namespace std;

#include "KursRozpoczety.hpp"
#include "AbsKurs.hpp"
#include "KartaKursu.hpp"

Model::KursRozpoczety::KursRozpoczety(Model::AbsKurs pKurs, int pIdKierowcy) : Model::KartaKursu(pKurs), _idKierowcy(pIdKierowcy) {
}

string Model::KursRozpoczety::opisz() {
	throw "Not yet implemented";
}

