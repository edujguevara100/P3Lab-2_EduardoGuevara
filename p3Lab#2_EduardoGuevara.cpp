#include <iostream>
	#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;
#define PI 3.14159265

//Evalua si el numero ingresado por el usuario es triangular o no
bool numTriangular(int);
//Menu de todas las posibles operaciones
int menu();
//Generador del random
int ranGen();
//Retorna el numero Triangular anterior al numero ingresado
int numTAnterior(int);
//Calcula Angulos del Triangulo
void Calculos();
//Serie de Catalan
void serieC();
//Calcula el area del tiangulo
double areaT(double,double,double);

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
			      	rantriang = numTriangular(random);
				cout<<random<<endl;
				if (rantriang) {
					cout<<"El numero aleatorio es Triangular"<<endl;
				}else{
					cout<<"El numero aleatorio no es Triangular"<<endl;
				}
				break;
			case 3:
				int numero;
				cout<<"Ingrese un numero para obtener el triangular anterior a ese"<<endl;
				cin>>numero;
				int Triangularant;
				Triangularant = numTAnterior(numero);
				cout<<"El numero Triangular anterior(o igual) a "<<numero<<" es: "<<Triangularant<<endl;
				break;
			case 4:
				Calculos();
				break;
			case 5:
				serieC();
				break;
		}
	}
	return 0;
}

bool numTriangular(int t){
	int acum = 0;
	for (int i = 1; acum < t; i++){
		if (acum < t) {
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

int numTAnterior(int t){
	int acum = 0;
	for (int i = 1; i < t; i++){
		if (acum < t){
			acum += i;
			if ( acum > t ){
				return acum -= i;
			}else if(acum == t){
				return acum;
			}
		}
	}
}

void Calculos() {
	double a;
	double b;
	double c;
	double angC;
	double angB;
	double angA;
	double area;
	double s;
	double alturaA;
	double alturaB;
	double alturaC;

	cout<<"Ingrese la medida del primer lado(a): "<<endl;
	cin>>a;
	cout<<"Ingrese la medida del segundo lado(b): "<<endl;
	cin>>b;
	cout<<"Ingrese la medida del tercer lado(c): "<<endl;
	cin>>c;

	angA = acos((-(a*a)+(c*c)+(b*b))/(2*c*b));
	angA = angA*180;
	angA = angA/PI;
	cout<<"Angulo A: "<<angA<<" grados"<<endl;
	
	angB = acos((-(b*b)+(a*a)+(c*c))/(2*a*c));
	angB = angB*180;
	angB = angB/PI;
	cout<<"Angulo B: "<<angB<<" grados"<<endl;

	angC = acos((-(c*c)+(a*a)+(b*b))/(2*a*b));
	angC = angC*180;
	angC = angC/PI;
	cout<<"Angulo C: "<<angC<<" grados"<<endl;
	
	//s = (a+b+c)/2;
	//area = sqrt(s*(s-a)*(s-b)*(s-c));
	cout<<"El area del Triangulo es: "<<areaT(a,b,c)<<endl;
	if (angA == 90){
		cout<<"Es triangulo Rectangulo"<<endl;
	}else if(angB == 90){
		cout<<"Es Triangulo Rectangulo"<<endl;
	}else if(angC == 90){
		cout<<"Es Triangulo Rectangulo"<<endl;
	}else{
		cout<<"No es Triangulo Rectangulo"<<endl;
	}
	alturaA = (2*area)/a;
	alturaB = (2*area)/b;
	alturaC = (2*area)/c;

	cout<<"Altura a : "<<alturaA<<endl;
	cout<<"Altura b : "<<alturaB<<endl;
	cout<<"Altura c : "<<alturaC<<endl;
}

double areaT(double a, double b, double c){
	double s;
       	s = (a+b+c)/2;
	double area;
	area = sqrt(s*(s-a)*(s-b)*(s-c));
	return area;
}

void serieC(){
	int conta = 1;
	cout<<"Quede picado con el triangulo no lo pude resolver"<<endl;
	cout<<"Ingrese un numero"<<endl;
	int numero;
	cin>>numero;
	int esp;
	esp = numero-1;
	for (int i = 0; i < numero; i++){
		for (int b = 0; b<esp;b++){
			cout<<" ";
		}	
		esp--;
		for (int a = 0; a < conta; a++){
			cout<<"*";
		}
		conta+=2;
		cout<<endl;
	}
}
