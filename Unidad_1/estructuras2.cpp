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
        cout << "***********" << endl;
        cout << "Estudiante " << i << endl;
        cout << "-----------" << endl;
        cout << "Direccion de memoria estructura: " << &estudiante << endl; //sin asignar posicion el espacio de memoria es en posicion '0'
        cout << "Direccion de memoria posicion " << i << ": "<< &estudiante[i] << endl;
        cout << "Espacio en memoria que ocupa estructura: " << (char*)&estudiante[i+1] - (char*)&estudiante[i] << " bytes"<<endl<<endl;  
        
        cout << "Direccion de memoria de char[]: " << &estudiante[i].nombre << "  ---Ocupa: "<< sizeof(estudiante[i].nombre) << " bytes"<< endl;
        cout << "Direccion de memoria de int: " << &estudiante[i].edad << "  ---Ocupa: "<< sizeof(estudiante[i].edad) << " bytes"<< endl;
        cout << "Direccion de memoria de float: " << &estudiante[i].promedio << " ---Ocupa: "<< sizeof(estudiante[i].promedio) << " bytes"<< endl;
        
        cout << "Espacion en memoria de estructura sin padding: " << sizeof(estudiante[i].nombre) + sizeof(estudiante[i].edad) + sizeof(estudiante[i].promedio) << " bytes" << endl; cout << endl;
    }

    return 0;
}