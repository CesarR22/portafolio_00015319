#include <iostream>
#include <math.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>

/*
Referencias: 
https://codigofacil.net/escoger-nombres-aleatorios-en-c.html
http://www.cplusplus.com/reference/cstdlib/rand/
*/

using namespace std;

struct libro
{
    string nombre;
    int NumeroPaginas;
    libro *sig;
    bool disponibilidad;
};

char *a[] = {
    "Esteban",
    "Dario",
    "Mireya",
    "Nubia",
    "Gustavo Adolfo",
    "Julio",
    "Carlos",
    "Helena",
    "Sebastian",
    "Nicolai",
    "Daniel",
    "Carolina",
    "Hugo",
    "Sandra",
    "Cristina",
};

string generadorNombre(int aux)
{
    srand(time(NULL));
    string nombre,nombrea;
    
    if((aux%2)==0){
        nombre = a[rand() % 12 + 1];
        nombrea = a[rand() % 15 + 1];
    
    }else{
    nombre = a[rand() % 14 + 1];
    nombrea = a[rand() % 12 + 1];};
    
    return nombre + nombrea;
}

class ListaSimple
{
private:
    string nombreLista;
    libro *inicio;

public:
    ListaSimple();
    libro *CrearNodo(int, string);
    void insertarInicio(int, string);
    void insertarFinal(int, string);
    void prestamo(string);
    void regreso(string);
    void mostrar();
};
ListaSimple::ListaSimple()
{
    this->inicio = NULL;
    srand(time(NULL));
    int a = rand() % 100 + 1 ;
    this->nombreLista = generadorNombre(a);
     
}

libro *ListaSimple::CrearNodo(int dato, string nombre)
{
    /*Aca creamos el nodo para despues poder insertarlo*/
    libro *nuevo = new (libro);
    nuevo->NumeroPaginas = dato; //
    nuevo->nombre = nombre;
    nuevo->disponibilidad = true;
    nuevo->sig = NULL;
    return nuevo;
}

void ListaSimple::insertarInicio(int numeropaginas, string nombre)
{
    //insertar el elmento al incio
    libro *nuevo = ListaSimple::CrearNodo(numeropaginas, nombre); /// creamos el nodo
    nuevo->sig = this->inicio;                                    // su sig tiene que ser el inicio de la lista
    this->inicio = nuevo;                                         // cambiamos la referencia
}

void ListaSimple::insertarFinal(int dato, string nombre)
{
    //primero creamos el nodos
    libro *nuevo = ListaSimple::CrearNodo(dato, nombre);
    //crearemos un punetero auxiliar
    libro *aux;
    //primero validaremos si hay algo en nuestra lista
    if (this->inicio)
    {
        aux = this->inicio; //creamos una copia del puntero para no perder la referencia
        //recorreremos la lista hasta el ultimo elemento
        while (aux->sig)
        {
            aux = aux->sig;
        }

        //cuando encontremos el final de lista
        aux->sig = nuevo;  //agregamo al final de la lista
        nuevo->sig = NULL; //le decimos que es el final de la lista
    }
    else
    {
        // si la lista se encuentra vacia
        nuevo->sig = this->inicio; // su sig tiene que ser el inicio de la lista
        this->inicio = nuevo;      // cambiamos la referencia
    }
}

void ListaSimple::prestamo(string nombre)
{
    libro *salto = this->inicio;

    while (salto->sig)
    {
        if (salto->nombre == nombre)
        {
            if (salto->disponibilidad == true)
                {
                cout << "Tu libro esta Disponible" << endl;
                salto->disponibilidad = false;
                }
            else
                {
                cout << "Tu Libro ya se fue prestado" << endl;
                }
            break;
        }
        else
        {
            salto = salto->sig;
        }
    }

 
}

void ListaSimple::regreso(string nombre)
{
    libro *salto = this->inicio;

    while (salto->sig)
    {
        if (salto->nombre == nombre){
            if (salto->disponibilidad == false){
                cout << "Gracias por Devolver tu Libro" << endl;
                salto->disponibilidad = true;
            }
            else
            {
                cout << "¿Como puedes devolver un libro que no has prestado?" << endl;
                salto = salto->sig;
            };
        }
        else
        {
            salto = salto->sig;
        };
    }
}

void ListaSimple::mostrar()
{

    libro *salto = this->inicio;

    cout << this->nombreLista << endl;
    while (salto)
    {
        cout << salto->NumeroPaginas << " " << salto->nombre << " " << salto->disponibilidad << " " << endl;

        salto = salto->sig;
    }
    cout << "\n";
}

int main()
{
    ListaSimple l, m;
    m.insertarInicio(666, "Nosferatu");

    l.insertarInicio(42, "Moby Dick");
    l.insertarFinal(69, "Tarzan");
    l.insertarFinal(420, "Como ser millonario");

    l.mostrar();
    l.prestamo("AAA");

    l.mostrar();
    l.regreso("Tarzan");

    l.mostrar();
    m.mostrar();
    return 0;
}
