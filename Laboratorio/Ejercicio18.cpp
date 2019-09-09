//Ejercicio 18
//Cesar Antonio Roque Castro 00015319
#include<iostream>

using namespace std;
int main()
{
int j;
int k;
int fila=0;
int columna=0;
cout<<".:Ingrese los siguientes datos:.\n";
cout<<"# de filas: ";
cin>>fila;
cout<<"# de columnas:";
cin>>columna;
for(j=0;j<=fila;j++){
for(k=0; k<=columna;k++){
		if(j<=k){
			cout<<j<<k<<"";	
		}
		else{
			cout<<"00";	
		}
	}cout<<endl;
}
return 0;
}

