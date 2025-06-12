#include "ChessGame.h"
#include "ChessBoard.h"

void ChessGame::run() 
{
    initgraph(767, 842);
    IMAGE buffer(767, 842);
    while (true) {
        board.draw(&buffer);
        putimage(0, 0, &buffer);

        if (board.IsGameOver()) {
            outtextxy(300, 400, "Game Over!");
            Sleep(2000);
            break;
        }

        board.move(); // 建议在ChessBoard中实现move()，处理用户输入和走棋
    }
    closegraph();
}