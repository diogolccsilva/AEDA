
#include "Itinerario.h"

/* Class: Itinerario
 *
 *
 *
 */

Itinerario::Itinerario(Cidade* origem, Cidade* destino) :
		origem(origem), destino(destino) {

}

Itinerario::~Itinerario() {
	// TODO Auto-generated destructor stub
}

void Itinerario::addTroco(Troco troco) {
	trocos.push_back(troco);
}

vector<Troco> Itinerario::getTrocos() {
	return trocos;
}

Cidade* Itinerario::getOrigem() const {
	return origem;
}

Cidade* Itinerario::getDestino() const {
	return destino;
}
