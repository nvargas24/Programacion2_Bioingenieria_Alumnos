#include <iostream>

using namespace std;

int main(){

    int* ptr = new int;

    *ptr = 10;

    cout << "Valor: " << *ptr << endl;
    cout << "Direccion en memoria: " << ptr << endl;

    delete ptr;
    //ptr = nullptr;

    cout << "Valor: " << *ptr << endl;
    cout << "Direccion en memoria: " << ptr << endl;

    return 0;
}

