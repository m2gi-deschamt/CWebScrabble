#pragma once

#include <string>

class Piece {
private:
    std::string name;

public:
    Piece();
    Piece(const std::string& n);
    std::string getName();
};

class Pawn : public Piece {
public:
    Pawn();
};

class Letter : public Piece {
private:
    char letter;
public:
    Letter();
    Letter(char ch);
    char getLetter();
};