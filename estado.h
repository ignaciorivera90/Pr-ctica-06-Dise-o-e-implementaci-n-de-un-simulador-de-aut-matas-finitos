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

  * Archivo estado.h: Declaracion de la clase estado
  *      
  * Referencias:
  *      Enlaces de interes

  * Historial de revisiones:
  *      20/10/2024 - Creacion (primera version) del codigo
  *      21/10/2024 - Creacion (segunda version) del codigo
  */

#ifndef ESTADO_H
#define ESTADO_H

#include <iostream>
#include <map>

#include "simbolo.h"
#include "alfabeto.h"

class Estado {
 public:
  // Constructores
  Estado() = default;
  Estado(unsigned int id, bool aceptacion, unsigned int num_transiciones) : id_(id), aceptacion_(aceptacion),
         num_transiciones_(num_transiciones_), transiciones_() {}
  
  // Getters
  const unsigned int& getId() const { return id_; }
  const bool getAceptacion() const { return aceptacion_; }
  const unsigned int getNumTransiciones() const { return num_transiciones_; }
  const std::multimap<Simbolo, unsigned int>& getTransiciones() const { return transiciones_; }

  //Metodos de adicion
  void AddTransicion(Simbolo, unsigned int);
  void IngrearTransicion(Simbolo, unsigned int);

 private:
  unsigned int id_;
  bool aceptacion_;
  unsigned int num_transiciones_{0};
  std::multimap<Simbolo, unsigned int> transiciones_;

};

std::ostream& operator<<(std::ostream& os, const Estado&);

#endif