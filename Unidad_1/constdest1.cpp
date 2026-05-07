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

            cout<<"[Constructor] Sensor inicializado: "
            <<nombre<< " -> " <<valor<<endl;
        }
        void mostrar() {
            cout<<"Sensor: " <<nombre<<" | Valor: " <<valor<<endl;
        }
        ~Sensor() {
            cout << "[Destructor] Liberando sensor: "<<nombre<<endl;
        }
};

int main() {
    Sensor temperatura("Temperatura", 24.5);
    Sensor presion("Presion", 101.3);

    temperatura.mostrar();
    presion.mostrar();

    return 0;
}

