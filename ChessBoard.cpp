#include "ChessBoard.h"
#include <graphics.h>
#include <conio.h>
#include <stdio.h>


ChessBoard::ChessBoard() {
    // 构造函数实现
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 9; ++j) {
			board[i][j] = nullptr; // 初始化棋盘为空
		}
	}
	// 初始化棋子
	//黑
    board[0][0] = new che("che", ChessPiece::BLACKPiece);
    board[0][1] = new ma("ma", ChessPiece::BLACKPiece);
    board[0][2] = new xiang("xiang", ChessPiece::BLACKPiece);
    board[0][3] = new shi("shi", ChessPiece::BLACKPiece);
    board[0][4] = new jiang("jiang", ChessPiece::BLACKPiece);
    board[0][5] = new shi("shi", ChessPiece::BLACKPiece);
    board[0][6] = new xiang("xiang", ChessPiece::BLACKPiece);
    board[0][7] = new ma("ma", ChessPiece::BLACKPiece);
    board[0][8] = new che("che", ChessPiece::BLACKPiece);
    board[2][1] = new pao("pao", ChessPiece::BLACKPiece);
    board[2][7] = new pao("pao", ChessPiece::BLACKPiece);
    board[3][0] = new soldier("zu", ChessPiece::BLACKPiece);
    board[3][2] = new soldier("zu", ChessPiece::BLACKPiece);
    board[3][4] = new soldier("zu", ChessPiece::BLACKPiece);
    board[3][6] = new soldier("zu", ChessPiece::BLACKPiece);
    board[3][8] = new soldier("zu", ChessPiece::BLACKPiece);
    //红
    board[9][0] = new che("che", ChessPiece::REDPiece);
    board[9][1] = new ma("ma", ChessPiece::REDPiece);
    board[9][2] = new xiang("xiang", ChessPiece::REDPiece);
    board[9][3] = new shi("shi", ChessPiece::REDPiece);
    board[9][4] = new xiang("shuai", ChessPiece::REDPiece);
    board[9][5] = new shi("shi", ChessPiece::REDPiece);
    board[9][6] = new xiang("shuai", ChessPiece::REDPiece);
    board[9][7] = new ma("ma", ChessPiece::REDPiece);
    board[9][8] = new che("che", ChessPiece::REDPiece);
    board[7][1] = new pao("pao", ChessPiece::REDPiece);
    board[7][7] = new pao("pao", ChessPiece::REDPiece);
    board[6][0] = new soldier("bin", ChessPiece::REDPiece);
    board[6][2] = new soldier("bin", ChessPiece::REDPiece);
    board[6][4] = new soldier("bin", ChessPiece::REDPiece);
    board[6][6] = new soldier("bin", ChessPiece::REDPiece);
    board[6][8] = new soldier("bin", ChessPiece::REDPiece);
	// 其他初始化操作
	bool st = true; // 当前执棋方
}

ChessBoard::~ChessBoard() {
    // 析构函数实现
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 9; ++j) {
			delete board[i][j]; // 删除棋子对象
			board[i][j] = nullptr; // 清空指针
		}
	}
}

void ChessBoard::draw(IMAGE* buffer) {
    int a[10][9] = { -1,-2,-3,-4,-5,-4,-3,-2,-1,
                     0,0,0,0,0,0,0,0,0,
                     0,-6,0,0,0,0,0,-6,0,
                     -7,0,-7,0,-7,0,-7,0,-7,
                     0,0,0,0,0,0,0,0,0,
                     0,0,0,0,0,0,0,0,0,
                     7,0,7,0,7,0,7,0,7,
                     0,6,0,0,0,0,0,6,0,
                     0,0,0,0,0,0,0,0,0,
                     1,2,3,4,5,4,3,2,1 };
    initgraph(767, 842);
    // 绘制棋盘实现
    IMAGE imgbj;
    loadimage(&imgbj, _T("./picture/information_board_321_321.png"), 767, 842);
    IMAGE imgqp;
    loadimage(&imgqp, _T("./picture/棋盘（黑上）.png"), 767, 842);
    putimage(0, 0, &imgbj);
    transparentimage3(buffer, 0, 0, &imgqp);
    // 棋子
    IMAGE ju;
    loadimage(&ju, _T("./picture/黑车.png"), 66, 66);
    IMAGE ma;
    loadimage(&ma, _T("./picture/黑马.png"), 66, 66);
    IMAGE xiang;
    loadimage(&xiang, _T("./picture/黑象.png"), 66, 66);
    IMAGE shi;
    loadimage(&shi, _T("./picture/黑士.png"), 66, 66);
    IMAGE jiang;
    loadimage(&jiang, _T("./picture/黑将.png"), 66, 66);
    IMAGE pao;
    loadimage(&pao, _T("./picture/黑炮.png"), 66, 66);
    IMAGE zu;
    loadimage(&zu, _T("./picture/黑卒.png"), 66, 66);
    IMAGE JU;
    loadimage(&JU, _T("./picture/红车.png"), 66, 66);
    IMAGE MA;
    loadimage(&MA, _T("./picture/红马.png"), 66, 66);
    IMAGE XIANG;
    loadimage(&XIANG, _T("./picture/红相.png"), 66, 66);
    IMAGE SHI;
    loadimage(&SHI, _T("./picture/红仕.png"), 66, 66);
    IMAGE SHUAI;
    loadimage(&SHUAI, _T("./picture/红帅.png"), 66, 66);
    IMAGE PAO;
    loadimage(&PAO, _T("./picture/红炮.png"), 66, 66);
    IMAGE BING;
    loadimage(&BING, _T("./picture/红兵.png"), 66, 66);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            if (a[i][j] == -1) transparentimage3(buffer, 77 + len * j, 62 + len * i, &ju);
            if (a[i][j] == -2) transparentimage3(buffer, 77 + len * j, 62 + len * i, &ma);
            if (a[i][j] == -3) transparentimage3(buffer, 77 + len * j, 62 + len * i, &xiang);
            if (a[i][j] == -4) transparentimage3(buffer, 77 + len * j, 62 + len * i, &shi);
            if (a[i][j] == -5) transparentimage3(buffer, 77 + len * j, 62 + len * i, &jiang);
            if (a[i][j] == -6) transparentimage3(buffer, 77 + len * j, 62 + len * i, &pao);
            if (a[i][j] == -7) transparentimage3(buffer, 77 + len * j, 62 + len * i, &zu);
            if (a[i][j] == 1) transparentimage3(buffer, 77 + len * j, 62 + len * i, &JU);
            if (a[i][j] == 2) transparentimage3(buffer, 77 + len * j, 62 + len * i, &MA);
            if (a[i][j] == 3) transparentimage3(buffer, 77 + len * j, 62 + len * i, &XIANG);
            if (a[i][j] == 4) transparentimage3(buffer, 77 + len * j, 62 + len * i, &SHI);
            if (a[i][j] == 5) transparentimage3(buffer, 77 + len * j, 62 + len * i, &SHUAI);
            if (a[i][j] == 6) transparentimage3(buffer, 77 + len * j, 62 + len * i, &PAO);
            if (a[i][j] == 7) transparentimage3(buffer, 77 + len * j, 62 + len * i, &BING);
        }
    }
}

