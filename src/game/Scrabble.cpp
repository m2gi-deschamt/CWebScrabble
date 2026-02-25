#include "Action.hpp"
#include "game/Scrabble.hpp"

Scrabble::Scrabble() = default;

Scrabble::~Scrabble() = default;

bool Scrabble::isMoveValid(const Action& action, const Board& board) const {
    return true;
}

bool Scrabble::checkVictory(const Board& board) const {
    return false;
}

std::array<Letter, 102> Scrabble::initLetters() {
            std::string allLetters = 
            "AAAAAAAAA"  // 9 A
            "BBBB"       // 2 B
            "CCCC"       // 2 C
            "DDDDD"      // 3 D
            "EEEEEEEEEEEEEEE" // 15 E
            "FFFF"       // 2 F
            "GGGG"       // 3 G
            "HH"         // 2 H
            "IIIIIIIII"  // 9 I
            "JJ"         // 1 J
            "KK"         // 1 K
            "LLLLLL"     // 6 L
            "MMMM"       // 4 M
            "NNNNNN"     // 6 N
            "OOOOOOO"    // 8 O
            "PPPP"       // 4 P
            "QQ"         // 1 Q
            "RRRRRR"     // 6 R
            "SSSSSS"     // 6 S
            "TTTTTTT"    // 6 T
            "UUUUU"      // 6 U
            "VV"         // 2 V
            "WW"         // 1 W
            "X"          // 1 X
            "Y"          // 1 Y
            "Z"          // 1 Z
            "__";        // 2 jokers (représentés par '_')

        std::array<Letter, 102> temp;
        for (int i = 0; i < temp.size(); i++) {
            temp[i] = Letter(allLetters[i]);
        }
        return temp;
    }