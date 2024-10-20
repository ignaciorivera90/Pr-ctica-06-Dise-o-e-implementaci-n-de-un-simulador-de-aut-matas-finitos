/**
  * Universidad de La Laguna
  * Escuela Superior de Ingenieria y Tecnologia
  * Grado en Ingenieria Informatica
  * Asignatura: Computabilidad y Algoritmia
  * Curso: 2º
  * Practica 6: Diseño e implementación de un simulador de autómatas finitos
  * Autor: Ignacio Andres Rivera Barrientos
  * Correo: alu0101675053@ull.edu.es
  * Fecha: 20/10/2024

  * Archivo funciones.cc: Implmentacion de la clase funciones
  *      
  * Referencias:
  *      Enlaces de interes

  * Historial de revisiones:
  *      20/10/2024 - Creacion (primera version) del codigo
  */

#include "funciones.h"

/**
  * @brief Imprime que hace el programa 
  */
void PrintProgramPurpose(){
  std::cout << "Este programa lee un fichero las especificaciones de un autómata finito (FA) y, a continuación," << std::endl;
  std::cout << " simule el comportamiento del autómata para una serie de cadenas que se suministren como entrada." << std::endl;
}



/**
  * @brief Comprueba la extension del fichero de texto en el que figura la especificación de un autómata finito
  */
void CheckExtensionFA(const std::string& FA) {
  std::regex pattern(R"((.*)\.(fa)$)");  
  bool aux{std::regex_match(FA, pattern)};
  if (aux == 0) {
    std::cerr << "Fallo en la extension del automata " << std::endl;
    std::cerr << "'./p06_automata_simulator --help' para mas información." << std::endl; 
    exit(1);
  }
}



/**
  * @brief Comprueba la extension del fichero de texto en el que figura una serie de cadenas
  */
void CheckExtensionTXT(const std::string& TXT) {
  std::regex pattern(R"((.*)\.(txt)$)");  
  bool aux{std::regex_match(TXT, pattern)};
  if (aux == 0) {
    std::cerr << "Fallo en la extension del las cadenas " << std::endl;
    std::cerr << "'./p06_automata_simulator --help' para mas información." << std::endl; 
    exit(1);
  }
}



/**
  * @brief Comprueba si se le paso el numeero correcto de parametros y sus extensiones llamando a dos funciones mas
  *        si falla envia un mensaje de error, con --help como parametro llama a la funcion que explica como funciona el
  *        programa y como se usa
  */
void Usage(int argc, char* argv[]) {
  std::string ayuda{argv[1]};
  if (ayuda == "--help") {
    PrintProgramPurpose();
    std::cout << "Uso: " << argv[0] << " <input.fa> <input.txt>" << std::endl;
    exit(1);
  }
  if (argc != 3) {
    std::cout << "Esta introduciendo mal los paranetros" << std::endl;
    std::cout << "Uso: " << argv[0] << " <input.fa> <input.txt>" << std::endl;
    std::cout << "Las extenciones de los archivos son importantes" << std::endl;
    std::cout << "'./p06_automata_simulator --help' para mas información." << std::endl; 
    exit(1);
  }
  CheckExtensionFA(std::string(argv[1]));
  CheckExtensionTXT(std::string(argv[2]));
}