#include "Piece.hpp"
#include <iostream>

Piece::Piece(const std::string& n) : name(n) {}
const std::string& Piece::getName() const {
    return name;
};

Pawn::Pawn(): Piece("Pawn") {};

Letter::Letter() : Piece("Letter"), letter(' ') {};
Letter::Letter(char ch) : Piece("Letter"), letter(ch) {};
char Letter::getLetter() const { 
    return letter; 
};