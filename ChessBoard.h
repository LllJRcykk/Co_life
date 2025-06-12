// C++
// #pragma once
#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include <memory>
#include "ChessPiece.h"
#include "Utils.h"
class ChessBoard {
public:
	static const int WIDTH = 767; // 棋盘宽度
	static const int HEIGHT = 842; // 棋盘高度
	static constexpr double len = 67.5; // 棋子间距
    ChessBoard();
    ~ChessBoard();
    void draw(IMAGE* buffer);
	bool IsGameOver() const;
    void move();
private:
    ChessPiece* board[10][9];
    // 其他成员
    bool st = true;
};

#endif // !CHESSBOARD_H