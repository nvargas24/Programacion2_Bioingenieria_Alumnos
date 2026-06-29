#include <iostream>
using namespace std;

class CuentaBancaria {
private:
    float saldo;  // atributo privado 

public:
    // Métodos público
    void depositar(float deposito) {
        if(validacionSaldo(deposito)){
            this->saldo += deposito;
            mostrarSaldo();
        }
    }

    // validacion de dato
    bool validacionSaldo(float deposito){
        if(deposito > 0){
            cout << "[INFO] Deposito valido" << endl;
            return true;
        }
        else{
            cout << "[ERROR] Deposito no valido" << endl;
            return false;
        }
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
    
    return 0;
}

