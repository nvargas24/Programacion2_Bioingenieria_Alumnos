#include <iostream>

using namespace std;

int main()
{
    int v=20;
    int* p = &v;

    *p = 25;
    cout<< "Valor de 'v': " <<v << endl;

    return 0;
}