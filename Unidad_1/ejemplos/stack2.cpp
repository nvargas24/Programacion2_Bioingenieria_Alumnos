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
    // deshacer
    if (!acciones.empty()) {
        cout << "Accion deshecha :" << acciones.top()<< endl;
        acciones.pop();
    }

    cout << "Nueva ultima accion: " << acciones.top() << endl;
    cout << "Nuevo tamanio: " << acciones.size() << endl;

    return 0;
}

