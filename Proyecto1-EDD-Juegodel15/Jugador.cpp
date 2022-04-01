#include "Jugador.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

Jugador::Jugador()
{
	this->nombre="";
	this->puntos = 0;
	this->tiempo = 0;
}

 void Jugador::ingresardatos(string nombre, int puntos, double tiempo)
{
	 this->nombre = nombre;
	 this->puntos = puntos;
	 this->tiempo = tiempo;
}

void Jugador::ingresarPuntos(int p)
{
	puntos = p;
}
void Jugador::ingresarTiempo(double p)
{
	tiempo = p;
}

void Jugador::imprimirdatos() {

	cout << "NOMBRE						"<<"PUNTOS					"<<"TIEMPO					"<<endl;
	cout << " "<<nombre <<" "<<puntos << "		"<<tiempo << endl;

}
