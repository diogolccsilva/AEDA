/*
 * Viagem.cpp
 *
 *  Created on: 20/12/2015
 *      Author: Rita
 */

#include "Viagem.h"

int Viagem::sid = 0;

/* Class: Viagem
 *
 *
 *
 */

Viagem::Viagem(Itinerario itinerario, float preco, int id) :
		itinerario(itinerario), preco(preco), id(id) {
	sid++;
}

Viagem::~Viagem() {
	// TODO Auto-generated destructor stub
}

float Viagem::getPreco() const {
	return preco;
}

Itinerario Viagem::getItinerario() const {
	return itinerario;
}

int Viagem::getId() const {
	return id;
}

bool Viagem::operator==(const Viagem& v) const {
	return (id == v.id);
}
