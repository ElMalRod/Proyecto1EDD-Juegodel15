#include "Lista.h"


Lista::Lista()
{
	this->frente = NULL;
	this->final = NULL;
	this->tamanio = -1;
}
string Lista::Recorrer()
{
	string c = "";
	Nodo* aux;
	aux = this->frente;
	while (aux != NULL)
	{
		if (aux == NULL)
		{
			return c;
		}
		else
		{
			c = c + to_string(aux->valor) + " ";
			aux = aux->siguiente;
		}

	}
	return c;
}

bool Lista::EstaVacia()
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
void Lista::InsertarVacia(int valor)
{
	Nodo* nuevo = new Nodo();
	nuevo->valor = valor;
	nuevo->siguiente = this->frente;
	this->frente = nuevo;
	this->final = nuevo;
	this->tamanio++;

}

void Lista::InsertarFinal(int valor)
{
	if (EstaVacia() == true)
	{
		InsertarVacia(valor);
	}
	else
	{
		Nodo* nuevo = new Nodo();
		nuevo->valor = valor;
		Nodo* aux;
		aux = this->final;
		aux->siguiente = nuevo;
		this->final = nuevo;
		this->tamanio++;

	}
}

int Lista::ObtenerXpos(int pos)
{
	Nodo* aux = this->frente;
	int cont = 0;
	while (aux != NULL)
	{
		if (aux == NULL)
		{
			return aux->valor;
		}
		else
		{
			if (cont == pos)
			{
				return aux->valor;
			}
			cont++;
			aux = aux->siguiente;
		}
	}

}
void Lista::limpiar()
{
	this->frente = NULL;
	this->final = NULL;
	this->tamanio = -1;
}
