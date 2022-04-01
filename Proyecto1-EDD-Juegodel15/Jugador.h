#ifndef Jugador_H
#define Jugador_H

#include <string>
#include <cstdlib>
using namespace std;

class Jugador {

	public:
		string nombre;
		int puntos;
		double tiempo;
		Jugador();
		void ingresardatos(string nombre, int puntos, double tiempo);
		void ingresarPuntos(int p);
		void ingresarTiempo(double p);
		void imprimirdatos();
	};
#endif
