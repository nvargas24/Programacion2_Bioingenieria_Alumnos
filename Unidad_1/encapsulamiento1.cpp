/* 
Defina una clase llamada Persona para almacenar información básica de una persona. 
La clase debe contener como atributos privados el nombre, la edad y el país de origen.
Implemente métodos públicos para cargar (setters) y obtener (getters) los valores 
de cada atributo. 
*/
#include <iostream> 
#include <string> 

class Persona { // Define la clase Personaa
  private: 
    std::string nombre; // Miembro privado para nombre 
    int edad; // Miembro privado para edad 
    std::string pais; // Miembro privado para pais

  public:
    // Setter de nombre
    void setnombre(const std::string & n) { 
      nombre = n; 
    }
	// Setter de edad
    void setedad(int a) {
      edad = a; 
    }
	//Setter de pais
    void setpais(const std::string & c) {
      pais = c; 
    }

    // Getter de nombre
    std::string getnombre() { 
      return nombre; 
    }
	// Getter de edad
    int getedad() {
      return edad; 
    }
	// Getter de pais
    std::string getpais() { 
      return pais; 
    }
};

int main() {
  // Crear el objeto persona
  Persona persona;

  // Cargar los datos de la persona
  persona.setnombre("Juan Perez"); 
  persona.setedad(25); 
  persona.setpais("Argentina"); 

  // Mostrar los nombres en la salida
  std::cout << "nombre: " << persona.getnombre() << std::endl;
  std::cout << "edad: " << persona.getedad() << std::endl;
  std::cout << "pais: " << persona.getpais() << std::endl;

  return 0;
}
