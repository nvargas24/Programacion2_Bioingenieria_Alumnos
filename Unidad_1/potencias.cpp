/*
Desarrolle un programa que permita calcular potencias 
simples de un número entero utilizando las funciones:
  - Square(int n): que reciba un número entero y devuelva su cuadrado.
  - Cube(int n): que reciba un número entero y devuelva su cubo.
*/
#include <iostream>
#include <string>

//using namespace std;
int Square(int );
int Cube(int );

int main()
{
  std::cout << "El cuadrado de 27 es " << Square(27) << std::endl;
  std::cout << "y el cubo de 27 es " << Cube(27) << std::endl;
  return 0;
}

int Square( int n ){
  return n * n;
}

int Cube( int n ){
  return n * n * n;
}
