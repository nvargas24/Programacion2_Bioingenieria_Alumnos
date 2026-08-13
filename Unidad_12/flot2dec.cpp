#include <iostream>
#include <bitset>    // Requerido para imprimir en binario
#include <cstdint>   // Requerido para uint32_t
#include <cmath>     // Requerido para pow

using namespace std;

int main() {
    uint32_t bits_entrada = 0b11000000110100000000000000000000u;

    uint32_t signo;
    uint32_t exponente_sesgado;
    int exponente_real;
    uint32_t mantisa_bits;
    
    double mantisa_fraccionaria;
    double valor_mantisa_completa;
    double resultado_final;
    int i;
    uint32_t bit_actual;

    signo = (bits_entrada >> 31) & 0x1;
    exponente_sesgado = (bits_entrada >> 23) & 0xFF;
    exponente_real = (int)exponente_sesgado - 127;
    mantisa_bits = bits_entrada & 0x7FFFFF;

    // Cálculo de valor matemático de 2^(-i)
    mantisa_fraccionaria = 0.0;
    for (i = 1; i <= 23; ++i) {
        bit_actual = (mantisa_bits >> (23 - i)) & 0x1;
        if (bit_actual == 1) {
            mantisa_fraccionaria += pow(2, -i);
        }
    }

    valor_mantisa_completa = 1.0 + mantisa_fraccionaria;
    resultado_final = pow(-1, signo) * valor_mantisa_completa * pow(2, exponente_real);

    cout << "Trama binaria analizada: " << bitset<32>(bits_entrada) << endl << endl;
    
    cout << "--- Componentes Extraidos ---" << endl;
    cout << "Signo              : " << signo << " (Significa: " << (signo == 1 ? "Negativo" : "Positivo") << ")" << endl;
    cout << "Exponente Sesgado  : " << exponente_sesgado << endl;
    cout << "Exponente Real     : " << exponente_real << " (Calculado como: " << exponente_sesgado << " - 127)" << endl;
    cout << "Mantisa (en bits)  : " << bitset<23>(mantisa_bits) << endl << endl;

    cout << "--- Procesamiento Matematico ---" << endl;
    cout << "Valor fraccionario de la mantisa : " << mantisa_fraccionaria << endl;
    cout << "Valor de mantisa con 1 implicito : " << valor_mantisa_completa << endl<< endl;

    cout << "--- Resultado de la Conversion ---" << endl;
    cout << "Valor interpretado: " << resultado_final << endl;

    return 0;
}
