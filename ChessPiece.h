// C++
#pragma once
#ifndef CHESSPIECE_H
#define CHESSPIECE_H
#include <graphics.h>
#include <string>

class ChessPiece {
public:
    enum Color { REDPiece, BLACKPiece };
	std::string name;
	ChessPiece(const std::string& name, Color color) : name(name), color(color) {}
    virtual ~ChessPiece() {}
    Color getColor() const { return color; }
	std::string getName() const { return name; }
    virtual bool isValidMove(int sx, int sy, int ex, int ey, ChessPiece* board[10][9]) = 0;
protected:
    Color color;
};

class che : public ChessPiece {
public:
    che(const std::string& name, Color color) : ChessPiece(name, color) {}
    bool isValidMove(int sx, int sy, int ex, int ey, ChessPiece* board[10][9]) override {
        // 检查目标位置是否在棋盘范围内
        if (ex < 0 || ex >= 9 || ey < 0 || ey >= 10) {
            return false;
        }

        // 检查是否移动到同一位置
        if (sx == ex && sy == ey) {
            return false;
        }

        // 检测是否为友军
		if (board[ey][ex] && board[ey][ex]->getColor() == this->getColor()) return false;


        if (sx == ex) {
            int step = (ey > sy) ? 1 : -1;
            for (int y = sy + step; y != ey; y += step) {
                if (board[y][sx] != nullptr) return false;
            }
            
            return true;
        }
        if (sy == ey) {
            int step = (ex > sx) ? 1 : -1;
            for (int x = sx + step; x != ex; x += step) {
                if (board[sy][x] != nullptr) return false;
            }
            return true;
        }
        return false;
    }
};

class ma : public ChessPiece {
public:
	ma(const std::string& name, Color color) : ChessPiece(name, color) {}
    bool isValidMove(int sx, int sy, int ex, int ey, ChessPiece* board[10][9]) override {
        // 检查目标位置是否在棋盘范围内
        if (ex < 0 || ex >= 9 || ey < 0 || ey >= 10) {
            return false;
        }

        // 检查是否移动到同一位置
        if (sx == ex && sy == ey) {
            return false;
        }

        // 检测是否为友军
        if (board[ey][ex]->getColor() == this->getColor())return false;

        if ((abs(sx - ex) == 2 && abs(sy - ey) == 1) || (abs(sx - ex) == 1 && abs(sy - ey) == 2)) {
            int midX = (sx + ex) / 2;
            int midY = (sy + ey) / 2;
            if (abs(sx - ex) == 2 && sy >= 0 && sy < 10 && midX >= 0 && midX < 9 && board[sy][midX] == nullptr )
                return true;
            if (abs(sy - ey) == 2 && midY >= 0 && midY < 10 && sx >= 0 && sx < 9 && board[midY][sx] == nullptr )
                return true;
        }
        return false;
    }
};

class xiang : public ChessPiece {
public:
	xiang(const std::string& name, Color color) : ChessPiece(name, color) {}
    bool isValidMove(int sx, int sy, int ex, int ey, ChessPiece* board[10][9]) override {
        // 检查目标位置是否在棋盘范围内
        if (ex < 0 || ex >= 9 || ey < 0 || ey >= 10) {
            return false;
        }

        // 检查是否移动到同一位置
        if (sx == ex && sy == ey) {
            return false;
        }

        // 检测是否为友军
		if (board[ey][ex] && board[ey][ex]->getColor() == this->getColor()) return false;

        if (abs(sx - ex) == 2 && abs(sy - ey) == 2) {
            int midX = (sx + ex) / 2;
            int midY = (sy + ey) / 2;
            if (board[midY][midX] == nullptr) {
                if (this->getColor() == REDPiece && ey >= 5) return true; // 红象
                if (this->getColor() == BLACKPiece < 0 && ey <= 4) return true; // 黑象
            }
        }
        return false;
    }
};

