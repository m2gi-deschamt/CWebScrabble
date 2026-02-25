#include "Board.hpp"
#include <cassert>

Cell::Cell() : piece(nullptr) {}

Board::Board(int r, int c) : rows(r), columns(c), cells(r) {
    for (auto& row : cells) {
        row.reserve(c);               
        for (int i = 0; i < c; ++i) {
            row.emplace_back(Cell()); 
        }
    }
}

Cell& Board::getCell(const Position& position) {
    return cells[position.row][position.col];
}


Piece* Board::getPiece(const Position& position) {
    Cell& cell = getCell(position);
    if(havePiece(position)) return cell.getPiece();
    assert("No piece on this case");
}

bool Board::havePiece(const Position& position) {
    return !getCell(position).isEmpty();
}

void Board::placePiece(const Position& position, std::unique_ptr<Piece> piece) {
    assert(piece && "Cannot place a null piece");
    Cell& cell = getCell(position);
    assert(cell.isEmpty() && "Cell already contains a piece");
    cell.setPiece(std::move(piece));
}

void Board::movePiece(const Position& from, const Position& to) {
    if(havePiece(to)) getCell(to).setPiece(cells[from.row][from.col].takePiece());
}

Cell& Board::cellAt(int row, int col) {
    if (row < 0 || row >= rows || col < 0 || col >= columns) {
        throw std::out_of_range("Board::cellAt: indices out of range");
    }
    return cells[row][col];
}

const Cell& Board::cellAt(int row, int col) const {
    if (row < 0 || row >= rows || col < 0 || col >= columns) {
        throw std::out_of_range("Board::cellAt: indices out of range");
    }
    return cells[row][col];
}

// Affichage du plateau
void Board::display() const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (cells[i][j].isEmpty()) {
                std::cout << ". ";
            } else {
                std::cout << "P "; // On affiche "P" si la cellule contient une pièce
            }
        }
        std::cout << "\n";
    }
}

