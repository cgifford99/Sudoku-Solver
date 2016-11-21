#pragma once
// SudokuAlg.h : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;
#define SHOW(a) cout << #a << ": " << (a) << endl

class Board {
public:

	void solve() {
		resetVector(horizVec, 0);
		resetVector(remainNum, 1);
		genBoard(sudoBoard, remainNum, horizVec);
		printBoard(sudoBoard);
	}

	void genBoard(int boardArg[9][9], vector<int> &boardOfNine, vector<int> &boardOfOct) {
		//while (boolZeroTest == false) {
		for (int y = savedY; y <= 8; y++) { //Sets values for the board
			for (int x = 0; x <= 8; x++) {
				if (boolZeroTest == false) {
					if (y == 0) {
						genHoriz(boardArg, boardOfOct, y);
					}
					else if (y != 0) {
						generatedNum = genNumber(boardArg, boardOfNine, y, x);
						if (generatedNum != -1) {
							boardArg[y][x] = generatedNum;
							resetVector(boardOfNine, 1);
						}
						else {
							resetVector(boardOfNine, 1);
							savedY = y;
							if (boolZeroTest == false) {
								genBoard(boardArg, boardOfNine, boardOfOct);
							}
						}
					}
				}
			}
			//printBoard(boardArg);
			resetVector(boardOfOct, 0);
			incHoriz = 9;

			boolZeroTest = anyZeros(boardArg);
			if (boolZeroTest == false) {
				continue;
			}
			else if (boolZeroTest == true) {
				return;
			}
			resetVector(boardOfOct, 0);
			incHoriz = 9;
		}
		//}
	}

	void genHoriz(int boardArg[9][9], vector<int> &vectorHoriz, int y) { //Generates a random horizontal vector of numbers 1-9
		int randHzPos = 0 + (rand() % vectorHoriz.size()); //******MAGIC******//Finds a random position in the 1-9 list
		horizYPos = vectorHoriz[randHzPos];
		vectorHoriz.erase(vectorHoriz.begin() + randHzPos);
		vectorHoriz.shrink_to_fit();
		boardArg[y][horizYPos] = incHoriz;
		incHoriz--;
	}

	bool anyZeros(int zeroBoard[9][9]) {
		bool zeroBool = true;
		for (int y = 0; y < 9; y++) {
			for (int x = 0; x < 9; x++) {
				if (zeroBoard[y][x] == 0) {
					zeroBool = false;
				}
			}
		}
		return zeroBool;
	}

	int genNumber(int board[9][9], vector<int> &vectorGenNum, int y, int x) {
		find_CoordSquare(board, vectorGenNum, y, x);
		search_Row(board, vectorGenNum, y, x);
		search_Col(board, vectorGenNum, y, x);
		if (vectorGenNum.size() <= 0) {
			if (boolZeroTest == false) {
				for (int r = 0; r < 9; r++) {
					board[y][r] = 0;
				}
				resetVector(vectorGenNum, 1);
				genNumber(board, vectorGenNum, y, x);
				return -1;
			}
		}
		else {
			int randPos = 0 + (rand() % vectorGenNum.size());
			validNum = vectorGenNum[randPos];
			vectorGenNum.erase(vectorGenNum.begin() + randPos);
			vectorGenNum.shrink_to_fit();
			return validNum;
		}
	}

	void find_CoordSquare(int board[9][9], vector<int> &vectorCoord, int y, int x) {
		if (y <= 2 && y >= 0) {
			if (x <= 2 && x >= 0) {
				search_Square(board, vectorCoord, 0, 2, 0, 2);
			}
			else if (x <= 5 && x >= 3) {
				search_Square(board, vectorCoord, 0, 2, 3, 5);
			}
			else if (x <= 8 && x >= 6) {
				search_Square(board, vectorCoord, 0, 2, 6, 8);
			}
		}
		else if (y <= 5 && y >= 3) {
			if (x <= 2 && x >= 0) {
				search_Square(board, vectorCoord, 3, 5, 0, 2);
			}
			else if (x <= 5 && x >= 3) {
				search_Square(board, vectorCoord, 3, 5, 3, 5);
			}
			else if (x <= 8 && x >= 6) {
				search_Square(board, vectorCoord, 3, 5, 6, 8);
			}
		}
		else if (y <= 8 && y >= 6) {
			if (x <= 2 && x >= 0) {
				search_Square(board, vectorCoord, 6, 8, 0, 2);
			}
			else if (x <= 5 && x >= 3) {
				search_Square(board, vectorCoord, 6, 8, 3, 5);
			}
			else if (x <= 8 && x >= 6) {
				search_Square(board, vectorCoord, 6, 8, 6, 8);
			}
		}
	}


