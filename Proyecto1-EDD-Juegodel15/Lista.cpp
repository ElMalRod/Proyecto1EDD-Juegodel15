#include "Lista.h"


Lista::Lista()
{
	this->frente = NULL;
	this->final = NULL;
	this->tamanio = -1;
}
Lista::Lista(int n)
{
	this->frenteJ = NULL;
	this->finalJ = NULL;
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

bool Lista::EstaVaciaJugador()
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
void Lista::RecorrerJugador()
{
	cout << "Reportes" << endl;
	cout << "Nombre->Puntos->Tiempo" << endl;
	Jugador* aux;
	aux = this->frenteJ;
	if (EstaVaciaJugador() == true)
	{
		//cout<<"No hay reportes todavia" << endl;
	}
	while (aux != NULL)
	{
		cout << aux->nombre << "  " << aux->puntos << "  " << aux->tiempo << " seg" << endl;
		aux = aux->siguiente;

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

void Lista::InsertarVaciaJugador(Jugador j)
{
	Jugador* nuevo = new Jugador();
	nuevo->nombre = j.nombre;
	nuevo->puntos = j.puntos;
	nuevo->tiempo = j.tiempo;
	nuevo->siguiente = this->frenteJ;
	this->frenteJ = nuevo;
	this->finalJ = nuevo;

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

void Lista::InsertarFinalJugador(Jugador j)
{
	if (EstaVaciaJugador() == true)
	{
		InsertarVaciaJugador(j);
	}
	else
	{
		Jugador* nuevo = new Jugador();
		nuevo->nombre = j.nombre;
		nuevo->puntos = j.puntos;
		nuevo->tiempo = j.tiempo;
		Jugador* aux;
		aux = this->finalJ;
		aux->siguiente = nuevo;
		this->finalJ = nuevo;

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
