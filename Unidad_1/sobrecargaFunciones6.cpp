#include <iostream>
using namespace std;

double suma(int , int);
double suma(double , int, int);

int main()
{
    cout << "Suma 1: " << suma(10, 2) << endl;
    cout << "Suma 2: " << suma(5.5, 12, 4) << endl;

    return 0;
}

double suma(int a, int b){
    return a+b;
}

double suma(double a, int b, int c){
    return a+b+c;
}


