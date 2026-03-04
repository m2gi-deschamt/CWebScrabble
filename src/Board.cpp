#include "Board.hpp"

#include <iostream>
#include <cassert>
#include <stdexcept>

Cell::Cell() : piece(nullptr) {}

Board::~Board() = default;

Board::Board(int r, int c)
    : rows(r), columns(c), cells(r)
{
    for (auto& row : cells) {
        row.reserve(c);
        for (int i = 0; i < c; ++i) {
            row.emplace_back(Cell());
        }
    }
}

Cell& Board::getCell(const Position& position) {
    return cellAt(position.row, position.col);
}

std::shared_ptr<Piece> Board::getPiece(const Position& position) {
    Cell& cell = getCell(position);

    if (!cell.piece) {
        throw std::runtime_error("No piece on this cell");
    }

    return cell.piece;
}

bool Board::havePiece(const Position& position) {
    return getCell(position).piece != nullptr;
}

void Board::placePiece(const Position& position,
                       std::shared_ptr<Piece> piece)
{
    if (!piece) {
        throw std::invalid_argument("Cannot place a null piece");
    }

    Cell& cell = getCell(position);

    if (!cell.isEmpty()) {
        throw std::runtime_error("Cell already contains a piece");
    }

    cell.piece = piece;
}

void Board::movePiece(const Position& from, const Position& to) {
    Cell& fromCell = getCell(from);
    Cell& toCell   = getCell(to);

    if (fromCell.isEmpty()) {
        throw std::runtime_error("No piece to move");
    }

    if (!toCell.isEmpty()) {
        throw std::runtime_error("Destination cell is not empty");
    }

    toCell.piece = fromCell.piece;
    fromCell.piece = nullptr;
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

void Board::display() const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (cells[i][j].isEmpty()) {
                std::cout << ". ";
            } else {
                std::cout << cells[i][j].piece->getName() << " ";
            }
        }
        std::cout << "\n";
    }
}