#include <iostream>
#include <cstring> // para usar strcat
#include <string>
using namespace std;

int main() {
    char nombre1[20] = "Juan";
    string nombre2 = "Juan";
    
    // Arreglo (C)
    strcat(nombre1, " Perez");  

    // String (C++) 
    nombre2 += " Perez";

    cout << "Char array: " << nombre1 << endl;
    cout << "String: " << nombre2 << endl;

    return 0;
}
