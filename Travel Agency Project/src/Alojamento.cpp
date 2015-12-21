/*
 * Alojamento.cpp
 *
 *  Created on: 20/12/2015
 *      Author: Rita
 */

#include "Alojamento.h"

/* Class: Alojamento
 *
 *
 *
 */

Alojamento::Alojamento() :
		tipo(""), nome(""), preco(0) {

}

Alojamento::Alojamento(string tipo, string nome, float preco) :
		tipo(tipo), nome(nome), preco(preco) {

}

Alojamento::~Alojamento() {

}

string Alojamento::getNome() const {
	return nome;
}

string Alojamento::getTipo() const {
	return tipo;
}

float Alojamento::getPreco() const {
	return preco;
}

bool Alojamento::operator==(const Alojamento& a) const {
	return (nome == a.nome);
}

bool Alojamento::operator<(const Alojamento& a) const{
	return (preco<a.preco);
}

