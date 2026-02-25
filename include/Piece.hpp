#ifndef PIECE_HPP
#define PIECE_HPP

#include <string>

class Piece {
private:
    std::string name;

public:
    Piece() : name(" "){};
    Piece(const std::string& n) : name(n) {}
    std::string getName() const { return name; }
};

class Pawn : public Piece {
public:
    Pawn() : Piece("Pawn") {}
};

class Letter : public Piece {
private:
    char letter;
public:
    Letter() : Piece("Letter"), letter(' ') {}
    Letter(char ch) : Piece("Letter"), letter(ch) {}
    char getLetter() const { return letter; }
};


#endif