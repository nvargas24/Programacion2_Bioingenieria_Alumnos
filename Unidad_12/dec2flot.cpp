#include <iostream>
#include <bitset>    // Requerido para imprimir en binario
#include <cstdint>   // Requerido para uint32_t
#include <cstring>   // Requerido para memcpy

using namespace std;

int main() {
    float numero_decimal = -6.5f;
    
    uint32_t bits;
    uint32_t signo;
    uint32_t exponente_sesgado;
    int exponente_real;
    uint32_t mantisa;

    memcpy(&bits, &numero_decimal, sizeof(float));
    signo = (bits >> 31) & 0x1;
    exponente_sesgado = (bits >> 23) & 0xFF;
    exponente_real = (int)exponente_sesgado - 127;
    mantisa = bits & 0x7FFFFF;

    cout << "Numero decimal original   : " << numero_decimal << endl << endl;
    cout << "Trama completa (32 bits)  : " << bitset<32>(bits) << endl << endl;

    cout << "--- Desglose por partes ---" << endl;
    cout << "Signo (1 bit)       : " << bitset<1>(signo) << endl;
    cout << "Exponente (8 bits)  : " << bitset<8>(exponente_sesgado) << endl;
    cout << "  > Exponente Sesgado (en trama): " << exponente_sesgado << endl;
    cout << "  > Exponente Real (matematico) : " << exponente_real << "  (Formula: " << exponente_sesgado << " - 127)" << endl;
    cout << "Mantisa (23 bits)   : " << bitset<23>(mantisa) << endl;

    return 0;
}
