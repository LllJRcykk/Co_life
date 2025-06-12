// C++
#pragma once
#ifndef CHESSGAME_H
#define CHESSGAME_H
#include "ChessBoard.h"

class ChessGame {
public:
    void run();
private:
    ChessBoard board;
    // 其他成员
};
#endif // !CHESSGAME_H
