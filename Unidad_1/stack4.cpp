#include <iostream>
#include <stack>
#include <string>
using namespace std;

void deshacer(stack<string>*, stack<string>*);
void rehacer(stack<string>&, stack<string> &);

int main() {
    stack<string> acciones;
    stack<string> aux;

    // carga
    acciones.push("Agregar diagnostico");
    acciones.push("Editar medicacion");
    acciones.push("Eliminar alergia");
    cout << "---------------------" << endl;

    // deshacer
    deshacer(&acciones, &aux);
    cout << "Nueva ultima accion: " << acciones.top() << endl;
    cout << "Tamanio acciones: " << acciones.size() << endl;
    cout << "---------------------" << endl;

    // rehacer
    rehacer(acciones, aux);

    cout << "Ultima accion actual: " << acciones.top() << endl;
    cout << "Tamanio acciones: " << acciones.size() << endl;

    
    return 0;
}

void deshacer(stack<string>* reg, stack<string>* aux){
    if (!(*reg).empty()) { // verifica si hay acciones registradas
        cout << "Accion deshecha: " << (*reg).top() << endl;
        aux->push(reg->top()); // guarda ultima accion registrada
        reg->pop();
    }
}

void rehacer(stack<string>& reg, stack<string>& aux){
    if (!aux.empty()) { // verifica si se registro algun dato eliminado del stack
        cout << "Rehaciendo accion: " << aux.top() << endl;
        reg.push(aux.top()); // cargo ultima accion borrada
        aux.pop();
    }
}