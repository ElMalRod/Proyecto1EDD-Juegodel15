
#include "ListaMatriz.h"
ListaMatriz::ListaMatriz(int n)
{
	this->frente = NULL;
	this->final = NULL;
	this->niveles = -1;
}
bool ListaMatriz::EstaVacia()
{
	if (this->frente == NULL && this->final == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void ListaMatriz::InsertarVacia(MatrizOrtogonal* matriz)
{
	MatrizOrtogonal* nuevo = new MatrizOrtogonal();
	nuevo = matriz;
	nuevo->siguiente = this->frente;
	this->frente = nuevo;
	this->final = nuevo;

}

void ListaMatriz::InsertarFinal(MatrizOrtogonal* matriz )
{
	if (EstaVacia() == true)
	{
		InsertarVacia(matriz);
	}
	else
	{
		MatrizOrtogonal* nuevo = new MatrizOrtogonal();
		nuevo = matriz;
		MatrizOrtogonal* aux;
		aux = this->final;
		aux->siguiente = nuevo;
		this->final = nuevo;

	}
}
MatrizOrtogonal* ListaMatriz::ObtenerXpos(int pos)
{
	MatrizOrtogonal* aux = this->frente;
	int cont = 0;
	while (aux != NULL)
	{
		if (aux == NULL)
		{
			return aux;
		}
		else
		{
			if (cont == pos)
			{
				return aux;
			}
			cont++;
			aux = aux->siguiente;
		}
	}
	return NULL;
}

