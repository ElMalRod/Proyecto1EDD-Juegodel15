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
	ListaMatriz(int n);
	bool EstaVacia();
	void InsertarVacia(MatrizOrtogonal* matriz);
	void InsertarFinal(MatrizOrtogonal* matriz);
	MatrizOrtogonal* ObtenerXpos(int pos);
	void Recorrer();


};
#endif LISTAMATRIZ