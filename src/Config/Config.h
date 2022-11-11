#ifndef CONFIG_H
#define CONFIG_H

enum class TipoJ : unsigned int {
  HUMANO_HUMANO = 0,
  HUMANO_COMPUTADOR = 1,
  COMPUTADOR_COMPUTADOR = 2
};

#include "../utils.h"
#include <chrono>

// Default Config Data
const TipoJ JUEGO_DEFAULT = TipoJ::HUMANO_HUMANO;
const unsigned int TAMANHO_DEFAULT = 11;

const seconds MIN_DURACION = seconds(30);

struct Config {
  // Atributos
  seconds time_limit;
  TipoJ tipo_juego;
  const unsigned int BOARD_SIZE;

  // Constructor
  Config(TipoJ tipoJ = JUEGO_DEFAULT, seconds timeLimit = seconds(0),
         unsigned int size = TAMANHO_DEFAULT);
  // Metodos
  void setTimeLimit(std::chrono::seconds timeLimit);
  void setTipoJ(TipoJ tipoJ);
};

#endif // !CONFIG_H
