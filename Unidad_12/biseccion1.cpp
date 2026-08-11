#include <iostream>
#include <iomanip> 
#include <cmath>
#include <string>

using namespace std;

// Funciones
double modelo_tendon(double x) {
    return (x * x) - 3.0;
}

double modelo_enzima(double x) {
    // f(x) = (Vmax * x) / (Km + x) - Lavado
    // Con Vmax = 1.5, Km = 0.8, Lavado = 0.5
    return (1.5 * x) / (0.8 + x) - 0.5;
}

double modelo_membrana(double x) {
    // f(x) = exp(-0.1 * x) - 0.5
    return exp(-0.1 * x) - 0.5;
}

// terminal
void mostrar_encabezado_tabla(string nombre_modelo, string ecuacion) {
    cout << "\n===============================================================\n";
    cout << " MODELO SELECCIONADO: " << nombre_modelo << "\n";
    cout << " ECUACION VALORADA:   f(x) = " << ecuacion << "\n";
    cout << "=================== REGISTRO DE ITERACIONES ===================\n";
    
    cout << fixed << setprecision(6);
    cout << setw(6)  << "Iter"   << " | " 
         << setw(12) << "Iqz (a)" << " | " 
         << setw(12) << "Der (b)" << " | " 
         << setw(12) << "Medio (c)" << " | " 
         << setw(12) << "f(c)"     << "\n";
    cout << "---------------------------------------------------------------\n";
}

void mostrar_fila_tabla(int iter, double a, double b, double c, double fc) {
    cout << setw(6)  << iter << " | " 
         << setw(12) << a    << " | " 
         << setw(12) << b    << " | " 
         << setw(12) << c    << " | " 
         << setw(12) << fc   << "\n";
}

void mostrar_reporte_final(double raiz_aprox, int total_iter) {
    cout << "---------------------------------------------------------------\n";
    cout << " >>> METODO FINALIZADO CON EXITO <<<\n";
    cout << " Raiz aproximada encontrada: " << raiz_aprox << "\n";
    cout << " Total de iteraciones ejecutadas: " << total_iter << "\n";
    cout << "===============================================================\n\n";
}

// metodo numerico
void ejecutar_biseccion(double (*f)(double), string nombre, string ecuacion, double a, double b, double tol) {
    int max_iter = 100;
    
    // Validación del Teorema de Bolzano utilizando la función seleccionada
    if (f(a) * f(b) >= 0) {
        cout << "\n[ERROR] El modelo '" << nombre << "' no cambia de signo en [" << a << ", " << b << "].\n";
        return;
    }
    mostrar_encabezado_tabla(nombre, ecuacion);

    double c = 0.0;
    int iter = 0;

    while ((b - a) / 2.0 > tol && iter < max_iter) {
        c = (a + b) / 2.0;
        double fc = f(c); // Evaluación dinámica

        mostrar_fila_tabla(iter, a, b, c, fc);

        if (fc == 0.0) {
            break; 
        } else if (f(a) * fc < 0) {
            b = c; 
        } else {
            a = c; 
        }
        iter++;
    }

    mostrar_reporte_final(c, iter);
}

int main() {
    cout << "=== BANCO DE PRUEBAS: METODOS NUMERICOS EN BIOINGENIERIA ===\n";
    double tolerancia = 0.001;

    ejecutar_biseccion(modelo_tendon, "Elasticidad de Tendon Artificial", "x^2 - 3.0", 1.0, 2.0, tolerancia);
    ejecutar_biseccion(modelo_enzima, "Cinetica Enzimatica (Michaelis-Menten)", "(1.5 * x) / (0.8 + x) - 0.5", 0.1, 1.5, tolerancia);
    ejecutar_biseccion(modelo_membrana, "Potencial Eléctrico de Membrana", "exp(-0.1 * x) - 0.5", 0.0, 10.0, tolerancia);

    return 0;
}
