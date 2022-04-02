#include "Jugador.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

Jugador::Jugador(int pos)
{
	
	this->nombre="";
	this->puntos = 0;
	this->tiempo = 0;
	this->posicion = pos;
	this->siguiente = NULL;
}

 void Jugador::ingresardatos( string nombre, int puntos, double tiempo)
{
	 
	 this->nombre = nombre;
	 this->puntos = puntos;
	 this->tiempo = tiempo;
	 this->siguiente = NULL;//ojo
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



}
