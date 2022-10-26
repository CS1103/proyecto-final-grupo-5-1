#include "Config.h"

Config::Config(TipoJ tipoJ, std::chrono::seconds timeLimit):
  m_time_limit(timeLimit),
  m_tipoJ(tipoJ) {}

void Config::setTimeLimit(std::chrono::seconds timeLimit){
  this->m_time_limit = timeLimit;
}
void Config::setTipoJ(TipoJ tipoJ){
  this->m_tipoJ = tipoJ;
}
void setBoardSize(const unsigned int s){
    this->mc_board_size = s;
}