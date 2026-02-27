#include "Player.hpp"
#include "Action.hpp"

Player::Player() = default;
Player::~Player() = default;

Player::Player(PlayerId id, string name, int age, Gender gender) {
    this->id = id;
    this->name = name;
    this->age = age;
    this->gender = gender;
}

void Player::display() {
    cout << "Name: " << name << ", Age: " << age << ", Gender: ";
    if (gender == MALE) cout << "Male";
    else cout << "Female";
    cout << endl;
}

PlayerId Player::getId() const{
    return id;
}

std::string Player::getName() const {
    return name;
}

int Player::getAge() const {
    return age;
}

Gender Player::getGender() const {
    return gender;
}


// TODO !!!!!
bool Player::operator<(const Player& other) const {
    return this->name != other.name;
}

PlayerInstance::PlayerInstance() = default;
PlayerInstance::~PlayerInstance() = default;

PlayerInstance::PlayerInstance(Player& p): player(&p){};

// TODO !!!!!
bool PlayerInstance::operator<(const PlayerInstance& other) const {
    return this->player->getName() != other.player->getName();
}

PlayerId PlayerInstance::getId() const{
    return player->getId();
}

std::string PlayerInstance::getName() {
    return player->getName();
}