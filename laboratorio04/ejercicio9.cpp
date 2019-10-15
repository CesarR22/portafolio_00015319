#include <iostream> 
using namespace std; 
struct nodo{
string nombre; 
int edad;
nodo *sig;
}; 
class datosPersona{
private:nodo *list;
public: datosPersona(){list = NULL;}
void llenarLista(string, int);
void mostrarPersona();
void eliminarPersona(string);
void actualizarPersona(string);
	};
	 int main()
	{
	datosPersona lista;
	string nombre;
	int edad;
	int opt;
	char siNo;
		 do{ 
		 
		 cout<<"====.:MENU:.===="<<endl;
		 cout<<"==OPCIONES A ELEGIR=="<<endl;
		 cout<<"1. LLENAR LISTA" <<endl;
		 cout<<"2. MOSTRAR PERSONA" <<endl;
		 cout<<"3. ELIMINAR PERSONA" <<endl;
		 cout<<"4. ACTUALIZAR" <<endl;
		 cout<<"5. EXIT" <<endl;
		 cout<<"\n.:Seleccione una opcion:. = " <<endl;
		 cin>>opt;
		  switch(opt){ 
		  case 1: 
		  do{
		  cout<<"\nNombre: ";
		  cin>>nombre;
		  cout<<"Edad: ";
		  cin>>edad;lista.llenarLista(nombre, edad);
		  cout<<"Desea agregar otra persona(s/n)? "<<endl;
		  cin>>siNo;
		  }
		  while(siNo == 's');
		   break;
		    case 2:lista.mostrarPersona(); 
			break; 
			case 3:cout<<"Nombre de persona a eliminar : ";
			cin>>nombre;lista.eliminarPersona(nombre);
			 break; 
			 case 4:cout<<"Nombre de persona a actualizar: ";
			 cin>>nombre;lista.actualizarPersona(nombre); 
			 break
			 ;} 
			 
			 }
			 while(opt != 5); 
			 return 0;}
			 
			 void datosPersona::llenarLista(string nombre, int edad)
			 {nodo *New_nodo = new nodo;
			 New_nodo->nombre = nombre;
			 New_nodo->edad = edad;
			  New_nodo->sig = list;
			  list = New_nodo;}
	
			  void datosPersona::mostrarPersona(){
			  nodo *actual = new nodo;
			  actual = list; 
			  while(actual != NULL)
			  {
			  cout<<endl<<"Nombre: "<<actual->nombre<<endl;
			  cout<<"Edad: "<<actual->edad<<endl;actual = actual->sig;}}
			 
			  void datosPersona::eliminarPersona(string nombre)
			  {
			  nodo *aux_delete = list;
			  nodo *previous = NULL;
			   while((aux_delete != NULL) && (aux_delete->nombre != nombre))
			   {previous = aux_delete;
			   aux_delete = aux_delete->sig;} 
			   if(aux_delete == NULL)
			   {
			   cout<<"NO SE ENCONTRO!"<<endl;
			   } 
			   else if(previous == NULL){
			   list = list->sig;
			    delete aux_delete;
				} 
				else{previous->sig = aux_delete->sig;
				 delete aux_delete;
				 }
				 }
				
				 void datosPersona::actualizarPersona(string nombre)
				 {
				 string nuevoNombre;
				  int edad;
				  nodo *actual = new nodo;
				  actual = list;
				   while(actual->nombre != nombre) {
				   actual = actual->sig;
				   }
			}
