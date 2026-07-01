#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    queue<string> pacientes;

    pacientes.push("Juan");
    pacientes.push("Maria");
    pacientes.push("Carlos");
    pacientes.push("Felipe");

    cout << "Proximo paciente: " << pacientes.front() << endl;
    cout << "Ultimo en llegar: " << pacientes.back() << endl;
    pacientes.pop(); // paciente atendido se quita de queue  
    cout << "Pacientes restantes: " << pacientes.size() << endl;
    cout << "---------------------" << endl;

    cout << "--- Registra nuevo paciente" << endl;
    pacientes.push("Patricio"); 
    cout << "---------------------" << endl;

    cout << "Proximo paciente: " << pacientes.front() << endl;
    cout << "Ultimo en llegar: " << pacientes.back() << endl;
    pacientes.pop(); // paciente atendido se quita de queue 
    cout << "---------------------" << endl;

    cout << "Pendientes: " << endl;
    while (!pacientes.empty()) {
        cout << pacientes.front() << endl;
        pacientes.pop();
    }

    return 0;
}

