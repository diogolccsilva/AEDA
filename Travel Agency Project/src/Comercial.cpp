/*
 * Comercial.cpp
 *
 *  Created on: 20/12/2015
 *      Author: Rita
 */

#include "Cliente.h"
#include "Comercial.h"

/* Class: Comercial
 *
 *
 *
 */

Comercial::Comercial(string nome, string email, string morada,
		int noparticipantes) :
		Cliente(nome, email, morada), noparticipantes(noparticipantes) {

}

Comercial::~Comercial() {

}

string Comercial::getTipo() const {
	return "Comercial";
}

int Comercial::getNoParticipantes() const {
	return noparticipantes;
}

void Comercial::addViagem(Viagem* v, int np) {
	Cliente::addViagem(v);
	this->noparticipantes += noparticipantes;
}

int Comercial::getMedParticipantes() const {
	return noparticipantes / getViagens().size();
}

float Comercial::desconto() const {
	if (getViagens().size() > 5 && getMedParticipantes() > 10) {
		return 0.5;
	}
	if (getViagens().size() > 5 && getMedParticipantes() > 15) {
		return 0.10;
	}
	return 0;
}

