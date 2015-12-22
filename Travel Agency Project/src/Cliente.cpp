/*
 * Cliente.cpp
 *
 *  Created on: 20/12/2015
 *      Author: Rita
 */

/* Class: Cliente
 *
 *
 *
 */

#include "Cliente.h"

Cliente::Cliente() :
		nome(""), email(""), morada("") {

}

Cliente::Cliente(string nome, string email, string morada) :
		nome(nome), email(email), morada(morada) {

}

Cliente::~Cliente() {

}

int Cliente::getNoViagens() const {
	return viagens.size();
}

string Cliente::getNome() const {
	return nome;
}

string Cliente::getEmail()const
{
	return email;
}

void Cliente::setEmail(string e)
{
	email=e;
}

string Cliente::getMorada() const
{
	return morada;
}

void Cliente::setMorada(string m)
{
	morada=m;
}

bool Cliente::operator==(const Cliente& cliente) const {
	return (nome == cliente.nome);
}

void Cliente::addViagem(Viagem* v) {
	viagens.push_back(v);
}

vector<Viagem*> Cliente::getViagens() const {
	return viagens;
}

//TODO usar templates talvez para ver se imprime o tipo direito
ostream & operator<<(ostream & o, const Cliente & c) {
	o << "Nome: " << c.getNome() << ";\n" << "Tipo: " << c.getTipo() << ";\n"
			<< "No de Viagens: " << c.getNoViagens() << ";\n";
	return o;
}

bool Cliente::operator<(const Cliente& a1, const Cliente& a2)
{
	if (a1.pontos < a2.pontos)
		return true;
	else
		return false;
}

void Cliente::setQeue()
{
	vector<Cliente> ouro = NULL;
	vector<Cliente> bronze = NULL;
	vector<Cliente> prata = NULL;
	frequenciaviajantes.push(bronze);
	frequenciaviajantes.push(prata);
	frequenciaviajantes.push(ouro);
}

void Cliente::addPontosCliente (Cliente c)
{
	vector<Cliente> tempouro, tempprata, tempbronze;
	int p = c.pontos;
	if (p>=20)
		frequenciaviajantes.top().push_back(c);
	if (p<20)
	{
		tempouro = frequenciaviajantes.top();
		frequenciaviajantes.pop();
		tempprata = frequenciaviajantes.top();
		if (p>10)
		{
			tempprata.push_back(c);
			frequenciaviajantes.pop();
			tempbronze = frequenciaviajantes.top();
			frequenciaviajantes.pop();
		}
		else
		{
			frequenciaviajantes.pop();
			tempbronze = frequenciaviajantes.top();
			tempbronze.push_back(c);
			frequenciaviajantes.pop();
		}

		frequenciaviajantes.push(tempbronze);
		frequenciaviajantes.push(tempprata);
		frequenciaviajantes.push(tempouro);
	}
}

