// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Board {
public:
	int sizeX;
	int sizeY;
	int sBoard[9][9];
	const enum diffInput { easy, medium, hard, };
	
	Board(){
		/*
		cout << "Enter difficulty: Easy, Medium or Hard?";
		cin >> din;
		switch (din) {
		case easy:
			blanks = 36;
			break;
		case medium:
			blanks = 45;
			break;
		case hard:
			blanks = 54;
		*/
	}
	
	void genBoard() {
		for (int x = 0; x < 9; x++) {
			for (int y = 0; y < 9; y++) {
				sBoard[x][y] = (1 + (rand() % 9));
				var = find(sBoard.first, sBoard.last, 1);
			}
		}
	}

protected:
	int din;
	int blanks;
	int var;
};

class Sudoku : public Board {
public:

	void printBoard(int arr[9][9]) {
		cout << " ----------------------- " << endl;
		for (int b = 0; b < 9; b++) {
			if (b == 3 || b == 6 || b == 9) {
				cout << "| ------+-------+--------" << endl;
			}
			cout << "| ";
			for (int c = 0; c < 9; c++) {
				cout << arr[b][c] << " ";
				if (c == 2 || c == 5 || c == 8) {
					cout << "| ";
				}
			}
			cout << endl;
		}
		cout << " ----------------------- " << endl;
	}
};

int main() {
	Sudoku gameObj; 
	gameObj.genBoard();
	gameObj.printBoard(gameObj.sBoard);
	return 0;
}