class shi : public ChessPiece {
public:
	shi(const std::string& name, Color color) : ChessPiece(name, color) {}
	bool isValidMove(int sx, int sy, int ex, int ey, ChessPiece* board[10][9]) override {
		// 检查目标位置是否在棋盘范围内
		if (ex < 3 || ex > 5 || ey < 0 || ey >= 10) {
			return false;
		}
		// 检查是否移动到同一位置
		if (sx == ex && sy == ey) {
			return false;
		}
		// 检测是否为友军
		if (board[ey][ex] && board[ey][ex]->getColor() == this->getColor()) return false;

		if (abs(sx - ex) == 1 && abs(sy - ey) == 1) {
			if ((this->getColor() == REDPiece && ey >= 7 && ey <= 9) || (this->getColor() == BLACKPiece && ey >= 0 && ey <= 2)) return true;
		}
		return false;
	}
};

class jiang : public ChessPiece {
public:
	jiang(const std::string& name, Color color) : ChessPiece(name, color) {}
	bool isValidMove(int sx, int sy, int ex, int ey, ChessPiece* board[10][9]) override {
		// 检查目标位置是否在棋盘范围内
		if (ex < 3 || ex > 5 || ey < 0 || ey >= 10) {
			return false;
		}
		// 检查是否移动到同一位置
		if (sx == ex && sy == ey) {
			return false;
		}
		// 检测是否为友军
		if (board[ey][ex] && board[ey][ex]->getColor() == this->getColor()) return false;


		if ((abs(sx - ex) + abs(sy - ey) == 1) && ((this->getColor() == REDPiece && ey >= 7 && ey <= 9) || (this->getColor() == BLACKPiece && ey >= 0 && ey <= 2))) return true;
		return false;
	}
};

class pao : public ChessPiece {
public:
	pao(const std::string& name, Color color) : ChessPiece(name, color) {}
	bool isValidMove(int sx, int sy, int ex, int ey, ChessPiece* board[10][9]) override {
		// 检查目标位置是否在棋盘范围内
		if (ex < 0 || ex >= 9 || ey < 0 || ey >= 10) {
			return false;
		}
		// 检查是否移动到同一位置
		if (sx == ex && sy == ey) {
			return false;
		}
		// 检测是否为友军
		if (board[ey][ex] && board[ey][ex]->getColor() == this->getColor()) return false;


		if (sx == ex) {
			int step = (ey > sy) ? 1 : -1;
			int count = 0;
			for (int y = sy + step; y != ey; y += step) {
				if (board[y][sx] != nullptr) count++;
			}
			return (count == 0 || (count == 1 && board[ey][ex] != nullptr));
		}
		if (sy == ey) {
			int step = (ex > sx) ? 1 : -1;
			int count = 0;
			for (int x = sx + step; x != ex; x += step) {
				if (board[sy][x] != nullptr) count++;
			}
			return (count == 0 || (count == 1 && board[ey][ex] != nullptr));
		}
		return false;
	}
};

class soldier : public ChessPiece {
public:
	soldier(const std::string& name, Color color) : ChessPiece(name, color) {}
	bool isValidMove(int sx, int sy, int ex, int ey, ChessPiece* board[10][9]) override {
		// 检查目标位置是否在棋盘范围内
		if (ex < 0 || ex >= 9 || ey < 0 || ey >= 10) {
			return false;
		}
		// 检查是否移动到同一位置
		if (sx == ex && sy == ey) {
			return false;
		}
		// 检测是否为友军
		if (board[ey][ex] && board[ey][ex]->getColor() == this->getColor()) return false;

		if (this->getColor() == REDPiece) { // 红兵
			if (sy >= 5) return (sx == ex && ey == sy - 1);
			return (sx == ex && ey == sy - 1) || (sy == ey && abs(sx - ex) == 1);
		}
		else { // 黑卒
			if (sy <= 4) return (sx == ex && ey == sy + 1);
			return (sx == ex && ey == sy + 1) || (sy == ey && abs(sx - ex) == 1);
		}
	}
};
#endif // !CHESSPIECE_H