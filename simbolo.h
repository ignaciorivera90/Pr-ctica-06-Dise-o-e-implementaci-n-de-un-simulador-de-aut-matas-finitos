

#ifndef SIMBOLO_H
#define SIMBOLO_H

#include <fstream>
#include <iostream>

class Simbolo {
 public:
  Simbolo (char caracter) : caracter_(caracter) {}; //Constructor for class symbol
  char getSimbolo () const {return caracter_;} //Getter

  //Operators
  bool operator< (const Simbolo&) const;
  bool operator== (const Simbolo&) const;

 private:
  char caracter_;

};
std::ostream& operator<<(std::ostream& os, const Simbolo&); //Overload of out stream operator for symbol class

#endif