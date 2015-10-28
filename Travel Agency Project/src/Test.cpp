#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "Agencia.h"
#include <conio.h>

void thisIsATest() {
	ASSERTM("start writing tests", false);	
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



