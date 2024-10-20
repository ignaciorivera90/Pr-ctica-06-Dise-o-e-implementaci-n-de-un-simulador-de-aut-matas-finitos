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

  * Archivo alfabeto.h: Declaracion de la clase alfabeto
  *      
  * Referencias:
  *      Enlaces de interes

  * Historial de revisiones:
  *      20/10/2024 - Creacion (primera version) del codigo
  */

#ifndef ALFABETO_H
#define ALFABETO_H

#include <set>
#include <iostream>
#include <algorithm>

#include "simbolo.h"
#include "cadena.h"

class Alfabeto {
 public:
  Alfabeto() = default;
  Alfabeto (const std::set<Simbolo>& simbolos) : simbolos_(simbolos) {}  //Constructor
  const std::set<Simbolo>& getSimbolos () const {return simbolos_;} //Getter

  bool Empty() const;
  void AddSimbolo (const Simbolo&); //Function to add symbols to the alphabet
  bool Find (const Simbolo&);

 private:
  std::set<Simbolo> simbolos_; 

};
std::ostream& operator<<(std::ostream& os, const Alfabeto&); //Overload of out stream operator for alphabet class

#endif