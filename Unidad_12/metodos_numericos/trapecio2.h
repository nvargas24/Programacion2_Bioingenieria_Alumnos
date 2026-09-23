#ifndef TRAPECIO2_H
#define TRAPECIO2_H

#include <vector>

struct Punto2D {
    double x;
    double y;
};

int calcular_trapecio_muestras(const std::vector<Punto2D>& puntos, float* resultado_integral);

#endif // TRAPECIO2_H
