#ifndef Jugador_H
#define Jugador_H

#include <string>
#include <cstdlib>
using namespace std;

class Jugador {

	public:
		string nombre;
		int puntos;
		int tiempo;
		Jugador();
		void ingresardatos(string nombre, int puntos, int tiempo);
		void ingresarPuntos(int p);
		void imprimirdatos();
	};
#endif
