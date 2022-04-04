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
	this->tamanioJugadores=0;
}
/*Metodo recorrer para lista simple*/
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
/*Metodo vacia verificador de que la lista no venga o este vacia*/
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
/*Metodo vacia verificador de que la lista de jugadores no venga o este vacia*/
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
/*Metodo recorrer para lista simple de jugadores*/
void Lista::RecorrerJugador()
{
	OrdenarJugadores();
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
		cout<<"posicion "<<aux->posicion<<endl;
		aux = aux->siguiente;

	}

}
/*Inserta unicamente cuando es el primer dato*/
void Lista::InsertarVacia(int valor)
{
	Nodo* nuevo = new Nodo();
	nuevo->valor = valor;
	nuevo->siguiente = this->frente;
	this->frente = nuevo;
	this->final = nuevo;
	this->tamanio++;

}
/*Inserta unicamente cuando es el primer dato*/
void Lista::InsertarVaciaJugador(Jugador j, int pos)
{
	Jugador* nuevo = new Jugador(pos);
	nuevo->nombre = j.nombre;
	nuevo->puntos = j.puntos;
	nuevo->tiempo = j.tiempo;
	nuevo->posicion = j.posicion;
	nuevo->siguiente = this->frenteJ;
	this->frenteJ = nuevo;
	this->finalJ = nuevo;

}
/*Inserta datos al final de la lista*/
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
/*Inserta datos al final de la lista*/
void Lista::InsertarFinalJugador(Jugador j, int pos)
{
	if (EstaVaciaJugador() == true)
	{
		InsertarVaciaJugador(j,pos);
		this->tamanioJugadores++;
	}
	else
	{
		Jugador* nuevo = new Jugador(pos);
		nuevo->nombre = j.nombre;
		nuevo->puntos = j.puntos;
		nuevo->tiempo = j.tiempo;
		nuevo->posicion = j.posicion;
		Jugador* aux;
		aux = this->finalJ;
		aux->siguiente = nuevo;
		this->finalJ = nuevo;
		this->tamanioJugadores++;

	}
}
/*Metodo para obtener por posicion el valor de la lista*/
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
/*Metodo de ordenamiento para los reportes de los jugadores*/
void Lista::OrdenarJugadores()
{
	int temp;
	double tiempo1;
	string nombre1;
	for (Jugador* i = frenteJ; i->siguiente != NULL; i = i->siguiente) {
		for (Jugador* j = i->siguiente; j != NULL; j = j->siguiente) {
			if (i->puntos < j->puntos) { // "< de Mayor a menor" y "> de menor a mayor"
				temp = i->puntos;
				tiempo1 = i->tiempo;
				nombre1 = i->nombre;

				i->puntos = j->puntos;
				i->tiempo = j->tiempo;
				i->nombre = j->nombre;

				j->puntos = temp;
				j->tiempo = tiempo1;
				j->nombre = nombre1;



			}
		}
	}

	// Imprime el Orden de los jugadores
	int i = 1;
	Jugador* aux = frenteJ;
	printf("\n    Reportes: ");
	cout << "NOMBRE->" << "PUNTOS->" << "TIEMPO->" << endl;
	while (aux != NULL) {
		
		cout << i << ". " << aux->nombre << " " << aux->puntos << " " << aux->tiempo << "seg " << endl;
		aux = aux->siguiente;
		i++;
	}
	if (i == 0)
		printf("\n\t La lista esta vacia...");
	
}
/*Metodo que nos devuele el valor de la posicion para poder se cambiados
si existen datos mayores o menores*/
int Lista::DevolverPosicion(string nombre)
{
	int temp;
	double tiempo1;
	string nombre1;
	for (Jugador* i = frenteJ; i->siguiente != NULL; i = i->siguiente) {
		for (Jugador* j = i->siguiente; j != NULL; j = j->siguiente) {
			if (i->puntos < j->puntos) { // "< de Mayor a menor" y "> de menor a mayor"
				temp = i->puntos;
				tiempo1 = i->tiempo;
				nombre1 = i->nombre;

				i->puntos = j->puntos;
				i->tiempo = j->tiempo;
				i->nombre = j->nombre;

				j->puntos = temp;
				j->tiempo = tiempo1;
				j->nombre = nombre1;



			}
		}
	}

	// Imprime el Orden de los jugadores
	int i = 1;
	Jugador* aux = frenteJ;
	printf("\n    Reportes: ");
	while (aux != NULL) {
		if (aux->nombre == nombre)
		{
			return i;
		}
		aux = aux->siguiente;
		i++;
	}
	if (i == 0)
		printf("\n\t La lista esta vacia...");
	return i;
}
/*Metodo limpiador , vacia la lista */
void Lista::limpiar()
{
	this->frente = NULL;
	this->final = NULL;
	this->tamanio = -1;
}
