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

  * Archivo alfabeto.cc: Implementacion de la clase alfabeto
  *      
  * Referencias:
  *      Enlaces de interes

  * Historial de revisiones:
  *      20/10/2024 - Creacion (primera version) del codigo
  */

#include "alfabeto.h"


/**
 * @brief Comprueba si un alfabeto está vacío
 * @param simbolo 
 * @return bool-type. Verdadero si el alfabeto está vacío. Falso en caso contrario.
 */
bool Alfabeto::Empty() const {
  return simbolos_.empty();
}

/**
 * @brief Metodo para añadir un simbolo
 * @param symbol 
 */
void Alfabeto::AddSimbolo (const Simbolo& simbolo) {
  simbolos_.insert(simbolo);
}

/**
 * @brief Buscar un simbolo en el alfabeto
 * @param simbolo
 * @return bool-type. Verdadero si se encuentra, falso en caso contrario
 */
bool Alfabeto::Find(const Simbolo& simbolo) {
  if (std::find(getSimbolos().begin(), getSimbolos().end(), simbolo) == getSimbolos().end()) {
    return false;
  } else {
    return true;
  }
}

/**
 * @brief Overload of << operator for Alphabet class
 * @param std::ostream  
 * @param symbol
 * @return ostream
 */
std::ostream& operator<<(std::ostream& os, const Alfabeto& simbolos)  {
  int contador {0};
  int albeto_size = simbolos.getSimbolos().size();
  os << "{";
  for (const Simbolo& simbol : simbolos.getSimbolos()) {
    os << simbol;
    if (contador < albeto_size - 1) {
      os << ", ";
    }
    ++contador;
  }
  os << "}";
  return os;
}