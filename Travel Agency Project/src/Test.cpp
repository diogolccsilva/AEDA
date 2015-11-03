#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "Agencia.h"
#include <conio.h>

void thisIsATest() {
	ASSERTM("start writing tests", false);	
}

void test_Cidade(){

	Cidade c1("Paris");
	Cidade c2 ("Oslo");
	Cidade c3 ("Tokio");
	Cidade c4 ("Sidney");

	ASSERT_EQUAL("Paris",c1.getNome());
	ASSERT_EQUAL("Oslo",c2.getNome());
	ASSERT_EQUAL("Tokio",c3.getNome());
	ASSERT_EQUAL("Sidney",c4.getNome());
}

void test_Pais(){

	Pais p1 ("França");
	Pais p2 ("Noruega");
	Pais p3 ("Japao");
	Pais p4 ("Autralia");

	ASSERT_EQUAL("França",p1.getNome());
	ASSERT_EQUAL("Noruega",p2.getNome());
	ASSERT_EQUAL("Japao",p3.getNome());
	ASSERT_EQUAL("Australia",p4.getNome());

	//p1.addCidade("Paris");


}

void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	//TODO add your test here
	s.push_back(CUTE(thisIsATest));
	s.push_back(CUTE(test_Cidade));
	s.push_back(CUTE(test_Pais));
	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

void pclientes(Agencia* a){
	for (unsigned int i = 0;i < a->getClientes().size();i++)
		cout << a->getClientes()[i] << endl;
}
void addcliente(Agencia* a){
	string nome;
	char tipo;
	cout << "Nome: ";
	cin >> nome;
	cout << "Tipo ('P' ou 'C'): ";
	cin >> tipo;
	switch (tipo){
	case 'P':{
			Particular p(nome);
			a->addCliente(p);
		}
		break;
	case 'C':{
			Comercial c(nome);
			a->addCliente(c);
		}
		break;
	default:
		cout << "Tipo de cliente inexistente!" << endl;
		getch();
		return;
		break;
	}
}

void cliente(Agencia* a){
	char c;
	while (c != 27 || c != '3') {
		system("cls");
		cout << "1-	Ver clientes;" << endl;
		cout << "2- Adicionar Cliente;" << endl;
		cout << "3- Voltar;" << endl;
		c = getch();
		system("cls");
		switch (c) {
		case '1':
			pclientes(a);
			getch();
			break;
		case '2':
			addcliente(a);
			break;
		default:
			break;
		}
	}
}

void gclientes(Agencia* a){
	char c;
	while (c != 27 || c != '3') {
		system("cls");
		cout << "1- Gerir clientes;" << endl;
		cout << "2- Gerir viagens;" << endl;
		cout << "3- Gerir destinos;" << endl;
		c = getch();
		system("cls");
		switch (c) {
		case '1':
			gclientes(a);
			break;
		case '2':

			break;
		case '3':

			break;
		default:
			break;
		}
	}
}

void admin(Agencia* a){
	char c;
	while (c != 27 || c != '3') {
		system("cls");
		cout << "1- Gerir clientes;" << endl;
		cout << "2- Gerir viagens;" << endl;
		cout << "3- Gerir destinos;" << endl;
		c = getch();
		system("cls");
		switch (c) {
		case '1':

			break;
		case '2':

			break;
		case '3':

			break;
		default:
			break;
		}
	}
}

void manual(){
	string nome;
	cout << "Nome da agencia: ";
	cin >> nome;
	Agencia* a = new Agencia(nome);
	char c;
	system("cls");
	while (c!=27 || c!='3'){
		system("cls");
		cout << "1- Cliente;" << endl;
		cout << "2- Administrador;" << endl;
		cout << "3- Voltar;" << endl;
		c = getch();
		system("cls");
		switch (c) {
		case '1':
			cliente(a);
			break;
		case '2':
			admin(a);
			break;
		default:
			break;
		}
	}
}

int main(int argc, char const *argv[]){
	char c;
	while (c!='3' || c!=27){
		cout << "1- Automatico" << endl;
		cout << "2- Manual" << endl;
		cout << "3- Sair" << endl;
		c=getch();
		system("CLS");
		switch(c){
		case '1': runAllTests(argc,argv);
			break;
		case '2': manual();
			break;
		default:
			break;
		}
	}
    return 0;
}



