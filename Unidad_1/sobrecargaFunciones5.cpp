#include <iostream>
using namespace std;

double suma(int , int);
double suma(double , int);
double suma(float, float);

int main()
{
    cout << "Suma 1: " << suma(2, 3) << endl;
    cout << "Suma 2: " << suma(5.2, 1) << endl;
    cout << "Suma 3: " << suma(5.2f, 3.5f) << endl;
    
    return 0;
}

double suma(int a, int b){
    cout << "[INFO] Suma de (int, int)" << endl;
    return (a+b)*2.5;
}

double suma(double a, int b){
    cout << "[INFO] Suma de (double, int)" << endl;
    return a+b;
}

double suma(float a, float b){
    cout << "[INFO] Suma de (float, float)" << endl;
    return a*b+b;
}

