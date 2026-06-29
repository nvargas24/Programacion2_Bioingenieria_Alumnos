#include <iostream>
#include <queue>
#include <string>
using namespace std;

void mostrarEstado(queue<string>& );
void cargaPaciente(queue<string>&, string);
void atenderPaciente(queue<string>&);

int main() {
    queue<string> pacientes;

    cargaPaciente(pacientes, "Juan");
    cargaPaciente(pacientes, "Maria");
    cargaPaciente(pacientes, "Carlos");
    cargaPaciente(pacientes, "Felipe");
    mostrarEstado(pacientes);
    
    atenderPaciente(pacientes);
    mostrarEstado(pacientes);

    cargaPaciente(pacientes, "Patricio");
    mostrarEstado(pacientes);

    atenderPaciente(pacientes);
    mostrarEstado(pacientes);

    return 0;
}

void mostrarEstado(queue<string>& reg){
    if(! reg.empty()){
        cout << "Proximo paciente: " << reg.front() << endl;
        cout << "Ultimo en llegar: " << reg.back() << endl;
        cout << "Pacientes restantes: " << reg.size() << endl;
        cout << "---------------------" << endl;
    }
    else
        cout << "Sin pacientes pendientes"  << endl;
}

void atenderPaciente(queue<string>& reg){
    if(! reg.empty()){
        cout << "Atendiendo a : " << reg.front() << endl;
        reg.pop();
    }
}

void cargaPaciente(queue<string>& reg, string nuevo){
    reg.push(nuevo); 
    cout << "--- Registra nuevo paciente: " << reg.back() <<endl;
    cout << "---------------------" << endl;
}

