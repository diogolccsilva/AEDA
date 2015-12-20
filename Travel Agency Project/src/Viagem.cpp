/*
 * Viagem.cpp
 *
 *  Created on: 20/12/2015
 *      Author: Rita
 */

#include "Viagem.h"

/* Class: Viagem
 *
 *
 *
 */

Viagem::Viagem(Itinerario itinerario, float preco, Alojamento* alojamento,
		int id) :
		itinerario(itinerario), alojamento(alojamento), preco(preco), id(id) {
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

Alojamento* Viagem::getAlojamento() const {
	//TODO add a throw eventually for non existent alojamento
	return alojamento;
}

int Viagem::getId() const {
	return id;
}

bool Viagem::operator==(const Viagem& v) const {
	return (getId() == v.getId());
}

bool Viagem::addAlojamento(Alojamento* a) {
	if (!(alojamento == new Alojamento()))
		return false; //TODO change to a throw eventually
	alojamento = a;
	return true;
}

void Viagem::delAlojamento() {
	alojamento = new Alojamento();
}

bool Viagem::changeAlojamento(Alojamento* a) {
	delAlojamento();
	return addAlojamento(a);
}

