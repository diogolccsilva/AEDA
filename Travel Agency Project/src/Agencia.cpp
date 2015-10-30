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

vector<Viagem> Cliente::getViagens() const{
	return viagens;
}

int Cliente::getNoViagens() const{
	return viagens.size();
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

Comercial::Comercial(string nome,int noviagens):Cliente(nome,noviagens),noparticipantes(0) {
	// TODO Auto-generated constructor stub
}

Comercial::~Comercial() {
	// TODO Auto-generated destructor stub
}

void Comercial::addViagem(Viagem viagem,int noparticipantes){
	viagens.push_back(viagem);
	this->noparticipantes += noparticipantes;
}

int Comercial::getMedParticipantes() const{
	return noparticipantes/viagens.size();
}

float Comercial::Desconto(){

	float desconto=0;

	if(noviagens > 5 && getMedParticipantes()>10)
	{
		desconto = 0.5;
	}

	if (noviagens > 5 && getMedParticipantes() > 15)
	{
		desconto=0.10;
	}

	return desconto;
}

/* Class: Viagem
 *>
 *
 *
 */

<<<<<<< HEAD
Viagem::Viagem(Itinerario itinerario,Alojamento alojamento,float preco):itinerario(itinerario),alojamento(alojamento),preco(preco) {
=======
Viagem::Viagem(Itinerario Itinerario,Alojamento alojamento,float preco,tm data):Itinerario(Itinerario),alojamento(alojamento),preco(preco),data(data) {
>>>>>>> origin/master
	// TODO Auto-generated constructor stub
}

Viagem::~Viagem() {
	// TODO Auto-generated destructor stub
}

float Viagem::getPreco() const{
	return preco;
}

Itinerario Viagem::getItinerario(){
	return itinerario;
}

Alojamento Viagem::getAlojamento(){
	return alojamento;
}

/* Class: Itinerario
 *
 *
 *
 */

Itinerario::Itinerario(Cidade origem,Cidade destino):origem(origem),destino(destino) {
	// TODO Auto-generated constructor stub
}

Itinerario::~Itinerario() {
	// TODO Auto-generated destructor stub
}

vector<Troco> Itinerario::getTrocos(){
	return trocos;
}

Cidade Itinerario::getOrigem(){
	return origem;
}

Cidade Itinerario::getDestino(){
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

Cidade Troco::getCidadeOrigem() const{
	return origem;
}

Cidade Troco::getCidadeDestino() const{
	return destino;
}

Transporte Troco::getTransporte() const{
	return transporte;
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

Alojamento::Alojamento(string tipo, string nome):tipo(tipo),nome(nome) {
	// TODO Auto-generated constructor stub
}

Alojamento::~Alojamento() {
	// TODO Auto-generated destructor stub
}

