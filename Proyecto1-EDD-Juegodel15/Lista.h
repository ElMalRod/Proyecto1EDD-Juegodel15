#pragma once
#include "Nodo.h"
#include "Jugador.h"
#include <string>
#include <cstdlib>
using namespace std;
/*Esta lista es utilizada para guardar los datos ingresados a la matriz
tambien es utilizada para la lista de jugadores */
class Lista
{
public:
	Nodo* frente;
	Nodo* final;
	Jugador* frenteJ;
	Jugador* finalJ;
	int tamanio;
	int tamanioJugadores;
	Lista();
	Lista(int n);
	bool EstaVacia();
	bool EstaVaciaJugador();
	string Recorrer();
	void RecorrerJugador();
	int ObtenerXpos(int pos);
	void InsertarVacia(int valor);
	void InsertarVaciaJugador(Jugador j, int pos);
	void InsertarFinal(int valor);
	void OrdenarJugadores();
	void InsertarFinalJugador(Jugador j, int pos);
	void ReporteOrdenJugadores();
	int DevolverPosicion(string nombre);
	void limpiar();

};