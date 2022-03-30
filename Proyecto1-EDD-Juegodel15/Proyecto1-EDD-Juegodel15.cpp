
// Proyecto1-EDD-Juegodel15.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "matriz.h"
#include <vector>
#include <cstdlib>
#include <ctime>

 // paramentros de la matiz en x y
int columna;
int fila;
int datos;
int inserta;
int n;
vector<int> lista;
vector<int> arreglo;
int cont = 0;
int c = 0;
bool vacio = false;

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
void aleatorios()
{
    int aux = 0;

    srand(time(0));

    for (int i = 0; i <= datos; i++) {
        aux = (1 + rand() % datos);

        int aux2 = 0;

        while (aux2 < i) {

            if (aux != arreglo[aux2])
                aux2++;

            else {
                aux = (0 + rand() % datos);
                aux2 = 0;

            }
        }

        arreglo.push_back(aux);

       // cout << arreglo[i] << "\n";
    }
  
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

                    if (inserta<=datos)
                    {
                        if (cont != 0)
                        {

                            if (verificador(inserta) == false)
                            {
                                if (vacio == false && cont == datos)
                                {
                                   
                                    cout << "NO AGREGO ESPACIO VACIOOOO se agregara automaticamente" << endl;
                                    matriz->insertar(i, a, 0, true);
                                    cont++;
                                }
                                else {
                                    lista.push_back(inserta);
                                    
                                    cont++;
                                    if (inserta == 0)
                                    {
                                        vacio = true;
                                        matriz->insertar(i, a, inserta,true);
                                    }
                                    else { matriz->insertar(i, a, inserta,false); }
                                }

                            }
                            else
                            {
                                a--;
                            }

                        }
                        else {

                            lista.push_back(inserta);
                            cont++;
                            if (inserta == 0)
                            {
                                vacio = true;
                                matriz->insertar(i, a, inserta, true);
                            }
                            else { matriz->insertar(i, a, inserta, false); }
                        }
                    }
                    else
                    {
                        cout << "UNICAMENTE PUEDE INGRESAR DATOS MENORES A "<<datos<<endl;
                        a--;
                    }
                    
                }
            }
 
            matriz->imprimir();
            system("pause");
            break;

        case 2:
            // Lista de instrucciones de la opción 2                
            
       
            break;

        case 3:
            // Lista de instrucciones de la opción 3   
            cout << "Ingrese Numero de Filas" << endl;
            cin >> fila;
            cout << "Ingrese Numero de Columnas" << endl;
            cin >> columna;
            crearTablero(fila, columna);
            aleatorios();
           
            for (int i = 0; i < fila; i++)
            {
                for (int a = 0; a < columna; a++)
                {
                    if (arreglo[c] == 0)
                    {
                        vacio = true;
                        matriz->insertar(i, a, arreglo[c], true);
                    }
                    else { matriz->insertar(i, a, arreglo[c], false); }
                    c++;

                }
            }
            cout << "-----LISTO PARA JUGAR!!!-----" << endl;
            matriz->imprimir();
            cout << "---------------------------------" << endl;
            cout << "Ingrese Numero que desea mover" << endl;
            cin >> n;
            matriz->movimiento(n);
            matriz->imprimir();

            system("pause");
            cout << "Ingrese Numero que desea mover" << endl;
            cin >> n;
            matriz->movimiento(n);
            matriz->imprimir();

            system("pause");
            cout << "Ingrese Numero que desea mover" << endl;
            cin >> n;
            matriz->movimiento(n);
            matriz->imprimir();

            system("pause");
            cout << "Ingrese Numero que desea mover" << endl;
            cin >> n;
            matriz->movimiento(n);
            matriz->imprimir();

            system("pause");
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
    MatrizOrtogonal* matriz;
    matriz = new MatrizOrtogonal();
  /* matriz->insertar(0, 0, 1);
    matriz->insertar(0, 1, 2);
    matriz->insertar(0, 2, 3);
    matriz->insertar(1, 0, 4);
    matriz->insertar(1, 1, 5);
    matriz->insertar(1, 2, 6);
    matriz->insertar(2, 0, 7);
    matriz->insertar(2, 1, 8);
    matriz->insertar(2, 2, 0);
    
    std::cout << "Hello World!\n";*/ 
   

   

    return 0;
}


