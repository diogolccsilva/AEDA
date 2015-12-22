/*
 * Destino.cpp
 *
 *  Created on: 21/12/2015
 *      Author: Diogo
 */

#include "Destino.h"

Destino::Destino() :
		cidade(NULL), alojamento(NULL),viagem(NULL) {

}

Destino::Destino(float desconto, Cidade* c, Viagem* viagem,
		Alojamento* alojamento) :
		desconto(desconto), cidade(c), viagem(viagem), alojamento(alojamento) {
	// TODO Auto-generated constructor stub
	updatePreco();
}

Destino::~Destino() {
	// TODO Auto-generated destructor stub
}

bool Destino::operator<(const Destino &d1) const {
	if (cidade->getNome() != d1.cidade->getNome())
		return cidade->getNome() < d1.cidade->getNome();
	else if (cidade->getNome() == d1.cidade->getNome())
		if (preco < d1.preco)
			return true;
	return false;
}

Cidade* Destino::getCidade() const {
	return cidade;
}

Alojamento* Destino::getAlojamento() const {
	return alojamento;
}

Viagem* Destino::getViagem() const {
	return viagem;
}

float Destino::getDesconto() const{
	return desconto;
}

void Destino::updatePreco(){
	preco = viagem->getPreco() + alojamento->getPreco();
	preco -= preco*desconto/100;
}

float Destino::getPreco() const{
	return preco;
}