	void search_Row(int board[9][9], vector<int> &vectorRow, int y, int x) {
		int rowVal;
		int foundRowVal;
		for (int r = 0; r < 9; r++) {
			int rowVal;
			rowVal = board[y][r];
			if (rowVal != 0) {
				foundRowVal = find_VecRowCol(vectorRow, rowVal, vectorRow.size());
				if (foundRowVal == vectorRow.size()) {
					continue;
				}
				else if (foundRowVal == -1) {
					return;
				}
				else {
					vectorRow.erase(vectorRow.begin() + foundRowVal);
					vectorRow.shrink_to_fit();
				}
			}
			else {
				continue;
			}
		}
	}

	void search_Col(int board[9][9], vector<int> &vectorCol, int y, int x) {
		int foundColVal;
		for (int r = 0; r < 8; r++) {
			int colVal;
			colVal = board[r][x];
			if (colVal != 0) {
				foundColVal = find_VecRowCol(vectorCol, colVal, vectorCol.size());
				if (foundColVal == vectorCol.size()) {
					continue;
				}
				else if (foundColVal == -1) {
					return;
				}
				else {
					vectorCol.erase(vectorCol.begin() + foundColVal);
					vectorCol.shrink_to_fit();
				}
			}
			else {
				continue;
			}
		}
	}

	void search_Square(int board[9][9], vector<int> &vectorSearch, int y1, int y2, int x1, int x2) {
		int squareVal;
		int foundVal;
		for (int a = y1; a <= y2; a++) {
			for (int b = x1; b <= x2; b++) {
				squareVal = board[a][b];
				if (squareVal != 0) {
					foundVal = find_VecSquare(vectorSearch, squareVal, vectorSearch.size());
					if (foundVal == -1) {
						return;
					}
					else {
						vectorSearch.erase(vectorSearch.begin() + foundVal);
						//printVector(vectorSearch, vectorSearch.size());
						vectorSearch.shrink_to_fit();
					}
				}
				else {
					return;
				}
			}
		}
	}

	int find_VecRowCol(vector<int> &vectorROWCOL, int vecValue, size_t vecSize) {
		vecSize--;
		for (int i = 0; i <= vecSize; i++) {
			if (vectorROWCOL.size() == 0) {
				return -1;
			}
			if (vectorROWCOL[i] == vecValue) {
				return i;
			}
			else if (vectorROWCOL[i] != vecValue) {
				continue;
			}
			if (vectorROWCOL[i] == vecSize) { //Case for which the number is not found in the vector
				return vecSize;
			}
		}
	}

	int find_VecSquare(vector<int> &vectorArg, int vecValue, size_t vecSize) {
		vecSize -= 1;
		for (int i = 0; i <= vecSize; i++) {
			if (vectorArg[i] == vecValue) {
				return i;
			}
			if (vectorArg.size() == 0) {
				return -1;
			}
		}
	}

	void printBoard(int boardArg[9][9]) {
		cout << " ----------------------- " << endl;
		for (int b = 0; b < 9; b++) {
			if (b == 3 || b == 6 || b == 9) {
				cout << "| ------+-------+--------" << endl;
			}
			cout << "| ";
			for (int c = 0; c < 9; c++) {
				cout << boardArg[b][c] << " ";
				if (c == 2 || c == 5 || c == 8) {
					cout << "| ";
				}
			}
			cout << endl;
		}
		cout << " ----------------------- " << endl;
	}

	void resetVector(vector<int> &vec, int chooseArr) {
		int boardArgOfOct[9] = { 0,1,2,3,4,5,6,7,8 };
		int boardArgOfNine[9] = { 1,2,3,4,5,6,7,8,9 };
		if (chooseArr == 0) {
			vec.assign(boardArgOfOct, boardArgOfOct + 9);
		}
		else if (chooseArr == 1) {
			vec.assign(boardArgOfNine, boardArgOfNine + 9);
		}
		//printVector(vec, vec.size());
	}

	void printVector(vector<int> &vec, size_t vecRange) {
		for (int y = 0; y < vecRange; y++) {
			cout << vec[y];
		}
		cout << endl;
	}

private:
	vector<int> horizVec;
	vector<int> remainNum;
	int incHoriz = 9;
	int horizYPos;
	int generatedNum;
	int validNum;
	int savedX = 0;
	int savedY = 0;
	bool boolZeroTest;

public:
	int sudoBoard[9][9];
};

int main(){
	Board tired;
	tired.solve();
	return 0;
}
