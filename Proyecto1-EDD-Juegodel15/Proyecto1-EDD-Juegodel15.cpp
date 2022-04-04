
// Proyecto1-EDD-Juegodel15.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "matriz.h"
#include "Jugador.h"
#include "Lista.h"
#include "ListaMatriz.h"
#include <cstdlib>
#include <ctime>
#include <string>
#include <stdio.h>
#include <fstream>
using namespace std;
/*VARIABLES GLOBALES */
 // paramentros de la matiz en x y
int columna = 0;
int fila = 0;;
int datos = 0;;
int inserta = 0;;
int n = 0;;
string n1;
Lista listaManual= Lista(); // Lista donde se guardan los numero de manual para no aceptar repetidos.
Lista listaAle = Lista();// Lista donde se guardan los numeros aleatoreos
Lista listaInicial = Lista();// Lista donde se guardan los numeros de la matriz inicial para poder reinciar.
Lista listaReportes = Lista(0);
ListaMatriz matrices = ListaMatriz();

int cont = 0;
int c = 0;
bool vacio = false;
bool jugar = true;
int pasos = 0;
int correcto = 1;
int contJugadores = -1;
unsigned t0, t1;

/*Metodo de Archivo prueba*/
void archivo() {
    char cadena[128];
    int i;
    ifstream fe("C:/Users/emili/OneDrive/Escritorio/PROYECTOS/Archivo.txt");
    while (!fe.eof()) {
        fe >> cadena;
        fe  >> i;
        cout << cadena <<i<< endl;

    }
    fe.close();
}
/*Metodo de la creacion del tablero*/
void crearTablero(int x, int y, int n) {

    //n indica si hay mas niveles
    fila = x;
    columna = y;
    datos = ((x * y)*n) - 1;
    

}
/*Metodo verificador Nos ayuda a filtrar los numeros ingresados
para verficar que no sean repetidos atravez de listas*/
bool verificador(int n) {

    for (int i = 0; i < listaManual.tamanio; i++) {
       //cout << lista[i] << endl;
       if (n == listaManual.ObtenerXpos(i))
       {
           cout << "NO SE PERMITE NUMEROS REPETIDOS" << endl;
         
           return true;
           break;
       }
    }
    return false;

}
/*Metodo que ganar es un simple metodo que nos muestra el resultado de la partida
y si es ganador imprime un letrero*/
void ganar(Jugador j) {
    int pt = (datos + 1) *2;
    cout << "Puntos "<<j.puntos << " " << endl;
    if (j.puntos == pt)
    {
        cout << "####################################################################################################" << endl;
        cout << "####################################################################################################" << endl;
        cout << "############,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,############" << endl;
        cout << "############,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,############" << endl;
        cout << "##iiiiiiiiii,,,,,,,,EEEEE,,,,,EEEEE,,,,,EEEEEE,,,,,EEEEE,,,,,,EEE,EEEEEEEEE,,,EEEEE,,,,,iiiiiiiiii##" << endl;
        cout << "###iiiiiiiii,,,,,,EEEEEEE,,,,EEEEEEE,,,EEEEEEEi,,,EEEEEEE,,,,EEEE,EEEEEEEEE,iEEEEEE,,,,,iiiiiiiii###" << endl;
        cout << "####iiiiiiii,,,,,,EEEEEEE,,,EEEEEEEEL,,EEEEEEEE,,EEEEEEEEt,,EEEEE,EEEEEEEEE,EEEEEEE,,,,,iiiiiiii####" << endl;
        cout << "####;iiiiiii,,,,,EEEEEi;E,,,EEEE,EEEE,,EEEjEEEE,,EEEE,EEEE,,EEEE;,EEEEEEEEE,EEEEEEE,,,,,iiiiiii;####" << endl;
        cout << "#####iiiiiii,,,,,EEEE,,,,,,,EEEE,EEEE,iEEE,iEEE,,EEEE,EEEE,,EEEE,,,,,EEE,,,,EEEE,,,,,,,,iiiiiii#####" << endl;
        cout << "######iiiiii,,,,,EEE,,EEEE,,EEEE,EEEE,iEEE,iEEE,,EEEE,EEEE,,EEEE,,,,,EEE,,,,EEEEEEE,,,,,iiiiii######" << endl;
        cout << "#######iiiii,,,,,EEE,,EEEEE,EEEEEEEEE,iEEE,iEEE,,EEEEEEEEE,,,EEEE,,,,EEE,,,,EEEEEEE,,,,,iiiii#######" << endl;
        cout << "########iiii,,,,,EEEE,EEEEE,EEEEEEEEE,iEEE,iEEE,,EEEEEEEEE,,,EEEE,,,,EEE,,,,EEEEiii,,,,,iiii########" << endl;
        cout << "#######iiiii,,,,,EEEEL,,EEE,EEEEEEEEE,iEEE,iEEE,,EEEEEEEEE,,,EEEE,,,,EEE,,,,EEEE,,,,,,,,iiiii#######" << endl;
        cout << "######;iiiii,,,,,,EEEEEEEEE,EEEE,EEEE,iEEE,iEEE,,EEEE,EEEE,EEEEEE,,,,EEE,,,,EEEEEEE,,,,,iiiii;######" << endl;
        cout << "#####iiiiiii,,,,,,EEEEEEEE,,EEEE,EEEE,iEEE,iEEE,,EEEE,EEEE,EEEEE,,,,,EEE,,,,tEEEEEE,,,,,iiiiiii#####" << endl;
        cout << "#####iiiiiii,,,,,,,iEEEEE,,,EEEE,EEEE,iEEE,iEEE,,EEEE,EEEE,EEEEt,,,,,EEE,,,,,;EEEEE,,,,,iiiiiii#####" << endl;
        cout << "####iiiiiiii,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,iiiiiiii####" << endl;
        cout << "###iiiiiiiii,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,iiiiiiiii###" << endl;
        cout << "####################################################################################################" << endl;
        cout << "####################################################################################################" << endl;
        cout << "####################################################################################################" << endl;
        //tiempo
        t1 = clock();
        double time = (double(t1 - t0) / CLOCKS_PER_SEC);
        j.ingresarTiempo(time);
        listaReportes.InsertarFinalJugador(j, contJugadores);
        cout << "----- END GAME!!!! -----" << endl;
        cout << "NOMBRE: " << j.nombre << endl;
        cout << "PUNTOS: " << j.puntos << endl;
        cout << "PASOS: " << pasos << endl;
        cout << "TIEMPO: " << j.tiempo <<".seg"<< endl;
        cout << "POSICION EN LA TABLA: " << listaReportes.DevolverPosicion(j.nombre) << endl;
        system("pause");
        jugar = false;
    }
    

}
/*Metodo aleatorios , Crea numeros aleatorios que posteriormente son ingresados a la
lista con el fin de que no sean repetidos*/
void aleatorios()
{
    
    int aux = 0;

    srand(time(0));

    for (int i = 0; i <= datos; i++) {
        aux = (1 + rand() % datos);

        int aux2 = 0;

        while (aux2 < i) {

            if (aux != listaAle.ObtenerXpos(aux2))
                aux2++;

            else {
                aux = (0 + rand() % datos);
                aux2 = 0;

            }
        }

        listaAle.InsertarFinal(aux);

       // cout << arreglo[i] << "\n";
    }
  
}
/*Metodo de Guardar Niveles es un metodo separado para que cree una nueva matriz con el fin
de no sobre escribir*/
void guardarNivel(int n)
{
    MatrizOrtogonal* matriz; //crea el puntero a la matriz ortogonal
    matriz = new MatrizOrtogonal(n); //inicializacion de la matriz

    //for
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
                            matriz->insertar(i, a, 0, true, correcto);
                            listaInicial.InsertarFinal(0);
                            cout << "Se agrego -> " << inserta << " en " << i << " , " << a << endl;
                            cont++;

                        }
                        else {
                            listaManual.InsertarFinal(inserta);

                            cont++;
                            correcto++;
                            if (inserta == 0)
                            {
                                vacio = true;
                                matriz->insertar(i, a, inserta, true, correcto);
                                listaInicial.InsertarFinal(inserta);
                                cout << "Se agrego -> " << inserta << " en " << i << " , " << a << endl;
                            }
                            else {
                                matriz->insertar(i, a, inserta, false, correcto);
                                listaInicial.InsertarFinal(inserta);
                                cout << "Se agrego -> " << inserta << " en " << i << " , " << a << endl;

                            }
                        }


                    }
                    else
                    {
                        a--;
                    }

                }
                else {

                    listaManual.InsertarFinal(inserta);
                    cont++;
                    correcto++;
                    if (inserta == 0)
                    {
                        vacio = true;
                        matriz->insertar(i, a, inserta, true, correcto);
                        listaInicial.InsertarFinal(inserta);
                    }
                    else {
                        matriz->insertar(i, a, inserta, false, correcto);
                        listaInicial.InsertarFinal(inserta);
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
    //
    matrices.InsertarFinal(matriz,n);

}
void juegoNiveles()
{
    MatrizOrtogonal* matriz; //crea el puntero a la matriz ortogonal
    string nombre; //variable para guardar nombre del jugador
    int puntos, niveles = 0; //variable para guardar puntos y numero de niveles de partida
    matriz = new MatrizOrtogonal(0); //inicializacion de la matriz

    //pedir datos
    cout << "Ingrese Nombre del Jugador" << endl;
    cin >> nombre;
    cout << "Ingrese Numero de niveles" << endl;
    cin >> niveles;
    cout << "Ingrese Numero de Filas" << endl;
    cin >> fila;
    cout << "Ingrese Numero de Columnas" << endl;
    cin >> columna;

    //
    crearTablero(fila, columna, niveles); //guardar datos de tablero
    contJugadores++;// aumentar contador de jugadores
    Jugador j = Jugador(contJugadores); //creador de jugador
    j.ingresardatos(nombre, 0, 0);//Guardar datos de jugador
    

    //limpiar variables
    correcto = 0;
    pasos = 0;
    c = 0;
    jugar = true;
    listaManual.limpiar();
    listaInicial.limpiar();
    matrices.LimpiarLista();
    cout << "RECUERDE MARCAR UN ESPACIO VACIO CON 0" << endl;

    //Guardar datos de los niveles
    for (int i = 0; i < niveles; i++)
    {
        if (i>0)
        {
            //matrices.InsertarFinal(matriz); // agregar matriz recien llenada a lista de matrices
            matriz->eliminar();// eliminar matriz
            matriz = new MatrizOrtogonal(i);//inicializarla*/
        }
        //for para ingresar datos
        guardarNivel(i);
        matrices.InsertarFinal(matriz,i);
       
        cout << "Matriz "<<i<<" ingresada." << endl;
    }
    // imprimir matrices
    matrices.ImprimirTablero();
    while (jugar == true)
    {
        cout << "Ingrese Numero que desea mover " << endl;    cout << "                                                    PRESIONE R para Reiniciar " << endl;
        cout << "                                                    PRESIONE S para Terminar " << endl;
        cout << "                                                    PRESIONE A para Autocompletar " << endl;
        cin >> n1;

        if (n1 == "R" || n1 == "r")
        {
            
            cout << "pendiente" << endl;
           
        }
        else if (n1 == "S" || n1 == "s")
        {
            t1 = clock();
            double time = (double(t1 - t0) / CLOCKS_PER_SEC);
            j.ingresarTiempo(time);
            listaReportes.InsertarFinalJugador(j, contJugadores);
            cout << "----- END GAME!!!! -----" << endl;
            cout << "NOMBRE: " << j.nombre << endl;
            cout << "PUNTOS: " << j.puntos << endl;
            cout << "PASOS: " << pasos << endl;
            cout << "TIEMPO: " << j.tiempo << ".seg" << endl;
            cout << "POSICION EN LA TABLA: " << listaReportes.DevolverPosicion(nombre) << endl;

            jugar = false;
            matriz->eliminar();
        }
        else {
            int num = stoi(n1);
            //matriz->movimiento(num);
            matrices.movimientos(num);
            j.ingresarPuntos(matrices.sumarPuntos(datos + 1));
            matrices.ImprimirTablero();
            ganar(j);
            pasos++;
            cout << "Pasos: " << pasos << endl;
           



        }


    }

}
/*Metodos de jugar basicamente son condiciones  que son validadas para sumar puntos 
en el juego */
void juegoAleatorio()
{
    MatrizOrtogonal* matriz;
    string nombre;
    int puntos=0;

    matriz = new MatrizOrtogonal(0);

    //
    cout << "Ingrese Nombre del Jugador" << endl;
    cin >> nombre;
    cout << "Ingrese Numero de Filas" << endl;
    cin >> fila;
    cout << "Ingrese Numero de Columnas" << endl;
    cin >> columna;

    crearTablero(fila, columna,1);
    listaAle.limpiar();
    listaInicial.limpiar();
    aleatorios();
    Jugador j=  Jugador(contJugadores);
    contJugadores++;
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
            if (listaAle.ObtenerXpos(c) == 0)
            {
                vacio = true;
                matriz->insertar(i, a, listaAle.ObtenerXpos(c), true,correcto);


            }
            else { matriz->insertar(i, a, listaAle.ObtenerXpos(c), false,correcto);
            }
            correcto++;
            c++;

        }
    }
    t0 = clock();
    // Code to execute
    cout << "-----LISTO PARA JUGAR!!!-----" << endl;
    matriz->imprimir();
    j.ingresarPuntos(matriz->puntosFuncion(datos + 1));
    //cout << "---------------------------------" << endl;
    while (jugar == true)
    {
        cout << "Ingrese Numero que desea mover " << endl;    cout << "                                                    PRESIONE R para Reiniciar " << endl;
        cout << "                                                    PRESIONE S para Terminar " << endl;
        cin >> n1;

        if (n1 == "R" || n1 == "r")
        {
            
            matriz->eliminar(); //eliminar matriz actual
            matriz = new MatrizOrtogonal(0);
            c = 0;//limpiar contador
            correcto = 1;//
            //vacio = true;
            //inserta datos de la matriz inicial
            for (int i = 0; i < fila; i++)
            {
                for (int a = 0; a < columna; a++)
                {
                    if (listaAle.ObtenerXpos(c) == 0)
                    {
                        vacio = true;
                        matriz->insertar(i, a, listaAle.ObtenerXpos(c), true, correcto);
                    }
                    else {
                        matriz->insertar(i, a, listaAle.ObtenerXpos(c), false, correcto);
                    }
                    correcto++;
                    c++;

                }
            }
            cout << "-------Juego reiniciado--------" << endl;
            pasos = 0;
            matriz->imprimir();
            //aqui se reinician los puntos tambien
            j.ingresarPuntos(matriz->puntosFuncion(datos + 1));
        }
        else if (n1 == "S" || n1 == "s")
        {
            t1 = clock();
            double time = (double(t1 - t0) / CLOCKS_PER_SEC);
            j.ingresarTiempo(time);
            listaReportes.InsertarFinalJugador(j, contJugadores);
            cout << "----- END GAME!!!! -----" << endl;
            cout << "NOMBRE: " << j.nombre<<endl;
            cout << "PUNTOS: " << j.puntos << endl;
            cout << "PASOS: " << pasos << endl;
            cout << "TIEMPO: " << j.tiempo << ".seg"<<endl;
            cout << "POSICION EN LA TABLA: " << listaReportes.DevolverPosicion(nombre) << endl;
            jugar = false;
            matriz->eliminar();
        }
        else {
            int num = stoi(n1);
            matriz->movimiento(num);
            pasos++;
           
            j.ingresarPuntos(matriz->puntosFuncion(datos + 1));
            matriz->imprimir();
            cout << "Pasos: " <<pasos<< endl;
            ganar(j);
            //j.imprimirdatos();
            

        }


    }
     
}
void juegoManual()
{
    MatrizOrtogonal* matriz;
    string nombre;
    int puntos = 0;
    matriz = new MatrizOrtogonal(0);
    
    cout << "Ingrese Nombre del Jugador" << endl;
    cin >> nombre;
    cout << "Ingrese Numero de Filas" << endl;
    cin >> fila;
    cout << "Ingrese Numero de Columnas" << endl;
    cin >> columna;

    crearTablero(fila, columna,1);
    contJugadores++;
    Jugador j = Jugador(contJugadores);
    j.ingresardatos(nombre, 0, 0);
    //limpiar variables
    correcto = 0;
    pasos = 0;
    c = 0;
    jugar = true;
    listaManual.limpiar();
    listaInicial.limpiar();
    cout << "RECUERDE MARCAR UN ESPACIO VACIO CON 0" << endl;
    //for para ingresar datos
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
                            listaInicial.InsertarFinal(0);
                            cout << "Se agrego -> "<<inserta<<" en "<<i<<" , "<<a<< endl;
                            cont++;
                            
                        }
                        else {
                            listaManual.InsertarFinal(inserta);

                            cont++;
                            correcto++;
                            if (inserta == 0)
                            {
                                vacio = true;
                                matriz->insertar(i, a, inserta, true,correcto);
                                listaInicial.InsertarFinal(inserta);
                                cout << "Se agrego -> " << inserta << " en " << i << " , " << a << endl;
                            }
                            else { matriz->insertar(i, a, inserta, false, correcto);
                                 listaInicial.InsertarFinal(inserta);
                                 cout << "Se agrego -> " << inserta << " en " << i << " , " << a << endl;
                            
                            }
                        }


                    }
                    else
                    {
                        a--;
                    }

                }
                else {

                    listaManual.InsertarFinal(inserta);
                    cont++;
                    correcto++;
                    if (inserta == 0)
                    {
                        vacio = true;
                        matriz->insertar(i, a, inserta, true,correcto);
                        listaInicial.InsertarFinal(inserta);
                    }
                    else { matriz->insertar(i, a, inserta, false,correcto);
                    listaInicial.InsertarFinal(inserta);
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
    j.ingresarPuntos(matriz->puntosFuncion(datos + 1));
    t0 = clock();
    cout << "---------------------------------" << endl;
    while (jugar == true)
    {
        cout << "Ingrese Numero que desea mover " << endl;    cout << "                                                    PRESIONE R para Reiniciar " << endl;
        cout << "                                                    PRESIONE S para Terminar " << endl;
        cout << "                                                    PRESIONE A para Autocompletar " << endl;
        cin >> n1;

        if (n1 == "R" || n1 == "r")
        {
            matriz->eliminar(); //eliminar matriz actual
            matriz = new MatrizOrtogonal(0);
            c = 0;//limpiar contador
            correcto = 1;//
            //volver a cargar matriz inicial
            for (int i = 0; i < fila; i++)
            {
                for (int a = 0; a < columna; a++)
                {
                    if (listaInicial.ObtenerXpos(c) == 0)
                    {
                        vacio = true;
                        matriz->insertar(i, a, listaInicial.ObtenerXpos(c), true, correcto);


                    }
                    else {
                        matriz->insertar(i, a, listaInicial.ObtenerXpos(c), false, correcto);
                    }
                    correcto++;
                    c++;

                }
            }
            cout << "-------Juego reiniciado--------" << endl;
            pasos = 0;
            matriz->imprimir();
            //aqui se reinician los puntos tambien
            j.ingresarPuntos(matriz->puntosFuncion(datos+1));
        }
        else if (n1 == "S" || n1 == "s")
        {
            t1 = clock();
            double time = (double(t1 - t0) / CLOCKS_PER_SEC);
            j.ingresarTiempo(time);
            listaReportes.InsertarFinalJugador(j, contJugadores);
            cout << "----- END GAME!!!! -----" << endl;
            cout << "NOMBRE: " << j.nombre << endl;
            cout << "PUNTOS: " << j.puntos << endl;
            cout << "PASOS: " << pasos<< endl;
            cout << "TIEMPO: " << j.tiempo << ".seg"<<endl;
            cout << "POSICION EN LA TABLA: " << listaReportes.DevolverPosicion(nombre) << endl;
            
            jugar = false;
            matriz->eliminar();
        }
        else {
            int num = stoi(n1);
            matriz->movimiento(num);
            pasos++;
            cout << "" << endl;
            j.ingresarPuntos(matriz->puntosFuncion(datos + 1));
            matriz->imprimir();
            cout << "Pasos: " << pasos << endl;
            //j.imprimirdatos();
            ganar(j);
            


        }


    }


}
/*Metodo del Menu es basicamente seleccionar para ingresar a las opciones del juego*/
void menutablero() {
    
    //matrizInicial = new MatrizOrtogonal();
    int opcion;
    bool repetir = true;
    
    do {
        system("cls");

        // Texto del menú que se verá cada vez
        cout << "\n\nMenu de Tablero" << endl;
        cout << "1. Manual" << endl;
        cout << "2. Manual con Niveles" << endl;
        cout << "3. Cargar Archivo" << endl;
        cout << "4. Aleatorio" << endl;
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
            
            juegoNiveles();
            break;

        case 3:
            // Lista de instrucciones de la opción 3   
            
            system("pause");
            break;

        case 4:
            // Lista de instrucciones de la opción 4   
            juegoAleatorio();

            system("pause");
            break;

        case 0:
            repetir = false;
            break;
        }
    } while (repetir);

}
/*Metodo Main*/
int main()
{
   // archivo();
    MatrizOrtogonal* matriz;
    matriz = new MatrizOrtogonal(0);
  
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
            juegoAleatorio();
            system("pause>nul"); // Pausa
            break;

        case 3:
            // Lista de instrucciones de la opción 3  
            listaReportes.OrdenarJugadores();
            //listaReportes.RecorrerJugador();
            system("pause>nul"); // Pausa            
            break;

        case 0:
            repetir = false;
            break;
        }
    } while (repetir);

   
   
  

    return 0;
}
