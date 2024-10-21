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

  * Archivo automata.cc: Implementacion de la clase automata
  *      
  * Referencias:
  *      Enlaces de interes

  * Historial de revisiones:
  *      20/10/2024 - Creacion (primera version) del codigo
  *      21/10/2024 - Creacion (segunda version) del codigo
  */

#include "automata.h"


/**
 * @brief Es el contructor del automata
 * @param file_fa: es el archivo donde figura la especificación de un autómata finito
 */
Automata::Automata(const std::string &file_fa) {
  std::ifstream archivo_fa(file_fa);
  if (!archivo_fa.is_open()) {
    std::cerr << "Error: No se pudo abrir el archivo " << file_fa << std::endl;
    std::cerr << "El ingresado puedo no exitir intentalo otra vez o usa \"./p06_automata_simulator --help\" para mas informacion " << std::endl;
    exit(1);
  }
  
  }



/**
 * @brief Comprueba del archvio recivido que cadenas son aseptadas y cuales no
 * @param file_txt: donde se encuentra las cadenas a simular
 */
void Automata::SimulacionFile(const std::string &file_txt) {
}



/**
 * @brief Comprueba la cadena pasada si pertenece al automata
 * @param cadena: un string de simbolos
 */
void Automata::SimulacionCadena(const std::string &cadena) {
}



/**
 * @brief Añade un estado nuevo al automata
 * @param estado: es el nuevo estado a añadir
 */
void Automata::AddEstado(const Estado& estado) {
}
