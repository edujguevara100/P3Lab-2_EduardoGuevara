#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

//Evalua si el numero ingresado por el usuario es triangular o no
bool numTriangular(int);
//Menu de todas las posibles operaciones
int menu();
//Generador del random
int ranGen();
//Retorna el numero Triangular anterior al numero ingresado
int numTanterior(int);

int main(){
	int t = 0;
	int opcion = 0;
	while (opcion != 6){
		switch (opcion = menu()) {
			case 1:
				cout<<"Ingrese un numero: "<<endl;
				cin>>t;
				bool estriang;
			      	estriang = numTriangular(t);
				if (estriang){
					cout<<"Es triangular"<<endl;
				}else{
					cout<<"No es triangular"<<endl;
				}
				break;
			case 2:
				int random;
			       	random = ranGen();
				bool rantriang;
			      	rantirang = numTriangular(random);
				cout<<random<<endl;
				if (estriang) {
					cout<<"El numero aleatorio es Triangular"<<endl;
				}else{
					cout<<"El numero aleatorio no es Triangular"<<endl;
				}
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
		}
	}
	return 0;
}

bool numTriangular(int t){
	int acum = 0;
	for (int i = 1; acum < t; i++){
		if (acum<=t) {
			acum += i;
		}
	}
	if(acum == t) {
		return true;
	}else{
		return false;
	}
}

int menu(){
	cout<<"1: Identificar si un numero es Triangular"<<endl
		<<"2: Identificar si un numero aleatorio es Triangular"<<endl
		<<"3: Numero Triangular Previo"<<endl
		<<"4: Area y Angulos de Triangulo"<<endl
		<<"5: Numeros de Catalan"<<endl
		<<"6: Salir"<<endl;
	int opcion;
	cin>>opcion;
	return opcion;
}

int ranGen(){
	srand(time(NULL));
	int aleatorio;
       	aleatorio = rand() % 5 + 1;
	return aleatorio;
}
