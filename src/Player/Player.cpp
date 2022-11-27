#include "Player.h"
#include <string>


const unsigned int MAX_NAME_LENGTH = 20;

bool ValidateName(const std::string &name) {
    std::string error;

    // Validate name size
    bool is_valid_size = name.length() <= MAX_NAME_LENGTH && name.length() >= 1;

    error += is_valid_size
             ? ""
             : "Name must be between 1 and " +
               std::to_string(MAX_NAME_LENGTH) + " characters\n";

    // isalnum -> chequea si el numero es un alphanumerico (letra o digito)
    // isspace -> chequea si es un espacio en blanco
    bool has_valid_chars = std::ranges::all_of(
            name, [](const auto &als) { return isalnum(als) || isspace(als); });

    error += has_valid_chars
             ? ""
             : "Name must only contain alphanumeric characters and spaces\n";

    return error.empty();
}

// CONSTRUCTORES -------------------
// Constructor por defecto
Player::Player() {
    m_name ="Jugador";
    m_is_winner = false;
    m_color = P_Color::NONE;
}

//Constructor por asignacion
Player::Player(const std::string &name, const P_Color &color) : m_color(color) {
    if (ValidateName(name)) {
        this->m_name = name;
    } else {
        throw std::invalid_argument("Invalid name");
    }
}

// METODOS DE CLASE -------------------
bool Player::changeName(const std::string &newName) {
    if (ValidateName(newName)) {
        this->m_name = newName;
        return true;
    }
    return false;
}

bool operator==(const std::shared_ptr<Player> &pPointer,
                const std::string &pName) {

    return pPointer->getName() == pName;
}

void Player::changeColor(P_Color &newColor) { this->m_color = newColor; }

std::string Player::getName() const { return this->m_name; }

P_Color Player::getColor() const { return this->m_color; }