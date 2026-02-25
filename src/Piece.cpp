#include "Piece.hpp"

Piece::Piece() : name(" "){};
Piece::Piece(const std::string& n) : name(n) {}
std::string Piece::getName() {
    return name;
};

Pawn::Pawn(): Piece("Pawn") {};

Letter::Letter() : Piece("Letter"), letter(' ') {};
Letter::Letter(char ch) : Piece("Letter"), letter(ch) {};
char Letter::getLetter() { 
    return letter; 
};