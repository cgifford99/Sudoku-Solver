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
	}
	
	void genBoard() {
		for (int x = 0; x < 9; x++) {
			cout << x << endl;
			for (int y = 0; y < 9; y++) {
				if (sBoard[x][y] != 0) {
					sBoard[x][y] = 0;
				}
				else { genBoard(); }
				if (sBoard[x][y] == 0) {
					makeNum(sBoard, numArr, x);
				}
			}
			for (int i = 0; i < 9; i++) {
				numArr[i] = { var1 };
				var1++;
			}
			var1 = 1;
			var = 10;
		}
	}

	void makeNum(int arr[9][9], int arrN[9], int x) {
		int randPos = 0 + (rand() % 8);
		yPos = arrN[randPos];
		if (yPos == 0) {
			yPos = findNum(arrN);
		}
		arrN[randPos] = 0;
		sBoard[x][yPos] = var; //yPos == 0 removes second row from being inputted
		var--;
	}

	int findNum(int arrN[9]) {
		int tempPos;
		for (int y = 0; y < 9; y++) {
			if (arrN[y] != 0) {
				tempPos = arrN[y];
				arrN[y] = 0;
				return tempPos;
			} else {
				tempPos = 0;
			}
		}
	}

private:
	int numArr[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int var = 9;
	int var1 = 1;
	int yPos;

protected:
	int diffIn;
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