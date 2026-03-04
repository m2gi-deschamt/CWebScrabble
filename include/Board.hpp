#pragma once

#include <memory>
#include <optional>
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
    std::optional<Piece> piece;

    Cell();

    std::optional<Piece> takePiece() {
        return piece;
    }

    bool setPiece(std::optional<Piece> p) { piece = p; return true;}

    void removePiece() { piece.reset(); }

    bool isEmpty() const { return !piece.has_value(); }

    Piece getPiece() const { return piece.value(); }

    friend class Board;
};

class Board {
private:
    vector<vector<Cell>> cells;
    int rows;
    int columns;

    public :
        ~Board();
        Board(int rows, int columns);
        void movePiece(const Position& from, const Position& to); 
        bool havePiece(const Position& position);
        void placePiece(const Position& position, std::optional<Piece> piece);
        Piece getPiece(const Position& position);
        
        Cell& getCell(const Position& position);
        Cell& cellAt(int row, int col); 
        const Cell& cellAt(int row, int col) const;
        
        int getRows() const { return rows; } 
        int getCols() const { return columns; }
        void display() const;    
};