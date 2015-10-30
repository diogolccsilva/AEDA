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

	Pais p1("França");
	Pais p2 ("Noruega");
	Pais p3 ("Japao");
	Pais p4 ("Autralia");

	ASSERT_EQUAL("França",p1.getNome());
	ASSERT_EQUAL("Noruega",p2.getNome());
	ASSERT_EQUAL("Japao",p3.getNome());
	ASSERT_EQUAL("Australia",p4.getNome());

	p1.addCidade("Paris");


}

void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	//TODO add your test here
	s.push_back(CUTE(thisIsATest));
	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

void manual(){

}

int main(int argc, char const *argv[]){
	char c;
	while (c!='3' || c!=27)
	{
		cout << "1- Automatico" << endl;
		cout << "2- Manual" << endl;
		cout << "3- Sair" << endl;
		c=getch();
		switch(c){
		case '1': runAllTests(argc,argv);
			break;
		case '2': manual();
			break;
		default:
			break;
		}
		system("CLS");
	}
    return 0;
}



