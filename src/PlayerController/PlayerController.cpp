#include "PlayerController.h"

void PlayerController::addPlayer(shared_ptr<Player> player) {
    for (auto const a : mp_players) {
        mp_players.push_back(player);
    }
}


void PlayerController::removePlayer(shared_ptr<Player> player) {
    iterator ref = std::find(mp_players.begin(), mp_players.end(), *player);

}

void PlayerController:: getPlayerAt(unsigned int index){

}



