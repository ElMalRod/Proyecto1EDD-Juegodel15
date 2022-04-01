#pragma once
#include "Nodo.h"
class Lista
{
public:
	Nodo* frente;
	Nodo* final;
	int tamanio;
	Lista();
	bool EstaVacia();
	string Recorrer();
	Nodo* ObtenerXvalor(int ref);
	int ObtenerXpos(int pos);
	int Obtenerpos(Nodo* ref);
	void InsertarVacia(int valor);
	void InsertarFinal(int valor);
	void limpiar();

};