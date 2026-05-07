#include <iostream>
#include <string>

using namespace std;

class Sensor {
private:
    string nombre;
    float valor;
public:
    Sensor(string n, float v) {
        nombre = n;
        valor = v;
        cout << "[Constructor 1] Sensor inicializado: "
             << nombre << " -> " << valor << endl;
    }
    Sensor(string n) {
        nombre = n;
        cout << "[Constructor 2] Sensor inicializado: "<< nombre << endl;
    }
    void mostrar() {
        cout << "Sensor: "<< nombre
             << " | Valor: "<< valor << endl;
    }
    ~Sensor() {
        cout << "[Destructor] Liberando sensor: "<< nombre << endl;
    }
};

int main() {
    Sensor temperatura("Temperatura", 24.5);
    Sensor* presion = new Sensor("Presion", 101.3);
    Sensor humedad("Humedad");

    temperatura.mostrar();
    humedad.mostrar();
    presion->mostrar();

    delete presion;
    presion = nullptr;

    return 0;
}