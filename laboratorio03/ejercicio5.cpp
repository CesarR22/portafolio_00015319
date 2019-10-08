#include<iostream>
using namespace std;

struct nodo{
	int dato;
	nodo *ant;
	nodo *sig;
	

nodo *crear(nodo *rot, int d){
	nodo *nuevo= new nodo;
	nuevo->dato=d;
	nuevo->ant=NULL;
	nuevo->sig=NULL;
	rot=nuevo;
	return rot;
}
nodo *insertar(nodo *rot, int d){
	nodo *nuevo= new nodo;
	nuevo->dato=d;
	nuevo->ant=NULL;
	nuevo->sig=rot;
	rot->ant=nuevo;
	rot=nuevo;
	return rot;
}

void mostrar(nodo *rot){
	nodo *aux=rot;
	while(aux !=NULL){
	cout<<aux->dato<<endl; 
	aux=aux->sig;
}
}
void mostrar2(nodo *rot){
	nodo *aux=rot;
	while(aux->sig!=NULL){
		aux=aux->sig;
	}
	while(aux !=NULL){
	cout<<aux->dato<<endl; 
	aux=aux->ant;
}
}
};

int main(void){
	
	nodo *rot=NULL;
	nodo *p;
	rot=p->crear(rot,40);
	rot=p->insertar(rot,30);
	rot=p->insertar(rot,20);
    rot=p->insertar(rot,10);
    cout<<"lista"<<endl;
	p->mostrar(rot);
	cout<<"lista inversa"<<endl;
	p->mostrar2(rot);
	
	return 0;
}
