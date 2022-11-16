#include "Config.h"

Config::Config(TipoJ tipoJ, unsigned int size, std::optional<seconds> timeLimit)
    : time_limit(timeLimit), tipo_juego(tipoJ), BOARD_SIZE(size) {}
Config::Config()
    : time_limit(std::nullopt), tipo_juego(TipoJ::HUMANO_HUMANO),
      BOARD_SIZE(TAMANHO_DEFAULT) {}

void Config::setTimeLimit(seconds timeLimit) { this->time_limit = timeLimit; }
void Config::setTipoJ(TipoJ tipoJ) { this->tipo_juego = tipoJ; }
/*
 *
const TipoJ JUEGO_DEFAULT = TipoJ::HUMANO_HUMANO;
const unsigned int TAMANHO_DEFAULT = 9;

const seconds MIN_DURACION = seconds(30);

struct Config {
  // Atributos
  seconds m_time_limit;
  TipoJ m_tipo_juego;
  const unsigned int MC_BOARD_SIZE;

  // Constructor
  Config(TipoJ tipoJ = JUEGO_DEFAULT, seconds timeLimit = seconds(0),
         unsigned int size = TAMANHO_DEFAULT);
  // Metodos
  void setTimeLimit(std::chrono::seconds timeLimit);
  void setTipoJ(TipoJ tipoJ);
 * */
