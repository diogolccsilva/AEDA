/*
 * Particular.cpp
 *
 *  Created on: 20/12/2015
 *      Author: Rita
 */

#include "Cliente.h"
#include "Particular.h"

/* Class: Particular
 *
 *
 *
 */

Particular::Particular(string nome, string email, string morada) :
		Cliente(nome, email, morada) {

}

Particular::~Particular() {

}

string Particular::getTipo() const {
	return "Particular";
}

int Particular::getNoParticipantes() const {
	return 0;
}

float Particular::desconto() const {
	return 0;
}

int Particular::getMedParticipantes() const {
	return 0;
}
