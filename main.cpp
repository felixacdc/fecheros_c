#include <iostream>
#include <fstream>
#include <cstring>
#include <string.h>

using namespace std;

void LeerArchivo();
void Ingresar();
void Modificar();
void Eliminar();
void Mostrar();
void EscribirEnArchivo();
 
struct Alumno {
   char nombre[32];
   int edad;
   float altura;
}alumnos[100];

int cantidad = 0;

int main() {
	LeerArchivo();
	Mostrar();
	Ingresar();
	EscribirEnArchivo();
   	
	return 0;
}

void LeerArchivo() {
	fstream fic;
	fic.open("alumnos.dat",ios::in);	
	fic.read((char*)&alumnos[cantidad],sizeof(Alumno)); 
	
	while(!fic.eof()){
		fic.read((char*)&alumnos[cantidad],sizeof(Alumno));
		cantidad++;	
	}
	
	fic.close();
}

void EscribirEnArchivo() {
	ofstream file;
	file.open("alumnos.dat");
	
	if (!file)
	{
		cout<<"Cannot load file"<<endl;
	} else {
		for (int i=0; i < cantidad; i++) {
			file<<alumnos[i].nombre
			<<alumnos[i].edad
			<<alumnos[i].altura;	
			cout<<" Member no "<<i<<"stored"<<endl;
		}
		
		file.close();
	}
	/*file.open("alumnos.dat", ios::out);
	if(file)
	{
			file.write((char*)&alumnos,sizeof(Alumno));
	
	}
	else
	cout <<"Error al abrir el archivo!\n";
	file.close();*/
}

void Ingresar() {
	cout<<"****** Ingreso ********"<<cantidad;
	cout<<"Nombre: ";
	cin>>alumnos[cantidad].nombre;
	cout<<"Edad: ";
	cin>>alumnos[cantidad].edad;
	cout<<"Altura: ";
	cin>>alumnos[cantidad].altura;
	cantidad++;
}

void Modificar() {
		
}

void Eliminar() {
		
}

void Mostrar() {
	for(int i = 0; i < cantidad; i++) {
		cout<<"Nombre: "<<alumnos[i].nombre<<endl;
		cout<<"Edad: "<<alumnos[i].edad<<endl;
		cout<<"Altura: "<<alumnos[i].altura<<endl<<endl;		
	}
}
