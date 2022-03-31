
// Proyecto1-EDD-Juegodel15.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "matriz.h"
#include "Jugador.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <stdio.h>

 // paramentros de la matiz en x y
int columna = 0;
int fila = 0;;
int datos = 0;;
int inserta = 0;;
int n = 0;;
string n1;
vector<int> lista;
vector<int> arreglo;
int cont = 0;
int c = 0;
bool vacio = false;
bool jugar = true;
int pasos = 0;

int correcto = 1;

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
void juegoAleatorio()
{
    MatrizOrtogonal* matriz;
    MatrizOrtogonal* matrizInicial;
    string nombre;
    int puntos;

    matriz = new MatrizOrtogonal();
    matrizInicial = new MatrizOrtogonal();

    //
    cout << "Ingrese Nombre del Jugador" << endl;
    cin >> nombre;
    cout << "Ingrese Numero de Filas" << endl;
    cin >> fila;
    cout << "Ingrese Numero de Columnas" << endl;
    cin >> columna;

    crearTablero(fila, columna);
    aleatorios();
    Jugador j=  Jugador();
    j.ingresardatos(nombre, 0, 0);
    //limpiar variables
    correcto = 1;
    pasos = 0;
    c = 0;
    jugar = true;
    for (int i = 0; i < fila; i++)
    {
        for (int a = 0; a < columna; a++)
        {
            if (arreglo[c] == 0)
            {
                vacio = true;
                matriz->insertar(i, a, arreglo[c], true,correcto);
                matrizInicial->insertar(i, a, arreglo[c], true, correcto);

            }
            else { matriz->insertar(i, a, arreglo[c], false,correcto);
            matrizInicial->insertar(i, a, arreglo[c], false, correcto);
            }
            correcto++;
            c++;

        }
    }
    cout << "-----LISTO PARA JUGAR!!!-----" << endl;
    matriz->imprimir();
    //cout << "---------------------------------" << endl;
    while (jugar == true)
    {
        cout << "Ingrese Numero que desea mover " << endl;    cout << "                                                    PRESIONE R para Reiniciar " << endl;
        cout << "                                                    PRESIONE S para Terminar " << endl;
        cin >> n1;

        if (n1 == "R" || n1 == "r")
        {
            cout << "Juego reiniciado" << endl;
            matriz = matrizInicial;
            matriz->imprimir();
            //aqui se reiniciarian los punto tambien
        }
        else if (n1 == "S" || n1 == "s")
        {
            cout << "----- GAME END!!!! -----" << endl;
            cout << "NOMBRE: " << j.nombre<<endl;
            cout << "PUNTOS: " << j.puntos << endl;
            cout << "PASOS: " << pasos << endl;
            cout << "TIEMPO: " << j.tiempo << endl;
            jugar = false;
        }
        else {
            int num = stoi(n1);
            matriz->movimiento(num);
            pasos++;
            j.ingresarPuntos(matriz->puntos(datos + 1));
            matriz->imprimir();
            cout << "Pasos: " <<pasos<< endl;
            //j.imprimirdatos();
            

        }


    }

}
void juegoManual()
{
    MatrizOrtogonal* matriz;
    MatrizOrtogonal* matrizInicial;
    string nombre;
    matriz = new MatrizOrtogonal();
    matrizInicial = new MatrizOrtogonal();
    correcto = 0;
    cout << "Ingrese Nombre del Jugador" << endl;
    cin >> nombre;
    cout << "Ingrese Numero de Filas" << endl;
    cin >> fila;
    cout << "Ingrese Numero de Columnas" << endl;
    cin >> columna;

    crearTablero(fila, columna);
    aleatorios();
    Jugador j = Jugador();
    j.ingresardatos(nombre, 0, 0);
    //limpiar variables
    correcto = 1;
    pasos = 0;
    c = 0;
    jugar = true;
    cout << "RECUERDE MARCAR UN ESPACIO VACIO CON 0" << endl;
    for (int i = 0; i < fila; i++)
    {
        for (int a = 0; a < columna; a++)
        {
            cout << "Ingrese dato en la posicion " << i << " , " << a << endl;
            cin >> inserta;

            if (inserta <= datos)
            {
                if (cont != 0)
                {

                    if (verificador(inserta) == false)
                    {
                        if (vacio == false && cont == datos)
                        {

                            cout << "NO AGREGO ESPACIO VACIOOOO se agregara automaticamente" << endl;
                            correcto++;
                            matriz->insertar(i, a, 0, true,correcto);
                            matrizInicial->insertar(i, a, 0, true, correcto);
                            cont++;
                            
                        }
                        else {
                            lista.push_back(inserta);

                            cont++;
                            correcto++;
                            if (inserta == 0)
                            {
                                vacio = true;
                                matriz->insertar(i, a, inserta, true,correcto);
                                matrizInicial->insertar(i, a, inserta, true, correcto);
                            }
                            else { matriz->insertar(i, a, inserta, false, correcto);
                                 matrizInicial->insertar(i, a, inserta, false, correcto);
                            
                            }
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
                    correcto++;
                    if (inserta == 0)
                    {
                        vacio = true;
                        matriz->insertar(i, a, inserta, true,correcto);
                        matrizInicial->insertar(i, a, inserta, true, correcto);
                    }
                    else { matriz->insertar(i, a, inserta, false,correcto);
                    matrizInicial->insertar(i, a, inserta, false, correcto);
                    }
                }
            }
            else
            {
                cout << "UNICAMENTE PUEDE INGRESAR DATOS MENORES A " << datos << endl;
                a--;
            }

        }
    }
    cout << "-----LISTO PARA JUGAR!!!-----" << endl;
    matriz->imprimir();
    //cout << "---------------------------------" << endl;
    while (jugar == true)
    {
        cout << "Ingrese Numero que desea mover " << endl;    cout << "                                                    PRESIONE R para Reiniciar " << endl;
        cout << "                                                    PRESIONE S para Terminar " << endl;
        cin >> n1;

        if (n1 == "R" || n1 == "r")
        {
            cout << "Juego reiniciado" << endl;
            matriz = matrizInicial;
            matriz->imprimir();
            //aqui se reiniciarian los punto tambien
        }
        else if (n1 == "S" || n1 == "s")
        {
            cout << "----- GAME END!!!! -----" << endl;
            cout << "NOMBRE: " << j.nombre << endl;
            cout << "PUNTOS: " << j.puntos << endl;
            cout << "PASOS: " << pasos;
            cout << "TIEMPO: " << j.tiempo << endl;
            jugar = false;
        }
        else {
            int num = stoi(n1);
            matriz->movimiento(num);
            pasos++;
            j.ingresarPuntos(matriz->puntos(datos + 1));
            matriz->imprimir();
            cout << "Pasos: " << pasos << endl;
            //j.imprimirdatos();


        }


    }


}

void menutablero() {
    
    //matrizInicial = new MatrizOrtogonal();
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
            juegoManual();
            system("pause");
            break;

        case 2:
            // Lista de instrucciones de la opción 2                
            
       
            break;

        case 3:
            // Lista de instrucciones de la opción 3   
            juegoAleatorio();
            
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


