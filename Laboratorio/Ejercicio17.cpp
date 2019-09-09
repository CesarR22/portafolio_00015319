//Ejercicio17 Laboratorio
//CesarAntonio Roque Castro 00015319
#include<iostream>
using namespace std;
int main(void){
	
	int arr[10];
	int j;
	cout << "Ingrese Diez numeros enteros: " << endl;
    for(j=0; j<10; j++){
        cout << "arr[" << j << "]: ";
        cin>>arr[j];
    }
    float suma=0;
    j=0;
    int n=10;
    float promedio=0;
    
    while(j<10){
	suma=suma+arr[j];
	j++;
	promedio=suma/n;
	}
	cout<<"La suma  es: "<<suma<<endl;
	cout<<"El promedio es: "<<promedio<<endl;
	return 0;
	}


