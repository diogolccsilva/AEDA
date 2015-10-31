/*
 * Agencia.cpp
 *
 *  Created on: Oct 8, 2015
 *      Author: Diogo
 */

#include "Agencia.h"

int Viagem::sid = 0;

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

bool Agencia::addCliente(Cliente c){
	typename vector<Cliente>::const_iterator it;
	it = find(clientes.begin(),clientes.end(),c);
	if (it!=clientes.end())
		return false; //change to a throw eventually
	else
		clientes.push_back(c);
	return true;
}

vector<Cliente> Agencia::getClientes(){
	return clientes;
}

void Agencia::sortClientes(){

}

bool Agencia::addViagem(Viagem v) {
	typename vector<Viagem>::const_iterator it;
	it = find(viagens.begin(), viagens.end(), v);
	if (it != viagens.end())
		return false; //change to a throw eventually
	else
		viagens.push_back(v);
	return true;
}

/* Class: Cliente
 *
 *
 *
 */

Cliente::Cliente(string nome):nome(nome) {
	// TODO Auto-generated constructor stub
}

Cliente::~Cliente() {
	// TODO Auto-generated destructor stub
}

int Cliente::getNoViagens() const{
	return viagens.size();
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

vector<Viagem*> Cliente::getViagens() const{
	return viagens;
}

ostream & operator<<(ostream & o, const Cliente & c){
	o << "Nome: " << c.getNome() << ";\n" << "Tipo: " << c.getTipo() << ";\n" << "No de Viagens: " << c.getNoViagens() << ";\n";
	return o;
}

/* Class: Particular
 *
 *
 *
 */

Particular::Particular(string nome):Cliente(nome) {
	// TODO Auto-generated constructor stub
}

Particular::~Particular() {
	// TODO Auto-generated destructor stub
}

string Particular::getTipo() const{
	return "particular";
}

/* Class: Comercial
 *
 *
 *
 */

Comercial::Comercial(string nome):Cliente(nome),noparticipantes(0) {
	// TODO Auto-generated constructor stub
}

Comercial::~Comercial() {
	// TODO Auto-generated destructor stub
}

string Comercial::getTipo() const{
	return "comercial";
}

void Comercial::addViagem(Viagem* v,int np){
	viagens.push_back(v);
	this->noparticipantes += noparticipantes;
}

int Comercial::getMedParticipantes() const{
	return noparticipantes/viagens.size();
}

float Comercial::desconto(){

	float desconto=0;

	if (viagens.size() > 5 && getMedParticipantes()>10)
	{
		desconto = 0.5;
	}

	if (viagens.size() > 5 && getMedParticipantes() > 15)
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

Viagem::Viagem(Itinerario itinerario,Alojamento* alojamento,float preco,tm data):itinerario(itinerario),alojamento(alojamento),preco(preco),data(data),id(sid++) {
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

Alojamento* Viagem::getAlojamento(){
	return alojamento;
}

int Viagem::getId() const{
	return id;
}

bool Viagem::operator ==(const Viagem v){
	if (this->getId() == v.getId())
	{
		return true;
	}
	return false;
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

void Pais::addCidade(Cidade cidade) {
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
