#include <iostream>
#include <vector>
using namespace std;

struct TOrden{
    int revueltas;
    int frijolconqueso;
    int queso;
    string masa;
};
typedef struct TOrden Pupas;

Pupas solicitarPupas(){
    Pupas p;
    cout << "revueltas: "; cin >> p.revueltas;
    cout << "frijolconqueso: "; cin >> p.frijolconqueso;
    cout << "queso : "; cin >> p.queso;
    cout << "de arroz o maiz? : "; cin >> p.masa;
	return p;
}

void mostrarPupas(Pupas p){
    cout << "revueltas: " << p.revueltas << endl;
    cout << "frijolconqueso: " << p.frijolconqueso << endl;
    cout << "queso: " << p.queso << endl;
    cout << "de arroz o masa?: " << p.masa << endl;
    cout << endl;
}

vector<Pupas> lista;

void agregarPupas(){
    Pupas p = solicitarPupas();
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "\t1) Al principio\n\t2) Al final"
            << "\n\tOpcion elegida: ";
        cin >> opcion;
        switch(opcion){
            case 1: lista.insert(lista.begin(), p);
                continuar = false;
            break;
            case 2: lista.push_back(p);
                continuar = false;
            break;
            default: cout << "Opcion erronea!" << endl;
            break;
        }
    }while(continuar);
}

void mostrarLista() {
    for (int i = 0; i < lista.size(); i++) 
        mostrarPupas(lista[i]);
}

int main(){
    cout << "Inicializando..." << endl;
    
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "Menu: \n\t1) Agregar Pupasas\n\t2) Ver pedido"
            << "\n\t3) Salir\n\tOpcion elegida: ";
        cin >> opcion;
        switch(opcion){
            case 1: cout << "Agregando..." << endl;
                agregarPupas();
            break;
            case 2: cout << "Listando..." << endl;
                mostrarLista();
            break;
            case 3: continuar = false;
            break;
            default: cout << "Opcion erronea!" << endl;
            break;
        }
    }while(continuar);

    return 0;
}
