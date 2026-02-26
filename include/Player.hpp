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

class Player {
    private:
        string name;
        int age;
        Gender gender;

    public:

        Player();
        ~Player();

        Player(string name, int age, Gender gender);
        void display();
        int getAge() const;
        string getName() const;
        Gender getGender() const;
        bool operator<(const Player& other) const;
};

class PlayerInstance {
    private:
        Player* player;
        std::vector<Letter> rack;
        int score = 0;

    public:
        PlayerInstance();
        ~PlayerInstance();
        PlayerInstance(Player& p);
        std::string getName();
        bool operator<(const PlayerInstance& other) const;
};

/*
bool operator<(const Player& other) const {
        return name < other.name;
    }
*/