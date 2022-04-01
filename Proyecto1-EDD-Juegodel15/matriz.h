#ifndef MATRIZ
#define MATRIZ
#include <iostream>
#include <stdlib.h>


using namespace std;
int xx;
int yy;
bool aceptar;
///// NODO DEL CENTRO

/* Esta esctructura es la que inicializa cada nodo nuevo*/ 
typedef struct NodoCen
{
    int dato;
    int x, y;
    bool pivote;
    int posxy;
    // PUNTEROS
    NodoCen* arriba;
    NodoCen* abajo;
    NodoCen* izquierda;
    NodoCen* derecha;
    NodoCen(int dato, int x, int y,bool pivote, int posxy)
    {
        this->dato = dato;
        this->x = x;
        this->y = y;
        this->pivote = pivote;
        this->posxy = posxy;
        arriba = NULL;
        abajo = NULL;
        izquierda = NULL;
        derecha = NULL;
    }
} NodoCen;

////// LISTA QUE COMPONE LA COLUMNA
/*Esta estructura inserta un espacio a la matriz*/
typedef struct ListaNodosCol
{
    NodoCen* primero;
    NodoCen* ultimo;

    //Constructor
    ListaNodosCol()
    {
        primero = NULL;
        ultimo = NULL;
    }
    // Verifica si esta vacio
    bool vacio()
    {
        if (primero == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    // Recorre la lista
    void recorrer()
    {
        if (!vacio())
        {
            NodoCen* temporal = primero;
            while (temporal != NULL)
            {
                //cout << temporal->dato << " ";
                temporal = temporal->abajo;
            }
        }
    }
    //imprimela lista
    void imprimir()
    {
        if (!vacio())
        {
            NodoCen* temporal = primero;
            while (temporal != NULL)
            {
                if (temporal->dato<10)
                {
                    cout << "| " << temporal->dato << "   |  ";
                }
                else
                {
                    cout << "| " << temporal->dato << "   |  ";
                }
                
                
                temporal = temporal->abajo;
            }
        }
    }
    //buscar nodo a mover pivote a numero
    bool moverPivote(int n)
    {
        if (!vacio())
        {
            NodoCen* temporal = primero;
            while (temporal != NULL)
            {
                if (temporal->pivote==true)
                {
                    //moverNodo(n);
                    xx = temporal->x;
                    yy = temporal->y;

                    temporal->pivote = false;
                    temporal->dato = n;

                    return true;
                }

                temporal = temporal->abajo;
            }
        }
        return false;

    }
    bool moverNodo(int n) //numero a pivote
    {
        if (!vacio())
        {
            NodoCen* temporal = primero;
            while (temporal != NULL)
            {
                if (temporal->dato == n )
                {

                    if ((temporal->x != xx) || (temporal->y != yy))
                    {

                        temporal->pivote = true;
                        temporal->dato = 0;
                        return true;
                    }
                }

                temporal = temporal->abajo;
            }
        }
        return false;
    }
    bool verificar(int n)
    {
        if (!vacio())
        {
            int aux = 1;
            NodoCen* temporal = primero;
            while (temporal != NULL)
            {
                if (temporal->pivote == true)
                {

                        switch (aux)
                        {
                        case 1: 
                         
                            if (temporal->arriba!=NULL)
                            {
                                if (temporal->arriba->dato == n)
                                {
                                    return true;
                                }
                            }
                            
                        case 2:
                        
                            if (temporal->abajo != NULL)
                            {
                                if (temporal->abajo->dato == n)
                                {
                                    return true;
                                }
                            }
                        case 3:
                           
                            if (temporal->izquierda != NULL)
                            {
                                if (temporal->izquierda->dato == n)
                                {
                                    return true;
                                }
                            }
                        case 4:
                          
                            if (temporal->derecha != NULL)
                            {
                                if (temporal->derecha->dato == n)
                                {
                                    return true;
                                }
                            }
                        }
                        
                    return false;
                }

                temporal = temporal->abajo;
            }
        }
        return false;
    }

    //sumar puntos
    int sumarPuntosC(int c)
    {
        int puntos=0;
        if (!vacio())
        {
            NodoCen* temporal = primero;
            while (temporal != NULL)
            {
                if (temporal->dato == temporal->posxy)
                {
                    puntos = puntos + 1;

                }
                if (temporal->dato==0 && temporal->posxy==c)
                {
                    puntos = puntos + 1;
                }

                temporal = temporal->abajo;
            }
        }
        return puntos;

    }
    // Metodo Insertar
    void insertar(NodoCen* inserta)
    {
        if (vacio())
        {
            primero = ultimo = inserta;
        }
        else
        {
            if (inserta->y < primero->y)
            {
                insertarFrente(inserta); // si la pos en y del nuevo nodo es menor a la pos en y del primer nodo se inserta al frente
            }
            else if (inserta->y > ultimo->y)
            {
                insertarFinal(inserta); // si la pos en y del nuevo nodo es mayor a la pos en y del primer nodo se inserta al final
            }
            else

            {
                insertarMedio(inserta);// sino inserta en el medio
            }
        }
    }

    /*
        Metodos para Insertar
    */
    void insertarFrente(NodoCen* inserta)
    {
        primero->arriba = inserta;
        inserta->abajo = primero;
        primero = primero->arriba;
    }

    void insertarFinal(NodoCen* inserta)
    {
        ultimo->abajo = inserta;
        inserta->arriba = ultimo;
        ultimo = ultimo->abajo;
    }

    void insertarMedio(NodoCen* inserta)
    {
        NodoCen* temporal1;
        NodoCen* temporal2;
        temporal1 = primero;
        while (temporal1->y < inserta->y)
        {
            temporal1 = temporal1->abajo;
        }
        temporal2 = temporal1->arriba;
        temporal2->abajo = inserta;
        temporal1->arriba = inserta;
        inserta->abajo = temporal1;
        inserta->arriba = temporal2;
    }

} ListaNodosCol;

////////// LISTA QUE COMPONE LA FILA
/*Esta estructura inserta un espacio a la matriz */
typedef struct ListaNodosFil
{
    NodoCen* primero;
    NodoCen* ultimo;

    // Constructor

    ListaNodosFil()
    {
        primero = NULL;
        ultimo = NULL;
    }

    // Verificador
    bool vacio()
    {
        if (primero == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // Recorre la fila
    void recorrer()
    {
        if (!vacio())
        {
            NodoCen* temporal = primero;
            while (temporal != NULL)
            {
                cout << temporal->dato << " ";
                temporal = temporal->derecha;
            }
        }
    }

    // Metodo de Insertar
    void insertar(NodoCen* inserta)
    {
        if (vacio())
        {
            primero = ultimo = inserta;
        }
        else
        {
            if (inserta->x < primero->x)
            {
                insertarFrente(inserta);  // si la pos en X del nuevo nodo es menor a la pos en X del primer nodo se inserta al frente
            }
            else if (inserta->x > ultimo->x)
            {
                insertarFinal(inserta); // si la pos en X del nuevo nodo es mayor a la pos en X del primer nodo se inserta al final
            }
            else
            {
                insertarMedio(inserta); //sino inserta en medio
            }
        }
    }
    /*
        Metodos para Insertar
    */
    void insertarFrente(NodoCen* inserta)
    {
        primero->izquierda = inserta;
        inserta->derecha = primero;
        primero = primero->izquierda;
    }

    void insertarFinal(NodoCen* inserta)

    {
        ultimo->derecha = inserta;
        inserta->izquierda = ultimo;
        ultimo = ultimo->derecha;
    }

    

    void insertarMedio(NodoCen* inserta)
    {
        NodoCen* temporal1;
        NodoCen* temporal2;
        temporal1 = primero;
        while (temporal1->x < inserta->x)
        {

            temporal1 = temporal1->derecha;
        }
        temporal2 = temporal1->izquierda;
        temporal2->derecha = inserta; 
        temporal1->izquierda = inserta;
        inserta->derecha = temporal1;
        inserta->izquierda = temporal2;
    }

} ListaNodosFil;

/////// NODOS DE CABECERA
/*Esta estructura define el nodo cabecera que nos indica el inicio y fin de una columna*/
typedef struct NodoCab
{
    int x;
    NodoCab* siguiente;
    NodoCab* anterior;
    ListaNodosCol* Columna;

    NodoCab(int x)
    {
        this->x = x;
        Columna = new ListaNodosCol();
        siguiente = NULL;
        anterior = NULL;
    }
} NodoCab;

////// LISTA DE NODOS CABECERAS
/*Esta esctrucutra inserta los espacios del primero hasta el ultimo, y es el guia para las columnas*/
typedef struct Cabeceras
{
    NodoCab* primero;
    NodoCab* ultimo;
    Cabeceras()
    {
        primero = NULL;
        ultimo = NULL;
    }
    void insertar(NodoCab* inserta)
    {
        if (vacio())
        {
            primero = ultimo = inserta;
        }
        else
        {
            if (inserta->x < primero->x)
            {
                insertarFrente(inserta);
            }
            else if (inserta->x > ultimo->x)
            {
                insertarFinal(inserta);
            }
            else
            {
                insertarMedio(inserta);
            }
        }
    }
    bool vacio()
    {
        if (primero == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    //

    void insertarFrente(NodoCab* inserta)
    {
        primero->anterior = inserta;
        inserta->siguiente = primero;
        primero = primero->anterior;
    }
    void insertarFinal(NodoCab* inserta)
    {
        ultimo->siguiente = inserta;
        inserta->anterior = ultimo;
        ultimo = ultimo->siguiente;
    }

    //
    void insertarMedio(NodoCab* inserta)
    {
        NodoCab* temporal1;
        NodoCab* temporal2;
        temporal1 = primero;
        while (temporal1->x < inserta->x)
        {
            temporal1 = temporal1->siguiente;
        }
        temporal2 = temporal1->anterior;

        temporal2->siguiente = inserta;
        temporal1->anterior = inserta;
        inserta->siguiente = temporal1;
        inserta->anterior = temporal2;
    }

    //
    void recorrer()
    {
        if (!vacio())
        {
            NodoCab* temporal = primero;
            while (temporal != NULL)
            {
                //cout << "Cabecera=" << temporal->x << endl;
                //temporal->Columna->imprimir();
                temporal = temporal->siguiente;
            }
        }
    }
    //imprimir
    void imprimir()
    {
        if (!vacio())
        {
            NodoCab* temporal = primero;
            cout << "---------------" << endl;
            while (temporal != NULL)
            {
                //cout << "Cabecera=" << temporal->x << endl;
                temporal->Columna->imprimir();
                cout << endl;
                temporal = temporal->siguiente;
            }
        }
    }

    //
    bool existe(int x)
    {
        if (vacio())
        {
           // cout << "no existe lista vacia" << endl;
            return false;
        }
        else
        {
            NodoCab* temporal;
            temporal = primero;
            while (temporal != NULL)
            {

                if (temporal->x == x)
                {
                    return true;
                }
                else if (temporal->siguiente == NULL)
                {
                   // cout << "no se encontro cabecera (se insertará) " << endl;
                    return false;
                }
                temporal = temporal->siguiente;
            }
        }
    }
    //
    NodoCab* busqueda(int x)
    {
        if (existe(x))
        {
            NodoCab* temporal;
            temporal = primero;
            while (temporal->x != x)
            {
                temporal = temporal->siguiente;
            }
            return temporal;
        }
        else {
           // cout << "no existe" << endl;
            return(new NodoCab(-1));
        }

    }
    //metodo para mover nodo
    void moverPivote(int n)
    {
        if (!vacio())
        {
            NodoCab* temporal = primero;
            while (temporal != NULL)
            {
                if (temporal->Columna->moverPivote(n) != true)
                {
                    temporal = temporal->siguiente;

                }
                
            }
        }
    }
    void moverNodo(int n)
    {
        if (!vacio())
        {
            NodoCab* temporal = primero;
            while (temporal != NULL)
            {
                if (temporal->Columna->moverNodo(n) != true)
                {
                    temporal = temporal->siguiente;

                }

            }
        }
    }
    //
    bool verificador(int n)
    {
        if (!vacio())
        {
            NodoCab* temporal = primero;
            while (temporal != NULL)
            {
                if (temporal->Columna->verificar(n) != true)
                {
                    temporal = temporal->siguiente;

                }
                else { return true; }
            }
        }
        return false;
    }
    //encontrar punteo
    int sumarPunteo(int cc)
    {
        int puntos=0;
        if (!vacio())
        {
            NodoCab* temporal = primero;
            while (temporal != NULL)
            {
                puntos = puntos + temporal->Columna->sumarPuntosC(cc);
                temporal = temporal->siguiente;

            }
        }
            return puntos;
    }
}Cabeceras;

/// NODO LATERAL
/*Esta estructura define el nodo lateral que nos indica el inicio y fin de una fila*/
typedef struct NodoLat
{
    int y;
    NodoLat* siguiente;
    NodoLat* anterior;
    ListaNodosFil* Filas;
    NodoLat(int y)
    {
        this->y = y;
        Filas = new ListaNodosFil();
        siguiente = NULL;
        anterior = NULL;
    }
} NodoLat;

///// LISTA DE NODOS LATERALES
/*Esta esctrucutra inserta los espacios del primero hasta el ultimo, y es el guia para las filas*/
typedef struct Laterales
{
    NodoLat* primero;
    NodoLat* ultimo;

    Laterales()
    {
        primero = NULL;
        ultimo = NULL;
    }

    void insertar(NodoLat* inserta)
    {
        if (vacio())
        {
            primero = ultimo = inserta;
        }
        else
        {
            if (inserta->y < primero->y)
            {
                insertarFrente(inserta);
            }
            else if (inserta->y > ultimo->y)
            {
                insertarFinal(inserta);
            }
            else
            {
                insertarMedio(inserta);
            }
        }
    }
    bool vacio()
    {
        if (primero == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    //

    void insertarFrente(NodoLat* inserta)
    {
        primero->anterior = inserta;
        inserta->siguiente = primero;
        primero = primero->anterior;
    }
    void insertarFinal(NodoLat* inserta)
    {
        ultimo->siguiente = inserta;
        inserta->anterior = ultimo;
        ultimo = ultimo->siguiente;
    }
    //
    void insertarMedio(NodoLat* inserta)
    {
        NodoLat* temporal1;
        NodoLat* temporal2;
        temporal1 = primero;
        while (temporal1->y < inserta->y)
        {

            temporal1 = temporal1->siguiente;
        }
        temporal2 = temporal1->anterior;

        temporal2->siguiente = inserta;
        temporal1->anterior = inserta;
        inserta->siguiente = temporal1;
        inserta->anterior = temporal2;
    }

    //
    void recorrer()
    {
        if (!vacio())
        {
            NodoLat* temporal = primero;
            while (temporal != NULL)
            {

                //cout << "Filas=" << temporal->y << endl;
                temporal->Filas->recorrer();
                temporal = temporal->siguiente;
            }
        }
    }
    //
    bool existe(int y)
    {
        if (vacio())
        {
            //cout << "no existe lista vacia" << endl;
            return false;
        }
        else
        {
            NodoLat* temporal;
            temporal = primero;
            while (temporal != NULL)
            {
                if (temporal->y == y)
                {
                    return true;
                }
                else if (temporal->siguiente == NULL)
                {
                    //cout << "no se encontro lateral (se insertará) " << endl;
                    return false;
                }
                temporal = temporal->siguiente;
            }
        }
    }
    //
    NodoLat* busqueda(int y)
    {
        if (existe(y))
        {
            NodoLat* temporal;
            temporal = primero;
            while (temporal->y != y)
            {
                temporal = temporal->siguiente;
            }
            return temporal;
        }
        else
        {
            cout << "no existe" << endl;
            return (new NodoLat(-1));
        }
    }
}Laterales;

///// MATRIZ ORTOGONAL
/*Esta estructura es el conjunto de todos los nodos creados: matriz*/
typedef struct MatrizOrtogonal
{
    
    Cabeceras* c;
    Laterales* l;

    MatrizOrtogonal()
    {
        c = new Cabeceras();
        l = new Laterales();
    }
    void insertar(int x, int y, int inserta, bool pivote, int posxy)
    {
        NodoCen* insercion;
        insercion = new NodoCen(inserta, x, y, pivote, posxy);
        if (c->existe(x) == false)
        {
            c->insertar(new NodoCab(x));
        }
        if (l->existe(y) == false)
        {
            l->insertar(new NodoLat(y));
        }
        NodoCab* CabTemp;
        NodoLat* LatTemp; 
        CabTemp = c->busqueda(x);
        LatTemp = l->busqueda(y);
        CabTemp->Columna->insertar(insercion);
        LatTemp->Filas->insertar(insercion);
        //cout << "Se inserto el valor: " << inserta << "<--- en la columna " << x << ", fila " << y << endl;
    }

    void imprimir()
    {
        
        c->imprimir();
        
    }
    void movimiento(int n)
    {
       if (c->verificador(n) == true)
        {
            c->moverPivote(n);
            c->moverNodo(n);
        }
        else
        {
            cout << "No se acepta ese movimiento" << endl;
        }
        //c->moverPivote(n);
       // c->moverNodo(n);

    }
    int puntosFuncion(int cc)
    {
        int puntos=0;
        puntos=c->sumarPunteo(cc);
        return puntos;
    }


}MatrizOrtogonal;

#endif MATRIZ