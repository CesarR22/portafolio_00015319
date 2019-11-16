#include <iostream>
using namespace std;
struct nodo
{
	int dato;
	nodo *sig;
};
struct arbol
{
	int dato;
	arbol *Izq;
	arbol *Der;
};
nodo *pInicio = NULL;
arbol *pArbol = NULL;
void insertarInicioLista(int);
void mostrarLista(void);
void mostrarLista(nodo *);
void mostrarIn(void);
void mostrarIn(arbol *);
void insNodo(int);
void insNodo(arbol **, int);
void insNodo(int dato) { insNodo(&pArbol, dato); }
void insNodo(arbol **p, int dato)
{
	if (!(*p))
	{
		*p = new arbol;
		(*p)->dato = dato;
		(*p)->Izq = (*p)->Der = NULL;
	}
	else if(dato < (*p)->dato)
	{
		insNodo(&((*p)->Izq), dato);
	}
	else if(dato > (*p)->dato)
	{
		insNodo(&((*p)->Der), dato);
	}
	else cout << "El nodo ya existe\n";
}
void mostrarIn(void)
{
	mostrarIn(pArbol);
}
void mostrarIn(arbol *p)
{
	if (p != NULL)
	{
		mostrarIn(p->Izq);
		cout << p->dato << " ";
		mostrarIn(p->Der);
	}
}
void insertarInicioLista(int dato)
{
	nodo *nuevo;
	nuevo = new nodo;
	nuevo->dato = dato;
	nuevo->sig = pInicio;
	pInicio = nuevo;
}
void mostrarLista(void) { mostrarLista(pInicio); }
void mostrarLista(nodo *s)
{
	cout << "Los elementos de la lista son:" << endl;
	while (s != NULL)
	{
		cout << s->dato << " ";
		int d = s->dato;
		insNodo(d);
		s = s->sig;
	}
}
int main()
{
	char resp;
	int dato;
	cout << "Desea meter un dato (s/n)?";
	cin >> resp;
	while (resp == 's')
	{
		cout << "Digite el dato: ";
		cin >> dato;
		insertarInicioLista(dato);
		cout << "Desea meter un dato (s/n)?";
		cin >> resp;
	}
	mostrarLista();
	cout << "\nMostrar in-orden (ascendente):" << endl;
	mostrarIn();
	return 0;
}
