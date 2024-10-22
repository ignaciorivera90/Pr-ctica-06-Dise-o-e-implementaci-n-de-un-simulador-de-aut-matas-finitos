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

  std::string aux_line;

  // Leer el alfabeto
  std::getline(archivo_fa, aux_line);
  for (char aux_sim : aux_line) {
    if(aux_sim != ' ' && aux_sim != '&') {
      alfabeto_.AddSimbolo(Simbolo(aux_sim));
    }
  }

  //Leer el numero de estados
  unsigned int num_estados{0};
  std::getline(archivo_fa, aux_line);
  if (!aux_line.empty()) {
    for (char chr : aux_line) {
      if (!std::isdigit(chr)) {
        std::cerr << "El numero de estados tiene que ser un numero" << std::endl;
        exit(1);
      }
    }
    num_estados = std::stoi(aux_line);
    if(num_estados <= 0) {
      std::cerr << "Error: el numero de estados no puede ser 0 o negativo" << std::endl;
      exit(1);
    }
  } else {
    std::cerr << "Error: El numero de estados mal introducidos" << std::endl;
    exit(1);
  }

  //Leer el numero del estado de arranque
  unsigned int inicio{0};
  std::getline(archivo_fa, aux_line);
  if (!aux_line.empty()) {
    for (char chr : aux_line) {
      if (!std::isdigit(chr)) {
        std::cerr << "El estado de arranque tiene que ser un numero" << std::endl;
        exit(1);
      }
    }
    inicio = std::stoi(aux_line);
    if(num_estados < 0) {
      std::cerr << "Error: el estado de arranque no puede ser negativo" << std::endl;
      exit(1);
    }
    if(inicio >= num_estados) {
      std::cerr << "Error: El estado de arranque tiene que estar entre 0 y " << num_estados << std::endl;
      exit(1);
    }
  } else {
    std::cerr << "Error: El estado de arranque esta mal introducido" << std::endl;
    exit(1);
  }

  //Leer cada estado
  unsigned int id{0};
  bool aceptado;
  unsigned int num_transiciones{0};
  bool encontrado_estado_inicial = false;
  for(unsigned i{0}; i < num_estados; ++i) {
    if(std::getline(archivo_fa, aux_line)) {
      std::istringstream linea_estado(aux_line);
      linea_estado >> id;
      if (id >= num_estados) {
        std::cerr << "Error: Un estado no se encuentra en el rango de los estado, 0 - " << num_estados - 1 << std::endl;
        exit(1);
      }
      linea_estado >> aceptado;
      linea_estado >> num_transiciones;

      Estado estado_aux(id, aceptado, num_transiciones);

      //Procesando las transiciones
      for(unsigned j{0}; j < estado_aux.getNumTransiciones(); ++j) {
        char simbolo_aux;
        unsigned int destino_trans;
        if(linea_estado >> simbolo_aux >> destino_trans) {
          Simbolo simbolo_aux_trans{simbolo_aux};
          
          //Ver si el simbolo de transicion pertene al alfabeto
          if(!alfabeto_.Find(simbolo_aux_trans) && simbolo_aux_trans.getSimbolo() != '&') {
              std::cerr << "Error: un simbolo de una de las transiciones no pertenece al alfabeto" << std::endl;
              std::cerr << "El simbolo que no pertenece es " << simbolo_aux_trans << std::endl;
              exit(1);
          }

          //Ver si el estado al que transita esta en el automata
          if(destino_trans >= num_estados) {
            std::cerr << "Error: al estado que transiciona no pertenece al automata" << std::endl;
            std::cerr << "El estado que intenta saltar es " << destino_trans << std::endl;
            exit(1);
          }

          estado_aux.IngrearTransicion(simbolo_aux_trans, destino_trans);
        } else {
          std::cerr << "Error: incorrecta forma de colocar las transiciones" << std::endl;
          exit(1);
        }
      }

      if(inicio == id) {
        inicio_ = estado_aux;
        encontrado_estado_inicial = true;
      }

      AddEstado(estado_aux);

    }
  }

  if(encontrado_estado_inicial == 0) {
    std::cerr << "Error: no exite el estado de arranque" << std::endl;
    exit(1);
  }

  archivo_fa.close();
}



/**
 * @brief Comprueba del archvio recivido que cadenas son aseptadas y cuales no
 * @param file_txt: donde se encuentra las cadenas a simular
 */
void Automata::SimulacionFile(const std::string &file_txt) {
  std::ifstream archivo_txt(file_txt);
  if (!archivo_txt.is_open()) {
    std::cerr << "Error: No se pudo abrir el archivo " << file_txt << std::endl;
    std::cerr << "El ingresado puedo no exitir intentalo otra vez o usa \"./p06_automata_simulator --help\" para mas informacion " << std::endl;
    exit(1);
  }

  std::string line_aux;
  while(std::getline(archivo_txt, line_aux)) {
    Cadena cadena_evaluar{line_aux};
    bool cadena_correcta{true};
    std::set<unsigned int> estados_actuales;
    estados_actuales.insert(getInicio().getId());

    if(!cadena_evaluar.Empty()) {
      bool aceptado{false};
      for(unsigned i{0}; i < cadena_evaluar.CadenaSize(); ++i) {
        //Ver si el simbolo corresponde al alfabeto
        for(const Simbolo& sim : getAlfabeto().getSimbolos()) {
          if(cadena_evaluar[i] == sim.getSimbolo() || cadena_evaluar[i] == '&') {
            aceptado = true;
            break;
          } else {
            break;
          }
        }
        if (aceptado == false) {
          cadena_correcta = false;
          break;
        }
      }

      for (const Simbolo& sim : cadena_evaluar.getCadena()) {
        std::set<unsigned int> estados_siguientes;
        for(unsigned int aux : estados_actuales ) {
          auto rango_coincidencia = getEstados().equal_range(aux);
          for (auto it = rango_coincidencia.first; it != rango_coincidencia.second; ++it) {
            
          }
        }
      }
    }

  }

  archivo_txt.close();
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
  estados_.insert({estado.getId(), estado});
}
