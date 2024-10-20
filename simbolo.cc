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

  * Archivo simbolo.cc: implementacion de la clase simbolo
  *      
  * Referencias:
  *      Enlaces de interes

  * Historial de revisiones:
  *      20/10/2024 - Creacion (primera version) del codigo
  */


#include "simbolo.h"

/**
 * @brief Overload of < operator for Symbol class
 * @param Simbolo 
 * @return boolean-type
 */
bool Simbolo::operator<(const Simbolo& caracter) const {
  return caracter_ < caracter.getSimbolo();
}

/**
 * @brief Overload of == operator for Symbol class
 * @param Simbolo 
 * @return boolean-type
 */
bool Simbolo::operator==(const Simbolo& caracter) const {
  return caracter_ == caracter.getSimbolo();
}

/**
 * @brief Overload of << operator for Symbol class
 * @param std::ostream  
 * @param Simbolo
 * @return ostream
 */
std::ostream& operator<<(std::ostream& os, const Simbolo& simbolo) {
  return os << simbolo.getSimbolo();
}