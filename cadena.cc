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

  * Archivo cadena.cc: implementacion de la clase cadena
  *      
  * Referencias:
  *      Enlaces de interes

  * Historial de revisiones:
  *      20/10/2024 - Creacion (primera version) del codigo
  */

#include "cadena.h"

/**
 * @brief Metodo para obtener el tamaño de la cadena
 * @return tamaño de la cadena
 */
const int Cadena::CadenaSize() const {
  if (cadena_[0].getSimbolo() == '&') return 0;
  else return cadena_.size();
}

/**
 * @brief Metodo para obtener la cadena inversa
 * @return inveros de la cadena convocada
 */
const Cadena Cadena::Inverso () const {
  std::vector<Simbolo> cadena_inversa = cadena_;
  std::reverse(cadena_inversa.begin(), cadena_inversa.end());
  return cadena_inversa;
}

/**
 * @brief Añade un nuevo simbolo a la cadena
 * @param Simbolo
 * @return La cadena anterior con la nueva adicion
 */
void Cadena::AddBack (const Simbolo& nuevo_simbolo) {
  cadena_.push_back(nuevo_simbolo);
}

/**
 * @brief Metodo para saber si la cadena esta vacia
 * @return bool-type
 */
bool Cadena::Empty() const {
    return cadena_.empty();
}

/**
 * @brief Overload of < operator
 * @param cadena
 * @return bool-type
 */
bool Cadena::operator<(const Cadena& cadena) const {
  return cadena_ < cadena.getCadena(); 
}

/**
 * @brief Overload of == operator
 * @param cadena
 * @return bool-type
 */
bool Cadena::operator==(const Cadena& cadena) const {
  return cadena_ == cadena.getCadena();
}

/**
 * @brief Overload of << operator for Chain class
 * @param std::ostream  
 * @param cadena
 * @return ostream
 */
std::ostream& operator<<(std::ostream& os, const Cadena& cadenas) {
  const std::vector<Simbolo>& simbolos = cadenas.getCadena();
  for (size_t i = 0; i < simbolos.size(); ++i) {
    os << simbolos[i];
  }
  return os;
}

/**
 * @brief Constructor based on a string
 * @param string
 */
Cadena::Cadena(const std::string& line) {
  for (long unsigned int i {0}; i < line.size(); ++i) {
    AddBack(Simbolo(line[i]));
  }
}