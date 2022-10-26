#ifndef CONFIG_H
#define CONFIG_H

enum class TipoJ: unsigned int { HUMANO_HUMANO = 0, HUMANO_COMPUTADOR = 1, COMPUTADOR_COMPUTADOR = 2 };

#include <chrono>

struct Config {
    // Atributos
  std::chrono::seconds m_time_limit;
  TipoJ m_tipoJ;
  const unsigned int mc_board_size;

  // Constructor
  Config(TipoJ tipoJ = TipoJ::HUMANO_HUMANO, std::chrono::seconds timeLimit = std::chrono::seconds(0), const unsigned int s)
  // Metodos
  void setTimeLimit(std::chrono::seconds timeLimit);
  void setTipoJ(TipoJ tipoJ);
  void setBoardSize(const unsigned int s);

};

#endif // !CONFIG_H
