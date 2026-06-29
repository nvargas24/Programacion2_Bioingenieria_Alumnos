#include <iostream>
using namespace std;

double suma(int , int);
double suma(double , int);

int main()
{
    cout << "Suma 1: " << suma(2, 3) << endl;
    cout << "Suma 2: " << suma(5.2, 1) << endl;
    
    return 0;
}

double suma(int a, int b){
    return (a+b)*2.5;
}

double suma(double a, int b){
    return a+b;
}

