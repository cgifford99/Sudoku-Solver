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
	//int sizeX;
	//int sizeY;
	//const enum diffInput { easy, medium, hard, };

	Board() {
		resetVector(horizVec, 0);
		resetVector(remainNum, 1);
		/* Temp comment. Difficulty option currently unnecessary.
		cout << "Enter difficulty: Easy, Medium or Hard?";
		cin >> diffIn;
		switch (diffIn) {
		case easy:
		blanks = 36;
		break;
		case medium:
		blanks = 45;
		break;
		case hard:
		blanks = 54;
		*/
		genBoard(sudoBoard, remainNum, horizVec);
		printBoard(sudoBoard);
	}

	void genBoard(int boardArg[9][9], vector<int> &boardOfNine, vector<int> &boardOfOct) {
		for (int x = 0; x < 9; x++) { //Sets values for the board
			for (int y = 0; y < 9; y++) {
				if (x == 0) {
					genHoriz(boardArg, boardOfOct, x);
				}
				if (x != 0) {
					genNumber(boardArg, boardOfNine, x, y);
					resetVector(boardOfNine, 1);
				}
			}
			resetVector(boardOfOct, 0);
			incHoriz = 9;
		}
	}

	void genHoriz(int boardArg[9][9], vector<int> &vectorArg, int x) { //Generates a random horizontal vector of numbers 1-9
		int randHzPos = 0 + (rand() % vectorArg.size()); //******MAGIC******//Finds a random position in the 1-9 list
		horizYPos = vectorArg[randHzPos];
		vectorArg.erase(vectorArg.begin() + randHzPos);
		vectorArg.shrink_to_fit();
		boardArg[x][horizYPos] = incHoriz;
		incHoriz--;
	}

	/*
	void genSquare(int boardArg[9][9], vector<int> &vectorArg, int x, int y) {
		int foundVal;
		int squarePos;
		if (doOnce == 0) {
			for (int i = 0; i <= 2; i++) {
				squarePos = boardArg[0][i];						//Ex. if position 0,0 equals 5, the number five is never used again in the square
				cout << "Squarepos " << squarePos << endl;
				foundVal = findValVec(vectorArg, squarePos, vectorArg.size());
				cout << "Foundval " << foundVal << endl;
				vectorArg.erase(vectorArg.begin() + foundVal); //Make sure the number is never used in the square again
				printVector(vectorArg, vectorArg.size());
			}
			doOnce++;
		}
		vectorArg.shrink_to_fit();
		int randVecPos = 0 + (rand() % vectorArg.size());
		squarePos = vectorArg[randVecPos];
		vectorArg.erase(vectorArg.begin() + randVecPos);
		printVector(vectorArg, vectorArg.size());
		vectorArg.shrink_to_fit();
		boardArg[x][y] = squarePos;
		printBoard(boardArg);
	}
	*/

	void genNumber(int board[9][9], vector<int> &vectorArg, int x, int y) {
		searchSquare(board, vectorArg, x, y);
		printVector(vectorArg, vectorArg.size());
		//searchRow(board, vectorArg, x, y);
		//searchCol(board, vectorArg, x, y);
		//generate number
	}

	void searchSquare(int board[9][9], vector<int> &vectorArg, int x, int y) {
		int squareVal;
		int foundVal;

	}

	int findValVec(vector<int> &vectorArg, int vecValue, size_t vecSize) {
		vecSize -= 1;
		for (int i = 0; i <= vecSize; i++) {
			if (vectorArg[i] == vecValue) {
				cout << i << endl;
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

private:
	vector<int> horizVec;
	vector<int> remainNum;
	int incHoriz = 9;
	int horizYPos;
	int doOnce = 0;

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

