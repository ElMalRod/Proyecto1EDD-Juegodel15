#ifndef LISTAMATRIZ
#define LISTAMATRIZ
#pragma once
#include <string>
#include <cstdlib>
#include "matriz.h"
using namespace std;
class ListaMatriz
{
public:
	MatrizOrtogonal* frente;
	MatrizOrtogonal* final;
	int niveles;
	int xxP, yyP = 0; //posiciones de pivote
	int xxD, yyD = 0; //posiciones de dato
	ListaMatriz();
	bool EstaVacia();
	void InsertarVacia(MatrizOrtogonal* matriz, int n);
	void InsertarFinal(MatrizOrtogonal* matriz, int n);
	MatrizOrtogonal* ObtenerXpos(int pos);
	void ImprimirTablero();
	void movimientos(int n);
	void movimientosNiveles(int n);
	bool guardarPiv();
	bool guardarDato(int n);
	void moverPivote(int n);
	void moverDatos(int n);
	bool cambiarBadera(int n);
	bool verificarMovimientosNormales(int n);
	int sumarPuntos(int datos);
	void LimpiarLista();
	bool comprobarNivel();
	

};
#endif LISTAMATRIZ