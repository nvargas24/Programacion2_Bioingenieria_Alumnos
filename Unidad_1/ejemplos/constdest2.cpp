#include <iostream>
#include <string>

using namespace std;

class Sensor {
private:
    string nombre;
    float valor = 0.0;
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
        cout << "Sensor: "<< nombre;
        if(valor)
            cout << "| Valor: "<< valor << endl;
        else
            cout << endl;
    }
    ~Sensor() {
        cout << "[Destructor] Liberando sensor: "<< nombre << endl;
    }
};

int main() {
    Sensor temperatura("Temperatura", 24.5);
    Sensor presion("Presion");
    Sensor* humedad = new Sensor("Humedad", 40);    

    temperatura.mostrar();
    presion.mostrar();
    humedad->mostrar();
    
    delete humedad;
    humedad = nullptr;

    return 0;
}