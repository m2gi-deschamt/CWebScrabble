#pragma once

#include <memory>
#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>

using std::vector;

#include "Piece.hpp"

struct Position {
    int row;
    int col;
};

class Cell {
private:
    std::shared_ptr<Piece> piece;

    Cell();

    std::shared_ptr<Piece> takePiece() {
        auto tmp = piece;
        piece.reset();
        return tmp;
    }

    bool setPiece(std::shared_ptr<Piece> p) {
        piece = p;
        return true;
    }

    void removePiece() { piece.reset(); }

    bool isEmpty() const { return piece == nullptr; }

    std::shared_ptr<Piece> getPiece() const { return piece; }

    friend class Board;
};

class Board {
private:
    vector<vector<Cell>> cells;
    int rows;
    int columns;

public:
    ~Board();
    Board(int rows, int columns);

    void movePiece(const Position& from, const Position& to); 
    bool havePiece(const Position& position);
    void placePiece(const Position& position, std::shared_ptr<Piece> piece);
    std::shared_ptr<Piece> getPiece(const Position& position);
    
    Cell& getCell(const Position& position);
    Cell& cellAt(int row, int col); 
    const Cell& cellAt(int row, int col) const;
    
    int getRows() const { return rows; } 
    int getCols() const { return columns; }
    void display() const;    
};