#include <iostream>
using namespace std;

class Prueba {
public:
    // Constructor
    Prueba() {
        cout << "Objeto creado" << endl;
    }

    // Destructor
    ~Prueba() {
        cout << "Objeto destruido" << endl;
    }
};

int main() {
    Prueba p;
    return 0;
}

