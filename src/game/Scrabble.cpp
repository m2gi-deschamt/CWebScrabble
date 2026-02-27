#include "Action.hpp"
#include "game/Scrabble.hpp"

#include <ostream>
#include <iostream>
#include <cstdlib> // pour exit

using namespace std;

// Constructeur : initialise letters
Scrabble::Scrabble() {
    letters = initLetters();
}

Scrabble::~Scrabble() = default;

// Validation temporaire
bool Scrabble::isMoveValid(const Action& action, const Board& board) const {
    return true;
}

// Check de victoire temporaire
bool Scrabble::checkVictory(const Board& board) const {
    return false;
}

// Retourne un vector safe
std::vector<Letter> Scrabble::getLettersVectors() {
    std::vector<Letter> lettersVector(letters.begin(), letters.end());
    return lettersVector;
}

// Initialisation safe des lettres
std::array<Letter, 102> Scrabble::initLetters() {
    std::string allLetters =
        "AAAAAAAAA"      // 9 A
        "BB"             // 2 B
        "CC"             // 2 C
        "DDD"            // 3 D
        "EEEEEEEEEEEEEEE"// 15 E
        "FF"             // 2 F
        "GG"             // 2 G
        "HH"             // 2 H
        "IIIIIIII"       // 8 I
        "J"              // 1 J
        "K"              // 1 K
        "LLLLL"          // 5 L
        "MMM"            // 3 M
        "NNNNNN"         // 6 N
        "OOOOOO"         // 6 O
        "PP"             // 2 P
        "Q"              // 1 Q
        "RRRRRR"         // 6 R
        "SSSSSS"         // 6 S
        "TTTTTT"         // 6 T
        "UUUUUU"         // 6 U
        "VV"             // 2 V
        "W"              // 1 W
        "X"              // 1 X
        "Y"              // 1 Y
        "Z"              // 1 Z
        "__";            // 2 jokers

    if (allLetters.size() != 102) {
        cerr << "Error: allLetters.size() = " << allLetters.size() << ", expected 102!" << endl;
        exit(1);
    }

    std::array<Letter, 102> temp;
    for (size_t i = 0; i < temp.size(); i++) {
        temp[i] = Letter(allLetters[i]);
    }

    return temp;
}