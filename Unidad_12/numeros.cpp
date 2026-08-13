#include <iostream>
#include <cstdint>

using namespace std;

int main() {
    uint8_t base = 128; 
    uint8_t config = 5; 
    uint8_t preparado = base | config; // 133
    uint8_t resultado = preparado * 2; 

    uint32_t resultado_real = (uint32_t)preparado * 2;

    cout << "Resultado Matematico Real: " << resultado_real << endl;
    cout << "Resultado en uint8_t: " << (unsigned int)resultado << endl;
    
    return 0;
}
