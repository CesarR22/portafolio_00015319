#include <iostream>
#include <stdlib.h>
using namespace std;

struct nodo
{
int dato;
struct nodo *left;
struct nodo *right;
};

int numNodos = 0;

typedef struct nodo Nodo;
typedef struct nodo *Arbol;
Arbol crearArbol(int x)
{
Arbol p = new Nodo;
p->dato = x;
p->left = NULL;
p->right = NULL;
return p;
}

int suma(Arbol a){
    int dato;
    if(a==0)
        return 0;
    return a->dato + suma(a->left) + suma(a->right);
}

void Nodos(Arbol a, int n)
{
if (a == NULL)
return;
Nodos(a->right, n + 1);
for (int i = 0; i < n; i++)
cout << " ";
numNodos++;
cout << a->dato << endl;
Nodos(a->left, n + 1);
}

int Niveles(Arbol a)
{
int Altleft, Altright;
if (a == NULL)
return -1;
else
{
Altleft = Niveles(a->left);
Altright = Niveles(a->right);
if (Altleft > Altright)
return Altleft + 1;
else
return Altright + 1;
}
}

void asignarleft(Arbol a, int unDato)
{
if (a == NULL)
cout << "Error: arbol vacio" << endl;
else if (a->left != NULL)
cout << "Error: subarbol left ya existe" << endl;
else
a->left = crearArbol(unDato);
}
void asignarright(Arbol a, int unDato)
{
if (a == NULL)
cout << "Error: arbol vacio" << endl;
else if (a->right != NULL)
cout << "Error: subarbol right ya existe" << endl;
else
a->right = crearArbol(unDato);
}
void agregarNodo(Arbol a)
{
int numero = 0;
cout << "Numero a agregar: ";
cin >> numero;
Arbol p = a;

while (true)
{
if (numero == p->dato)
{
cout << "Error: " << numero << " ya existe" << endl;
return;
}
else if (numero < p->dato)
{

if (p->left == NULL)
break;
else
p = p->left;
}
else
{

if (p->right == NULL)
break;
else
p = p->right;
}
}
if (numero < p->dato)
asignarleft(p, numero);
else
asignarright(p, numero);
}

void preorden(Arbol a)
{
if (a != NULL)
{
cout << " " << a->dato;
preorden(a->left);
preorden(a->right);
}
}
void inorden(Arbol a)
{
if (a != NULL)
{
inorden(a->left);
cout << " " << a->dato;
inorden(a->right);
}
}
void postorden(Arbol a)
{
if (a != NULL)
{
postorden(a->left);
postorden(a->right);
cout << " " << a->dato;
}
}
void recorrerArbol(Arbol a)
{
cout << "Recorrido PRE orden:";
preorden(a);
cout << endl;
cout << "Recorrido IN orden:";
inorden(a);
cout << endl;
cout << "Recorrido POST orden:";
postorden(a);
cout << endl;
int main()
{
int variable = 0;
cout << "Inicializando arbol...\nValor contenido en la raiz: ";
cin >> variable;
Arbol arbol = crearArbol(variable);
bool continuar = true;
do
{
int opcion = 0;
cout << "Menu: \n\t1) Agregar\n\t2) Recorrer\n\t3) Cant. nodos\n\t4) Cant. niveles\n\t5) Suma"
<< "\n\t6) Salir\n\tOpcion elegida: ";
cin >> opcion;
switch (opcion)
{
case 1:
agregarNodo(arbol);
break;
case 2:
recorrerArbol(arbol);
break;
case 3:
Nodos(arbol, 0);
cout<<"el numero de nodos es: ";
cout<<numNodos<<endl;
break;
case 4:
int h;
h = Niveles(arbol);
cout<<"El numero de niveles es: "<<h<<endl;
break;
                case 5:
                    cout<<"la suma de los nodos es: "<<suma(arbol)<<endl;
                    break;
                case 6:
continuar = false;
break;

}
} while (continuar);
return 0;
}
