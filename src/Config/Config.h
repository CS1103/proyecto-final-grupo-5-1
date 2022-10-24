#ifndef CONFIG_H
#define CONFIG_H

enum class TipoJ: unsigned int { HUMANO_HUMANO = 0, HUMANO_COMPUTADOR = 1, COMPUTADOR_COMPUTADOR = 2 };

#include <chrono>

struct Config {

  std::chrono::seconds m_time_limit;
  TipoJ m_tipoJ;

  Config(TipoJ tipoJ = TipoJ::HUMANO_HUMANO, std::chrono::seconds timeLimit = std::chrono::seconds(0));
  void setTimeLimit(std::chrono::seconds timeLimit);
  void setTipoJ(TipoJ tipoJ);

};

#endif // !CONFIG_H
