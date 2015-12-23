/*
 * Transporte.cpp
 *
 *  Created on: 20/12/2015
 *      Author: Rita
 */

#include "Transporte.h"

/* Class: Transporte
 *
 *
 *
 */

Transporte::Transporte(string tipo) :
		tipo(tipo) {
}

Transporte::~Transporte() {
}

string Transporte::getTipo() const {
	return tipo;
}

