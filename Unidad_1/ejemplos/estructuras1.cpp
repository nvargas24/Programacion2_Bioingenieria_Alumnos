#include <iostream>

using namespace std;

struct Curso{
    char nombre[50];
    int edad;
    float promedio;
};

int main()
{
    Curso estudiante[3];

    // Carga de estudiantes de la estructura Curso
    estudiante[0] = {"Ana", 20, 8.5};
    estudiante[1] = {"Luis", 22, 7.2};
    estudiante[2] = {"Maria", 21, 9.1};

    // Muestra por terminal contenido
    cout << "Listado de estudiantes "<< endl;
    for(int i=0; i<3; i++){
        cout << "-----------" << endl;
        cout << "Estudiante " << i << endl;
        cout << "Nombre: " << estudiante[i].nombre << endl;
        cout << "Edad: " << estudiante[i].edad << endl;
        cout << "Promedio: " << estudiante[i].promedio << endl;
    }

    return 0;
}