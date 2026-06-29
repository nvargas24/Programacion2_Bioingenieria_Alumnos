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

    cout << "Acceso usando operador . :" << endl;
    cout << "-------------------------------"<< endl;
    cout << "Nombre: " << estudiante.nombre << endl;
    cout << "Edad: " << estudiante.edad << endl;
    cout << "Promedio: " << estudiante.promedio << endl;

    cout << "*******************************"<< endl;

    cout << "Acceso usando puntero y operador -> :" << endl;
    cout << "-------------------------------"<< endl;
    cout << "Nombre: " << ptr->nombre << endl;
    cout << "Edad: " << ptr->edad << endl;
    cout << "Promedio: " << ptr->promedio << endl;

    return 0;
}

