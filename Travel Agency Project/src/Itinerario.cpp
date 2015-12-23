
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

tm* Itinerario::getData() const{
	return trocos[0].getData();
}
