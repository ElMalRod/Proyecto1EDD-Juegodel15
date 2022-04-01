#pragma once
#include "Nodo.h"
#include "Jugador.h"

class Lista
{
public:
	Nodo* frente;
	Nodo* final;
	Jugador* frenteJ;
	Jugador* finalJ;
	int tamanio;
	Lista();
	Lista(int n);
	bool EstaVacia();
	bool EstaVaciaJugador();
	string Recorrer();
	void RecorrerJugador();
	int ObtenerXpos(int pos);
	void InsertarVacia(int valor);
	void InsertarVaciaJugador(Jugador j);
	void InsertarFinal(int valor);
	void InsertarFinalJugador(Jugador j);
	void limpiar();

};