#pragma once

#include "Piece.hpp"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Action;

enum Gender {
    MALE,
    FEMALE
};

struct PlayerId {
    int value;
    bool operator==(const PlayerId& other) const noexcept {
        return value == other.value;
    }
};
namespace std {
template<>
struct hash<PlayerId> {
    size_t operator()(const PlayerId& id) const noexcept {
        return std::hash<int>()(id.value);
    }
};
}


class Player {
    private:
        PlayerId id;
        string name;
        int age;
        Gender gender;

    public:

        Player();
        ~Player();

        Player(PlayerId id, string name, int age, Gender gender);
        void display();
        int getAge() const;
        string getName() const;
        Gender getGender() const;
        PlayerId getId() const;
        bool operator<(const Player& other) const;
};

class PlayerInstance {
    private:
        Player* player;

    public:
        PlayerInstance();
        ~PlayerInstance();
        PlayerInstance(Player& p);
        std::string getName();
        PlayerId getId() const;
        bool operator<(const PlayerInstance& other) const;
};

/*
bool operator<(const Player& other) const {
        return name < other.name;
    }
*/