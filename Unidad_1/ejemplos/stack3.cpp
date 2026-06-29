#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    stack<string> acciones;

    // carga
    acciones.push("Agregar diagnostico");
    acciones.push("Editar medicacion");
    acciones.push("Eliminar alergia");

    cout << "---------------------" << endl;
    cout << "Ultima accion: " << acciones.top() << endl;
    cout << "Tamanio: " << acciones.size() << endl;
    
    // acceso a stack
    cout << "Listado: " << endl;
    while(! acciones.empty()){
        cout << acciones.top() << endl;
        acciones.pop();
    }

    return 0;
}

