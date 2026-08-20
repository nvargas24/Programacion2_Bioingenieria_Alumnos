#include "metodos_numericos/newton_raphson.h"
#include <iostream>

using namespace std;

#define VALOR_INICIAL           3.95f
#define ITERACIONES_SOLICITADAS 5
#define RANGO_INFERIOR          0.0f
#define RANGO_SUPERIOR          5.0f
#define RAIZ_TEORICA     1.133107f // Raíz real suave del polinomio introductorio

// Envoltura limpia para pasar la función matemática como puntero
float evaluar_sensor(float x) {
    // f(x) = 0.2*x^3 - 2*x + 2
    return ((0.2f * (x) * (x) * (x)) - (2.0f * (x)) + 2.0f);  
}

int main() {
    // Declaración única de las variables de estado al principio del bloque
    float resultado_sensor;
    int estado_modulo;

    resultado_sensor = 0.0f;

    cout << "Valor inicial enviado: " << VALOR_INICIAL << "\n";
    cout << "Limites operacionales: [" << RANGO_INFERIOR << " a " << RANGO_SUPERIOR << "]\n";
    cout << "Raiz teorica configurada: " << RAIZ_TEORICA << "\n\n";

    estado_modulo = calcular_newton_raphson(evaluar_sensor, 
                                            VALOR_INICIAL, 
                                            ITERACIONES_SOLICITADAS, 
                                            RANGO_INFERIOR, 
                                            RANGO_SUPERIOR, 
                                            RAIZ_TEORICA, 
                                            &resultado_sensor);


    return 0;
}
