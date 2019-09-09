//Ejercicio 23 laboratorio
//Cesar Antonio Roque Castro 00015319
# include <iostream>
# include <stdlib.h>
using namespace std ;
 
void sumaDeComplejos ( int , int , int , int , int & , int & ) ;
 
int main ()
{
	int j;
	int parteReal [ 2 ] ;
	int parteIma [ 2 ] ;
	int resulReal ;
	int resulIma ;
	char * numeros [] = { "Primer" , "Segundo" , "Tercer" } ;
	for ( int i = 0 ; i < 2 ; i ++ )
	{
	    cout << "\n Parte Real del " << numeros [ i ] << " Numero : " ;
		cin >> parteReal [ i ] ;
		cout << "\n Parte Imaginaria del " << numeros [ i ] << " Numero : " ;
		cin >> parteIma [ i ] ;
	}
	
	
	sumaDeComplejos ( parteReal [ 0 ] , parteIma [ 0 ] , parteReal [ 1 ] , parteIma [ 1 ] , resulReal , resulIma ) ;
	
 
	
	cout << "\n Resultado Parte Real : " << resulReal ;
	cout << "\n Resultado Parte Imaginaria : " << resulIma ;
	
 
 
	
	
	return 0 ;
}
 
void sumaDeComplejos ( int real1 , int ima1 , int real2 , int ima2 , int & rReal , int & rIma )
{
	rReal = real1 + real2 ;
	rIma = ima1 + ima2 ;
}
*/
