
#include "ListaMatriz.h"

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
void ListaMatriz::InsertarVacia(MatrizOrtogonal* matriz)
{
	MatrizOrtogonal* nuevo = new MatrizOrtogonal();
	//nuevo = matriz;
	nuevo->c = matriz->c;
	nuevo->c = matriz->c;
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
			cout << "Encontro pivote en matriz " << cont << endl;
			xxP = aux->xx;
			yyP = aux->yy;
			return true;
		}
		else {
			aux = aux->siguiente;
			cont++;
		}

	}
	return false;
}
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
			cout << "Encontro dato en matriz " << cont << endl;
			xxD = aux->xx;
			yyD = aux->yy;
			return true;
		}
		else {
			aux = aux->siguiente;
			cont++;
		}

	}
	return false;
}

void ListaMatriz::movimientosNiveles(int n)
{
	
	if (guardarPiv()==true && guardarDato(n)==true)
	{
		if ((xxP== xxD) && (yyP==yyD) )
		{
			//Si se puede hacer el movimiento ------------------OJO
			cout << "Si se puede hacer ese movimiento " << endl;
			if (cambiarBadera(n)==true)
			{
				moverPivote(n);
				moverDatos(n);
			}
		}
		else { // provar con movimiento normales
			cout << "nel" << endl;
		}

	}
}
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
			cout << "se movio el pivote " << cont << endl;
			
		}
		else {
			aux = aux->siguiente;
			cont++;
		}

	}
}

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
			cout << "se movio el datos WUUU " << cont << endl;

		}
		else {
			aux = aux->siguiente;
			cont++;
		}

	}
}
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
void ListaMatriz::movimientos(int n)
{
	if (verificarMovimientosNormales(n)!=true)
	{
		movimientosNiveles(n);
	}
}
