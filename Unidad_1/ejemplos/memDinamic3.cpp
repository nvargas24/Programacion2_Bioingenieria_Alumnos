#include <iostream>
using namespace std;

// Definición de la estructura
struct Paciente {
    char nombre[50];
    int edad;
    float altura;
};

int main() {

    Paciente* pacientes;
    int n;
    
    cout << "Ingrese cantidad de pacientes: ";
    cin >> n;

    pacientes = new Paciente[n]; // Reserva memoria de 'n' pacientes

    // Carga de datos por terminal
    for (int i = 0; i < n; i++) {
        cout << "\nPaciente " << i + 1 << endl;

        cout << "Nombre: ";
        cin >> pacientes[i].nombre;

        cout << "Edad: ";
        cin >> pacientes[i].edad;

        cout << "Altura: ";
        cin >> pacientes[i].altura;
    }

    // Muestra de datos
    cout << "--------------------------" << endl;
    cout << "--- Lista de pacientes ---" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Paciente " << i + 1 << endl;
        cout << "Nombre: " << pacientes[i].nombre << endl;
        cout << "Edad: " << pacientes[i].edad << endl;
        cout << "Altura: " << pacientes[i].altura << endl;

        cout << "Direccion en memoria: " << &pacientes[i] << endl;
        cout << "--------------------------" << endl;
    }

    // Liberación de memoria
    delete[] pacientes;
    pacientes = nullptr;

    return 0;
}