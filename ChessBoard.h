// C++
// #pragma once
#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include <memory>
#include "ChessPiece.h"
#include "Utils.h"
class ChessBoard {
public:
	static const int WIDTH = 767; // ���̿��
	static const int HEIGHT = 842; // ���̸߶�
	static constexpr double len = 67.5; // ���Ӽ��
    ChessBoard();
    ~ChessBoard();
    void draw(IMAGE* buffer);
	bool IsGameOver() const;
    void move();
private:
    ChessPiece* board[10][9];
    // ������Ա
    bool st = true;
};

#endif // !CHESSBOARD_H