bool ChessBoard::IsGameOver() const {
	// 检查游戏是否结束
	bool red = false, black = false;
	for (int i = 0; i <= 2; i++) {
		for (int j = 3; j <= 5; j++) {
			if (board[i][j] != nullptr&& board[i][j]->getName() == "jiang") black = true;
		}
	}
	for (int i = 8; i <= 10; i++) {
		for (int j = 3; j <= 5; j++) {
			if (board[i][j] != nullptr && board[i][j]->getName() == "shuai") red = true;
		}
	}
	return !(red && black);
}

void ChessBoard::move() {
    IMAGE buffer(767, 842);
    setbkmode(TRANSPARENT);
    setbkcolor(WHITE);
    settextcolor(BLACK);
    setlinecolor(BLACK);
    setfillcolor(WHITE);
    setlinestyle(PS_SOLID, 1);
    settextstyle(20, 0, _T("宋体"));
    SetWorkingImage(&buffer);
    draw(&buffer);
    SetWorkingImage(NULL);
    putimage(0, 0, &buffer);

    int selectedX = -1, selectedY = -1;
    bool isRedTurn = true; // 当前执棋方

    while (true) {
        if (MouseHit()) {
            MOUSEMSG msg = GetMouseMsg();
            if (msg.uMsg == WM_LBUTTONDOWN) {
                int x = static_cast<int>((msg.x - 77) / len);
                int y = static_cast<int>((msg.y - 62) / len);

                // 选中棋子
                if (selectedX == -1 && selectedY == -1) {
                    if (x >= 0 && x < 9 && y >= 0 && y < 10 && board[y][x] != nullptr) {
                        // 只允许选中当前方的棋子
                        if ((isRedTurn && board[y][x]->getColor() == ChessPiece::REDPiece) ||
                            (!isRedTurn && board[y][x]->getColor() == ChessPiece::BLACKPiece)) {
                            selectedX = x;
                            selectedY = y;
                            SetWorkingImage(&buffer);
                            draw(&buffer);
                            drawSelection(&buffer, 77 + len * x, 62 + len * y);
                            SetWorkingImage(NULL);
                            putimage(0, 0, &buffer);
                        }
                    }
                }
                // 点击空白区域或已选中棋子取消选中
                else if (x < 0 || x >= 9 || y < 0 || y >= 10 || (x == selectedX && y == selectedY)) {
                    selectedX = -1;
                    selectedY = -1;
                    SetWorkingImage(&buffer);
                    draw(&buffer);
                    SetWorkingImage(NULL);
                    putimage(0, 0, &buffer);
                }
                // 尝试走棋
                else if (x >= 0 && x < 9 && y >= 0 && y < 10 && board[selectedY][selectedX] != nullptr) {
                    ChessPiece* piece = board[selectedY][selectedX];
                    if (piece->isValidMove(selectedX, selectedY, x, y, board)) {
                        // 吃子
                        if (board[y][x] != nullptr) {
                            delete board[y][x];
                        }
                        board[y][x] = piece;
                        board[selectedY][selectedX] = nullptr;
                        selectedX = -1;
                        selectedY = -1;
                        SetWorkingImage(&buffer);
                        draw(&buffer);
                        SetWorkingImage(NULL);
                        putimage(0, 0, &buffer);
                        isRedTurn = !isRedTurn;
                       /* if (IsGameOver()) {
                            MessageBox(GetHWnd(), isRedTurn ? _T("黑方胜利！") : _T("红方胜利！"), _T("游戏结束"), MB_OK);
                            break;
                        }*/
                    }
                }
            }
        }
        if (_kbhit()) {
            break;
        }
    }
    closegraph();
}