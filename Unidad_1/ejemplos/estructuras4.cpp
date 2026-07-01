#include <iostream>
using namespace std;

struct Curso{
    char nombre[50];
    int edad;
    float promedio;
};

int main()
{
    Curso estudiante = {"Carlos", 23, 8.8};

    // Puntero a estructura
    Curso *ptr = &estudiante;

    // Modificación usando ->
    ptr->edad = 25;
    ptr->promedio = 9.5;

    cout << "Modifico con -> :" << endl;
    cout << "Edad: " << estudiante.edad << endl;
    cout << "Promedio: " << estudiante.promedio << endl;

    return 0;
}