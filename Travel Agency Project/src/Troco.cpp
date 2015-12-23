/*
 * Troco.cpp
 *
 *  Created on: 20/12/2015
 *      Author: Rita
 */

#include "Troco.h"

/* Class: Troco
 *
 *
 *
 */

Troco::Troco(Cidade* origem, Cidade* destino, Transporte transporte, tm data) :
		origem(origem), destino(destino), transporte(transporte), data(data) {

}

Troco::~Troco() {
}

Cidade* Troco::getCidadeOrigem() const {
	return origem;
}

Cidade* Troco::getCidadeDestino() const {
	return destino;
}

Transporte Troco::getTransporte() const {
	return transporte;
}

tm* Troco::getData() const{
	return const_cast<tm*>(&data);
}

void Troco::printData() const {
	cout << "Data: " << data.tm_mday << "/" << data.tm_mon << "/" << data.tm_year << endl;
}


