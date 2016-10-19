// Sudoku Solver.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#define SHOW(a) std::cout << #a << ": " << (a) << std::endl
//#include <algorithm>s
using namespace std;

class Board {
public:

	Board() {
		resetVector(horizVec, 0);
		resetVector(remainNum, 1);
		genBoard(sudoBoard, remainNum, horizVec);
		printBoard(sudoBoard);
	}

	void genBoard(int boardArg[9][9], vector<int> &boardOfNine, vector<int> &boardOfOct) {
		for (int y = 0; y < 9; y++) { //Sets values for the board
			for (int x = 0; x < 9; x++) {
				if (y == 0) {
					genHoriz(boardArg, boardOfOct, y);
				}
				if (y != 0) {
					generatedNum = genNumber(boardArg, boardOfNine, y, x);
					boardArg[y][x] = generatedNum;
					printBoard(boardArg);					
					resetVector(boardOfNine, 1);
				} 
			}
			//printBoard(boardArg);
			resetVector(boardOfOct, 0);
			incHoriz = 9;
		}
	}

	void genHoriz(int boardArg[9][9], vector<int> &vectorHoriz, int y) { //Generates a random horizontal vector of numbers 1-9
		int randHzPos = 0 + (rand() % vectorHoriz.size()); //******MAGIC******//Finds a random position in the 1-9 list
		horizYPos = vectorHoriz[randHzPos];
		vectorHoriz.erase(vectorHoriz.begin() + randHzPos);
		vectorHoriz.shrink_to_fit();
		boardArg[y][horizYPos] = incHoriz;
		incHoriz--;
	}

	int genNumber(int board[9][9], vector<int> &vectorNum, int y, int x) {
		coordSquare(board, vectorNum, y, x);
		coordRow(board, vectorNum, y, x);
		coordCol(board, vectorNum, y, x);
		if (vectorNum.size() <= 1) {
			//add another conditional here
			for (int r = 0; r < 9; r++) {
				board[y][r] = 0;
			}
			resetVector(vectorNum, 1);
			genNumber(board, vectorNum, y, x);
		}else{
			int randPos = 0 + (rand() % vectorNum.size());
			validNum = vectorNum[randPos];
			vectorNum.erase(vectorNum.begin() + randPos);
			vectorNum.shrink_to_fit();
			printVector(vectorNum, vectorNum.size());
			return validNum;
		}
	}

	void coordSquare(int board[9][9], vector<int> &vectorCoord, int y, int x) {
		if (y <= 2 && y >= 0) {
				if (x <= 2 && x >= 0) {
					searchSquare(board, vectorCoord, 0, 2, 0, 2);
				}
				else if (x <= 5 && x >= 3) {
					searchSquare(board, vectorCoord, 0, 2, 3, 5);
				}
				else if (x <= 8 && x >= 6) {
					searchSquare(board, vectorCoord, 0, 2, 6, 8);
				}
		}
		else if (y <= 5 && y >= 3) {
				if (x <= 2 && x >= 0) {
					searchSquare(board, vectorCoord, 3, 5, 0, 2);
				}
				else if (x <= 5 && x >= 3) {
					searchSquare(board, vectorCoord, 3, 5, 3, 5);
				}
				else if (x <= 8 && x >= 6) {
					searchSquare(board, vectorCoord, 3, 5, 6, 8);
				}
		}
		else if (y <= 8 && y >= 6) {
				if (x <= 2 && x >= 0) {
					searchSquare(board, vectorCoord, 6, 8, 0, 2);
				}
				else if (x <= 5 && x >= 3) {
					searchSquare(board, vectorCoord, 6, 8, 3, 5);
				}
				else if (x <= 8 && x >= 6) {
					searchSquare(board, vectorCoord, 6, 8, 6, 8);
				}
		}
	}

	void coordRow(int board[9][9], vector<int> &vectorRow, int y, int x) { //can't finish the for loop if its returning nothing so soon 
		int rowVal;
		int foundRowVal;
		for (int r = 0; r < 9; r++) {
			rowVal = board[y][r];
			if (rowVal != 0) {
				foundRowVal = findValVec(vectorRow, rowVal, vectorRow.size());
				if (foundRowVal == vectorRow.size()) {
					continue;
				}
				else if(foundRowVal != vectorRow.size()){
					vectorRow.erase(vectorRow.begin() + foundRowVal);
					vectorRow.shrink_to_fit();
				}
			}
			else{
				continue;
			}
		}
	}

	void coordCol(int board[9][9], vector<int> &vectorCol, int y, int x) {
		int colVal;
		int foundColVal;
		for (int r = 0; r < 8; r++) {
			colVal = board[r][x];
			if (colVal != 0) {
				foundColVal = findValVec(vectorCol , colVal, vectorCol.size());
				if(foundColVal == vectorCol.size()){
					continue;
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

	void searchSquare(int board[9][9], vector<int> &vectorSearch, int y1, int y2, int x1, int x2) {
		int squareVal;
		int foundVal;
		for (int a = y1; a <= y2; a++) {
			for (int b = x1; b <= x2; b++) {
				squareVal = board[a][b];
				if (squareVal != 0) {
					foundVal = findSQUAREVec(vectorSearch, squareVal, vectorSearch.size());
					vectorSearch.erase(vectorSearch.begin() + foundVal);
					//printVector(vectorSearch, vectorSearch.size());
					vectorSearch.shrink_to_fit();
				}
				else {
					return;
				}
			}
		}
	}

	int findValVec(vector<int> &vectorROWCOL, int vecValue, size_t vecSize) {
		vecSize--;
		for (int i = 0; i <= vecSize; i++) {
			if (vectorROWCOL[i] == vecValue) {
				return i;
			}
			else if(vectorROWCOL[i] != vecValue){
				continue;
			}
			else if (vectorROWCOL[i] == vecSize) {
				return vecSize;
			}
		}
	}

	int findSQUAREVec(vector<int> &vectorArg, int vecValue, size_t vecSize) {
		vecSize -= 1;
		for (int i = 0; i <= vecSize; i++) {
			if (vectorArg[i] == vecValue) {
				return i;
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
	
	void good(){
		cout << "-----------------------------------------Got here!----------------------------------------" << endl;
	}

private:
	vector<int> horizVec;
	vector<int> remainNum;
	int incHoriz = 9;
	int horizYPos;
	int doOnce = 0;
	int generatedNum;
	int validNum;

protected:
	int sudoBoard[9][9];
	//int diffIn;
};

/*
class Sudoku : public Board {
public:
};
*/

int main() {
	Board nBoard;
	return 0;
}

