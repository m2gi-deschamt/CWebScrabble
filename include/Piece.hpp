#pragma once

#include <string>

class Piece {
private:
    std::string name;

public:
    Piece(const std::string& n);
    virtual ~Piece() = default;
    const std::string& getName() const;
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
    char getLetter() const;
};