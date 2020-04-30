/*	Ejercicio #2	*/
#include <fstream>
#include <iostream>
#include <string>
#include <sstream> 
#include <regex>
#include <iomanip> 

void insert_data_db();
void mp();
void leer_data_db();
using namespace std;

/*struct estudiante {
	int id;
	string nombre;
	float nota;	
};*/

int main(){	
	mp();
	//return 0;	
}
void mp(){
	int resp;
	//string nombrearchivo;
	//cout<<"Indique nombre de archivo: ";
	//getline(cin,nombrearchivo);
	
	do {
		system("CLS");
		cout<<"________________________________________"<<"\n"<<"\n";
		cout<<"	MENU PRINCIPAL DE ESTUDIANTES	"<<"\n";
		cout<<"________________________________________"<<"\n"<<"\n";
		cout<<" 1 - Registro "<<"\n";
		cout<<" 2 - Reporte "<<"\n";
		cout<<" 3 - Salir"<<"\n";
		cout<<"________________________________________"<<"\n"<<"\n";
		cout<<" Selecciona una opcion: ";
		cin>>resp;
		if (resp==1){		
			system("CLS");
			insert_data_db();			
		}
		else if (resp==2){		
			system("CLS");
			leer_data_db();
		}			
		else if (resp==3)
			break;
		else 
			break;
		
	} while(resp!=3);	
}

void insert_data_db(){
	//declaracion de variables
	int iid;
	string inombre;
	float inota;
	ofstream db;

	system("CLS");
	//Ingreso de datos
	cout<<"______________________________________________"<<"\n"<<"\n";
	cout<<"	REGISTRO DE ESTUDIANTES	"<<"\n";
	cout<<"______________________________________________"<<"\n"<<"\n";
	cout<<"Identificacion de estudiante: "<<endl;
	cin>>iid;
	//cin.ignore();
	fflush(stdin);
	cout<<"Nombre del Estudiante: "<<endl;
	getline(cin,inombre);
	fflush(stdin);	
	cout<<"Nota del Estudiante: "<<endl;
	cin>>inota;
	//reemplaca espacios en blanco " " con "_"	
	const auto obj = regex{ " " };
    const auto repl = string{ "_" };
    const auto valor = inombre;
 	//
	//Insercion de datos a un archivo
	try {
		db.open("HT2_EJERCICIO_02.txt",ios::app);
		db<<iid<<"\t"<<regex_replace(valor, obj, repl)<<"\t"<<inota<<endl;   //"|"
		db.close();
	}
	catch(exception X){
		cout<<"	ERROR AL CARGAR EL ARCHIVO...	"<<endl;
		system("Pause");
	}	
}
void leer_data_db(){
	//declaracion de variables
	int oid,i,mayorid;
	string onombre;
	float onota;	
	string linea;
	float suma= 0;
	int mayornota = -1;
	
	ifstream db;	
	try{
		db.open("HT2_EJERCICIO:02.txt",ios::in);	
		cout<<"__________________________________________________"<<"\n"<<"\n";
		cout<<"		DATOS DE LOS ESTUDIANTES	"<<endl;
		cout<<"__________________________________________________"<<"\n"<<"\n";
		cout<<"	Id	|"<<"	Nombre		|"<<"	Nota	|"<<endl;		
		while (db>>oid>>onombre>>onota){
			//reemplaca "_" con " "	<-espacios en blanco
			const auto obj = regex{ "_" };
    		const auto repl = string{ " " };
    		const auto valor = onombre;
			//
			cout<<setw(3)<<oid<<"		|"<<setw(18)<<regex_replace(valor, obj, repl)<<"	|	"<<setw(4)<<onota<<"	|	"<<endl;
			i++;					
			suma+=onota;
//			system("Pause");
			if (onota>mayornota){
				mayornota=onota;
				mayorid =oid;
			}
		}	
		db.close();	
		
		cout<<"\n";
		cout<<"PROMEDIO GLOBAL: "<<suma/i<<endl;
		cout<<"ID del estudiante con nota mas alta: "<<setw(3)<<mayorid<<"\n"<<" - Nota mas alta: "<<setw(3)<<mayornota<<endl;
		system("Pause");
	}
	catch(exception& X){
		cout<<"	ERROR AL CARGAR EL ARCHIVO..."<<endl;
		cout<<"ERROR: "<<X.what()<<endl;
		system("Pause");
	}
	
}
