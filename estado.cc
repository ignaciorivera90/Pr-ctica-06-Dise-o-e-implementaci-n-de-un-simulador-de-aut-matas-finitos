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

  * Archivo estado.h: Implmentacion de la clase estado
  *      
  * Referencias:
  *      Enlaces de interes

  * Historial de revisiones:
  *      20/10/2024 - Creacion (primera version) del codigo
  *      21/10/2024 - Creacion (segunda version) del codigo
  */

#include "estado.h"



/**
 * @brief Añade una transicion al estado y suma al numero de transiciones
 * @param simbolo: es el simbolo que produce la transicion
 * @param id_estado_transicion: es el id del el estado de destino
 */
void Estado::AddTransicion(Simbolo simbolo, unsigned int id_estado_transicion) {
  ++num_transiciones_;
  transiciones_.insert({simbolo, id_estado_transicion});
}



/**
 * @brief Overload of operator << for State class
 * @param ostream
 * @param Estado
 * @return ostream
 */
std::ostream& operator<<(std::ostream& os, const Estado& estado) {
  os << "Estado " << estado.getId() << ":" << std::endl;
  os << "Aceptacion " << estado.getAceptacion() << std::endl;
  os << "Numero de estados: " << estado.getNumTransiciones() << std::endl;
  os << "Transiciones: " << std::endl;
  for (const auto& par : estado.getTransiciones()) {
    os << estado.getId() << "(Simbolo: " << par.first << ")" << " -> " << par.second << std::endl;
  }
  return os;
}
