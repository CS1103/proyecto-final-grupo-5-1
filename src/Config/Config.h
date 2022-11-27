#ifndef CONFIG_H
#define CONFIG_H

#include "../utils.h"
#include <chrono>
#include <optional>

using UTILS::seconds;
using UTILS::TipoJ;

// Default Config Data
const TipoJ JUEGO_DEFAULT = TipoJ::HUMANO_HUMANO;
const unsigned int TAMANHO_DEFAULT = 11;
[[maybe_unused]] const seconds MIN_DURATION = seconds(30);

struct Config {

  // Atributos
  std::optional<seconds> time_limit;
  TipoJ tipo_juego;
  const unsigned int BOARD_SIZE;

  // Constructor
  Config(TipoJ tipoJ = JUEGO_DEFAULT, unsigned int size = TAMANHO_DEFAULT,
         std::optional<seconds> timeLimit = std::nullopt);

  // Metodos
  void setTimeLimit(std::chrono::seconds timeLimit);
  void setTipoJ(TipoJ tipoJ);
};

#endif // !CONFIG_H
