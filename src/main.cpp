#include <iostream>
using namespace std;

#include "System.h"
#include "Config/Config.h"

int main (int argc, char *argv[])
{

  config_base = new Config();
  //config_adicional = new Config(bot=true, tiempo=120);

  sistema = new System();
  sistema->crear_juego(config_base);
  
  system("pause");
  return 0;
}
