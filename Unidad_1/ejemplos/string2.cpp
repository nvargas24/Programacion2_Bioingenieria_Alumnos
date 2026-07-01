#include <iostream>
#include <string>
using namespace std;

struct Curso{
    string nombre;
    int edad;
    float promedio;
};

int main()
{
    Curso estudiante = {"Carlos", 23, 8.8};

    // Puntero a estructura
    Curso *ptr = &estudiante;

    // Modificación usando ->
    ptr->nombre = "Felipe";
    ptr->edad = 25;
    ptr->promedio = 9.5;

    cout << "Modifico con -> :" << endl;
    cout << "Nombre: " << estudiante.nombre << endl;
    cout << "Edad: " << estudiante.edad << endl;
    cout << "Promedio: " << estudiante.promedio << endl;

    return 0;
}

