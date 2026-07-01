#include <iostream>

using namespace std;

// Declaracion de namespaces
namespace Operacion{
    namespace Impar{
        int suma(int a, int b, int c, int d){
            return a+c;
        }
        int resta(int a, int b, int c, int d){
            return a-c;
        }
    }
    namespace Par{
        int suma(int a, int b, int c, int d){
            return b+d;
        }
        int resta(int a, int b, int c, int d){
            return b-d;
        }
        
    }
}

int main()
{
    cout << "Suma de impares: " << Operacion::Impar::suma(2,3,4,5) << endl;
    cout << "Resta de pares: " << Operacion::Par::resta(2,3,4,5) << endl;

    return 0;
}