
#include "ListaMatriz.h"
/*VARIABLES GLOBALES*/
int n1, n2 = 0;// compara los niveles para ver si se puede realizar el movimiento

ListaMatriz::ListaMatriz()
{
	this->frente = NULL;
	this->final = NULL;
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

void ListaMatriz::InsertarVacia(MatrizOrtogonal* matriz, int n)
{
	MatrizOrtogonal* nuevo = new MatrizOrtogonal(n);
	//nuevo = matriz;
	nuevo->c = matriz->c;
	nuevo->c = matriz->c;
	nuevo->siguiente = this->frente;
	this->frente = nuevo;
	this->final = nuevo;

}

void ListaMatriz::InsertarFinal(MatrizOrtogonal* matriz, int n )
{
	if (EstaVacia() == true)
	{
		InsertarVacia(matriz,n);
	}
	else
	{
		MatrizOrtogonal* nuevo = new MatrizOrtogonal(n);
		nuevo->c = matriz->c;
		nuevo->c = matriz->c;
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

void ListaMatriz::ImprimirTablero()
{
	
	MatrizOrtogonal* aux;
	aux = this->frente;
	if (EstaVacia() == true)
	{
		//cout<<"No hay reportes todavia" << endl;
	}
	while (aux != NULL)
	{
		aux->imprimir();
		cout << "---------------------------------------" << endl;
		aux = aux->siguiente;

	}
	
}

/*Metodo guardarpivote este metodo guarda la posicion del pivote al realizar
movimientos entre niveles (devolvera un verdadero al guardar el dato)*/
bool ListaMatriz::guardarPiv()
{
	MatrizOrtogonal* aux;
	aux = this->frente;
	int cont = 0; //contador de niveles
	
	if (EstaVacia() == true)
	{
		//cout<<"No hay reportes todavia" << endl;
	}
	while (aux != NULL)
	{
		if (aux->verificarPivoteDatos() == true)
		{
			//continuar
			//cout << "Encontro pivote en matriz " << cont << endl;
			xxP = aux->xx;
			yyP = aux->yy;
			n1 = aux->nivel;
			return true;
		}
		else {
			aux = aux->siguiente;
			
		}
		cont++;

	}
	return false;
}
/*Metodo guardardato este metodo guarda la posicion del dato al realizar 
movientos entre niveles*/
bool ListaMatriz::guardarDato(int n)
{
	MatrizOrtogonal* aux;
	aux = this->frente;
	int cont = 0; //contador de niveles

	if (EstaVacia() == true)
	{
		//cout<<"No hay reportes todavia" << endl;
	}
	while (aux != NULL)
	{
		if (aux->verificarNodoDatos(n) == true)
		{
			//continuar
			//cout << "Encontro dato en matriz " << cont << endl;
			xxD = aux->xx;
			yyD = aux->yy;
			n2 = aux->nivel;
			return true;
		}
		else {
			aux = aux->siguiente;

		}cont++;

	}
	return false;
}
/*Metodo comprobarNivel este metodo verifica el movimiento entre niveles
tomando en cuenta que se ubiquen a la par*/
bool ListaMatriz::comprobarNivel()
{
	//cout << "Nivel " <<n1+1 <<" "<<n2 <<endl;
	if (n1>n2)
	{
		int aux = n1 - n2;
		//cout << aux << endl;
		if (aux==1)
		{
			return true;
		}
		else { return false; }
	}
	else if (n1 < n2)
	{
		int aux = n2 - n1;
		//cout << aux << endl;
		if (aux == 1)
		{
			return true;
		}
		else { return false; }
	}
	return false;
}
/*Metodo une las verificaciones para poder realizar un moviemnto si se cumplen
realiza el cambio del dato*/
void ListaMatriz::movimientosNiveles(int n)
{
	
	if (guardarPiv()==true && guardarDato(n)==true)
	{
		if ((xxP== xxD) && (yyP==yyD) )
		{
			//Si se puede hacer el movimiento ------------------OJO
			//cout << "Si se puede hacer ese movimiento " << endl;
			if (comprobarNivel() == true)
			{
				//cout << "Si se puede hacer ese movimiento NIVEL" << endl;
				if (cambiarBadera(n) == true)
				{
					//cout << "Si se puede hacer ese movimiento " << endl;
					moverPivote(n);
					moverDatos(n);
				}
			}
			
		}
		else { // provar con movimiento normales
			cout << "No se puede hacer ese movimiento" << endl;
		}

	}
}
/*Cambiar bandera , cambia la bandera del dato que sera cambiado */
bool ListaMatriz::cambiarBadera(int n)
{
	MatrizOrtogonal* aux;
	aux = this->frente;
	int cont = 0; //contador de niveles

	if (EstaVacia() == true)
	{
		//cout<<"No hay reportes todavia" << endl;
	}
	while (aux != NULL)
	{
		if (aux->cambiarBanderaDatos(n) != true)
		{
			//continuar
			aux = aux->siguiente;
			cont++;
		}
		else {
			cout << "se cambio bandera " << cont << endl;
			return true;
			
		}

	}
	return false;
}
/*Metodo mover pivote este metodo mueve el espacio vacio*/
void ListaMatriz::moverPivote(int n)
{
	MatrizOrtogonal* aux;
	aux = this->frente;
	int cont = 0; //contador de niveles

	if (EstaVacia() == true)
	{
		//cout<<"No hay reportes todavia" << endl;
	}
	while (aux != NULL)
	{
		if (aux->moverPivoteNiveles(n) == true)
		{
			//continuar
			//cout << "se movio el pivote " << cont << endl;
			
		}
		else {
			aux = aux->siguiente;
			cont++;
		}

	}
}
/*Metodo mover dato mueve los datos siempre y cuando sean verificados*/
void ListaMatriz::moverDatos(int n)
{
	MatrizOrtogonal* aux;
	aux = this->frente;
	int cont = 0; //contador de niveles

	if (EstaVacia() == true)
	{
		//cout<<"No hay reportes todavia" << endl;
	}
	while (aux != NULL)
	{
		if (aux->moverNodoDatos(n) == true)
		{
			//continuar
			//cout << "se movio el datos SIUUU " << cont << endl;

		}
		else {
			aux = aux->siguiente;
			cont++;
		}

	}
}
/*Metodo que verifica los movientos de niveles pero solo dentro de la misma
matriz*/
bool ListaMatriz::verificarMovimientosNormales(int n)
{
	MatrizOrtogonal* aux;
	aux = this->frente;
	if (EstaVacia() == true)
	{
		//cout<<"No hay reportes todavia" << endl;
	}
	while (aux != NULL)
	{
		if (aux->movimientoNiveles(n) != true)
		{
			aux = aux->siguiente;
		}
		else {
			return true;
		}
		

	}
	return false;
}
/*Metodo de moviemntos une todos los verificadores */
void ListaMatriz::movimientos(int n)
{
	if (verificarMovimientosNormales(n)!=true)
	{
		movimientosNiveles(n);
	}
}
/*Metodo de sumar puntos recorre las matrices y verifica la posicion para sumar los 
puntos*/
int ListaMatriz::sumarPuntos(int datos)
{
	int puntos=0;
	MatrizOrtogonal* aux;
	aux = this->frente;
	if (EstaVacia() == true)
	{
		//cout<<"No hay reportes todavia" << endl;
	}
	while (aux != NULL)
	{
		puntos=puntos+aux->puntosFuncion(datos);
		aux = aux->siguiente;

	}
	return puntos;
}
/*Metodo que limpia la lista */
void ListaMatriz::LimpiarLista()
{
	this->frente = NULL;
	this->final = NULL;
}
