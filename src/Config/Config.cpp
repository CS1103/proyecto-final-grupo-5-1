#include "Config.h"

Config::Config(TipoJ tipoJ, seconds timeLimit, unsigned int size)
    : m_time_limit(timeLimit), m_tipo_juego(tipoJ), MC_BOARD_SIZE(size) {}

void Config::setTimeLimit(seconds timeLimit) { this->m_time_limit = timeLimit; }
void Config::setTipoJ(TipoJ tipoJ) { this->m_tipo_juego = tipoJ; }
