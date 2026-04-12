#include <iostream>
using namespace std;

class CuentaBancaria {
private:
    float saldo;  // atributo privado 

public:
    // Métodos público
    void depositar(float saldo) {
        this->saldo += saldo;
    }
    void mostrarSaldo() {
        cout << "Saldo: $" << this->saldo << endl;
    }
    // Setter
    void setSaldo(int saldo){
        this->saldo = saldo;
    }
};

int main() {
    CuentaBancaria cuenta; // creo objeto

    cuenta.setSaldo(1000); // acceso a atributo privado

    cuenta.depositar(500); 
    cuenta.mostrarSaldo();
    
    return 0;
}

