#ifndef PIECE_HPP
#define PIECE_HPP

#include "string"

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
    private :
        std::string name = "Letter"; 
        char letter;
    public :
        Letter() : letter(' ') {}
        Letter(char ch) : letter(ch) {} 
        char getLetter(){return letter;};
};


#endif