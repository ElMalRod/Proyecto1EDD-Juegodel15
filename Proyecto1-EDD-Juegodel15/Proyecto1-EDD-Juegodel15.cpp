
// Proyecto1-EDD-Juegodel15.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "matriz.h"
#include <vector>

 // paramentros de la matiz en x y
int columna;
int fila;
int datos;
int inserta;
vector<int> lista;
int cont = 0;

void crearTablero(int x, int y) {

    fila = x;
    columna = y;
    datos = (x * y) - 1;
    

}

bool verificador(int n) {

    for (int i = 0; i < lista.size(); i++) {
       //cout << lista[i] << endl;
       if (n == lista[i])
       {
           cout << "NO SE PERMITE NUMEROS REPETIDOS" << endl;

           return true;
           break;
       }
    }
    return false;
}

void menutablero() {
    MatrizOrtogonal* matriz;
    matriz = new MatrizOrtogonal();
    int opcion;
    bool repetir = true;
    
    do {
        system("cls");

        // Texto del menú que se verá cada vez
        cout << "\n\nMenu de Tablero" << endl;
        cout << "1. Manual" << endl;
        cout << "2. Cargar Archivo" << endl;
        cout << "3. Aleatorio" << endl;
        cout << "0. Regresar" << endl;

        cout << "\nIngrese una opcion: " << endl;
        cin >> opcion;

        switch (opcion) {
        case 1:
            // Lista de instrucciones de la opción 1   
            cout << "Ingrese Numero de Filas" << endl;
            cin >> fila;
            cout << "Ingrese Numero de Columnas" << endl;
            cin >> columna;
            crearTablero(fila , columna);
            cout << "RECUERDE MARCAR UN ESPACIO VACIO CON 0" << endl;
            for (int i = 0; i < fila; i++)
            {
                for (int a = 0; a < columna; a++)
                {
                    cout << "Ingrese dato en la posicion "<<i<<" , "<<a <<endl;
                    cin >> inserta;
                    if (cont != 0)
                    {
                       
                        if (verificador(inserta) == false)
                        {
                           
                            lista.push_back(inserta);
                            matriz->insertar(i, a, inserta);
                            cont++;
                        }
                        else
                        {
                            a--;
                        }

                    }
                    else {
                        
                        lista.push_back(inserta);
                        matriz->insertar(i, a, inserta);
                        cont++;
                    }
                    
                }
            }
            break;

        case 2:
            // Lista de instrucciones de la opción 2                

            system("pause>nul"); // Pausa
            break;

        case 3:
            // Lista de instrucciones de la opción 3   
            cout << "Ingrese Numero de Filas" << endl;
            cin >> fila;
            cout << "Ingrese Numero de Columnas" << endl;
            cin >> columna;
            crearTablero(fila, columna);

            system("pause>nul"); // Pausa            
            break;

        case 0:
          
            break;
        }
    } while (repetir);

}
void menu() {
    int opcion;
    bool repetir = true;

    do {
        system("cls");

        // Texto del menú que se verá cada vez
        cout << "\n\nMenu de Opciones" << endl;
        cout << "1. Crear Tablero y Jugar" << endl;
        cout << "2. Jugar" << endl;
        cout << "3. Reportes" << endl;
        cout << "0. SALIR" << endl;

        cout << "\nIngrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            // Lista de instrucciones de la opción 1                
            menutablero();
            break;

        case 2:
            // Lista de instrucciones de la opción 2                

            system("pause>nul"); // Pausa
            break;

        case 3:
            // Lista de instrucciones de la opción 3                

            system("pause>nul"); // Pausa            
            break;

        case 0:
            repetir = false;
            break;
        }
    } while (repetir);
}

int main()
{
    menu();
    std::cout << "Hello World!\n";
   

   

    return 0;
}


