#include <iostream>

using namespace std;

float evaluar(int correlativo)
{
    float puntaje = 0;
    char opcion;
    cout << "\nInicio de preguntas\nAspirante: " << correlativo + 1 << endl;
    
    //Pregunta 1
    cout << "\n1) Â¿Cuanto espera ganar?\n(a) De 300 a 500.\n(b) De 500 en adelante.\nR//";
    cin >> opcion;
    if(opcion=='a')
        puntaje++;

    //Pregunta 2
    cout << "\n2) Â¿Como considera su desempeÃ±o al realizar un trabajo?\n(a) Muy alto\n(b) Regular \nR//";
    cin >> opcion;
    if(opcion=='a')
        puntaje++;
    
    //Pregunta 3
    cout << "\n3) Â¿Usted como se desenvuelve en un ambiente grupal?\n(a) Me gusta mas trabajar de forma individual.\n(b) Me desenvuelvo muy bien con los demas\nR//";
    cin >> opcion;
    if(opcion=='b')
        puntaje++;
	
	cin.ignore();
	
    //Pregunta 4
    cout << "\n4) Â¿Se considera un buen lider?\n(a) Si\n(b) No\nR//";
    cin >> opcion;
    if(opcion=='a')
        puntaje++;

    //Pregunta 5
    cout << "\n5) Â¿Como se siente al trabajar bajo presion?\n(a) Estresado y presionado.\n(b) Trabajo mejor bajo presion\nR//";
    cin >> opcion;
    if(opcion=='b')
        puntaje++;
        
    cin.ignore();    
    
    return puntaje;
}

float bonus(int correlativo)
{
    float extra=0;
	int op;
	
	
	
	cout<<"\nInicio de preguntas bono\nAspirante: "<< correlativo + 1<<endl;
	cout<<endl;
	cout<<"Usted puede acumular maximo 3 puntos de bonificacion"<<endl; //
	cout<<"\n1)¿que nivel de ingles maneja: "<<endl;
	cout<<"[1]- 10%-25%"<<endl;
	cout<<"[2]- 25%-50%"<<endl;
	cout<<"[3]- 50%-100%"<<endl;
	cin>>op;
	switch(op){
		case 1:
			extra++;
			break;
		case 2:
			extra+= 2;
			break;
		case 3:
			extra+= 3;
			break;
		default:
			cout<<"Elija una opcion disponible"<<endl;		
	}
	
	 op=0;
	
	
	cout<<"\n2)¿cual es su experiencia laboral: "<<endl;
	cout<<"[1]- 1 anio - 2 anios"<<endl;
	cout<<"[2]- 3 anios - 5 anios"<<endl;
	cin>>op;
	switch(op){
		case 1:
			extra++;
			break;
		case 2:
			extra+= 2;
			break;
		default:
			cout<<"Elija una opcion disponible"<<endl;		
	}
	
	op=0;
	
    cout<<"\n3) Dominio Informatico: "<<endl;
	cout<<"[1]- Basico"<<endl;
	cout<<"[2]- Intermedio"<<endl;
	cout<<"[3]- Avanzado"<<endl;
	cin>>op;
	switch(op){
		case 1:
			extra++;
			break;
		case 2:
			extra+= 2;
			break;
		case 3:
			 extra +=3;
		default:
			cout<<"Elija una opcion disponible"<<endl;		
	}
	
	cin.ignore();	
	
    return (extra/3)*1; 
    //devuelve porcentaje de bonus dividido entre tres ya que 9 bonos de maximo nos da 9 por eso dividimos entre las 3 preguntas.
}

int mayor(float arreglo[], int j)
{
    int may = arreglo[0];
    int limite = j-1;
    if(j==0)
    {
        limite = j;
    }
    for(int i = 0; i <= limite; i++)
    {
        if(arreglo[i]>may)
            may=arreglo[i]; 
    }
    return may;
}

void imprimir(float tabla[], int k)
{
    cout << "\nTabla de calificaciones" << endl;
    for(int i = 0; i <= k; i++)
        cout << "\nAspirante: " << i + 1 << " | Calificacion: " << tabla[i] << " | Probabilidad: " << tabla[i]*12.5<< "%" <<endl;
}

int main(int argc, char const *argv[])
{
	int aux;
    int respuesta;
    int estado = 0;
    cout<<"        .:-----BIENVENIDO AL CALL CENTER M.C.P.R:.-----:."<<endl;
    cout<<endl;
  
    cout<<"****:::::*******:::::::********:::::::*******:::::::****::::****"<<endl; 
    cout << "            .:SISTEMA DE SELECCION DE PERSONAL:."<<endl;
    cout<<"****:::::*******:::::::********:::::::*******:::::::****::::****"<<endl;
    cout<<endl;
    
    cout<<"<-<-<-<-Numero de Aspirantes (no pueden ser menos de 3 aspirantes 0) ->->->->: ";
    cin >> respuesta;
    if(respuesta>2){
	
    
    float resultados[respuesta];
    for(int i = 0; i < respuesta; i++)
    {
    	cout << i << endl; 
	    resultados[i] = evaluar(i)+bonus(i);  
        cout << "\nResultado: " << resultados[i] << endl;
		  		
       if(resultados[i]>mayor(resultados,i))
        {
        	aux=i;
        	estado =1;
        }
    }
    
    cout<<"Contratar al aspirante: "<<aux+1<<endl;
    imprimir(resultados,respuesta-1);

if(estado==0)//si da 0, ninguno se contrata.
        cout << "Todos han obtenido la misma calificación. Utilice otro medio de selección";}
        
    else{
    	cout<<"Ingrese mas aspirantes!! :)";
	}
    return 0;
}
