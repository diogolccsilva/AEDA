/*
 * Agencia.cpp
 *
 *  Created on: Oct 8, 2015
 *      Author: Diogo
 */

#include "Agencia.h"

/* Class: Agencia
 *
 *
 *
 */

Agencia::Agencia(string nome):nome(nome) {
	// TODO Auto-generated constructor stub
}

Agencia::~Agencia() {
	// TODO Auto-generated destructor stub
}

string Agencia::getNome() const{
	return nome;
}

bool Agencia::addCliente(Cliente cliente){
	typename vector<Cliente>::const_iterator it;
	it = find(clientes.begin(),clientes.end(),cliente);
	if (it==clientes.end()){
		clientes.push_back(cliente);
		return true;
	}
	return false;
}

void Agencia::sortClientes(){

}

/* Class: Cliente
 *
 *
 *
 */

Cliente::Cliente(string nome,int noviagens):nome(nome),noviagens(noviagens) {
	// TODO Auto-generated constructor stub
}

Cliente::~Cliente() {
	// TODO Auto-generated destructor stub
}

int Cliente::getNoviagens() const{
	return noviagens;
}

string Cliente::getNome() const{
	return nome;
}

bool Cliente::operator ==(const Cliente cliente){
	if (this->nome==cliente.nome)
	{
		return true;
	}
	return false;
}

/* Class: Particular
 *
 *
 *
 */

Particular::Particular(string nome,int noviagens):Cliente(nome,noviagens) {
	// TODO Auto-generated constructor stub
}

Particular::~Particular() {
	// TODO Auto-generated destructor stub
}

/* Class: Comercial
 *
 *
 *
 */

Comercial::Comercial(string nome,int noviagens):Cliente(nome,noviagens) {
	// TODO Auto-generated constructor stub
}

Comercial::~Comercial() {
	// TODO Auto-generated destructor stub
}

/* Class: Viagem
 *
 *
 *
 */

Viagem::Viagem(Itenerario itenerario,Alojamento alojamento,float preco):itenerario(itenerario),alojamento(alojamento),preco(preco) {
	// TODO Auto-generated constructor stub
}

Viagem::~Viagem() {
	// TODO Auto-generated destructor stub
}

float Viagem::getPreco() const{
	return preco;
}

Itenerario Viagem::getItenerario(){
	return itenerario;
}

Alojamento Viagem::getAlojamento(){
	return alojamento;
}

/* Class: Itenerario
 *
 *
 *
 */

Itenerario::Itenerario(Cidade origem,Cidade destino):origem(origem),destino(destino) {
	// TODO Auto-generated constructor stub
}

Itenerario::~Itenerario() {
	// TODO Auto-generated destructor stub
}

vector<Troco> Itenerario::getTrocos(){
	return trocos;
}

Cidade Itenerario::getOrigem(){
	return origem;
}

Cidade Itenerario::getDestino(){
	return destino;
}

/* Class: Troco
 *
 *
 *
 */

Troco::Troco(Cidade origem,Cidade destino,Transporte transporte):origem(origem),destino(destino),transporte(transporte) {
	// TODO Auto-generated constructor stub
}

Troco::~Troco() {
	// TODO Auto-generated destructor stub
}

/* Class: Transporte
 *
 *
 *
 */

Transporte::Transporte() {
	// TODO Auto-generated constructor stub
}

Transporte::~Transporte() {
	// TODO Auto-generated destructor stub
}

/* Class: Pais
 *
 *
 *
 */

Pais::Pais(string nome):nome(nome) {
	// TODO Auto-generated constructor stub
}

Pais::~Pais() {
	// TODO Auto-generated destructor stub
}

void Pais::AddCidade(Cidade *cidade) {
	cidades.push_back(cidade);
}

string Pais::getNome() const{
	return nome;
}

/* Class: Cidade
 *
 *
 *
 */

Cidade::Cidade(string nome):nome(nome) {
	// TODO Auto-generated constructor stub
}

Cidade::~Cidade() {
	// TODO Auto-generated destructor stub
}

string Cidade::getNome() const{
	return nome;
}

/* Class: Alojamento
 *
 *
 *
 */

Alojamento::Alojamento() {
	// TODO Auto-generated constructor stub
}

Alojamento::~Alojamento() {
	// TODO Auto-generated destructor stub
}

