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

  * Archivo cadena.h: declaracion de la clase cadena
  *      
  * Referencias:
  *      Enlaces de interes

  * Historial de revisiones:
  *      20/10/2024 - Creacion (primera version) del codigo
  */

#ifndef CADENA_H
#define CADENA_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>

#include "simbolo.h"

class Cadena {
 public:
  //Constructores
  Cadena() = default;
  Cadena(const std::vector<Simbolo>& cadena) : cadena_(cadena) {}   
  Cadena(const std::string& line);

  //Getter
  const std::vector<Simbolo>& getCadena () const {return cadena_;} 

  //Metodos
  const int CadenaSize() const;
  const Cadena Inverso () const;
  void AddBack (const Simbolo& nuevo_simbolo);
  bool Empty() const;

  //Overload of operators
  bool operator<(const Cadena&) const;
  bool operator==(const Cadena&) const;

 private:
  std::vector<Simbolo> cadena_;

};
std::ostream& operator<<(std::ostream& os, const Cadena&);

#endif