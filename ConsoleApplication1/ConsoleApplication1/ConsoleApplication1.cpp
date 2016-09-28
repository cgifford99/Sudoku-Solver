// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

class Board {
public:
	int sizeX;
	int sizeY;
	const enum diffInput { easy, medium, hard, };

	Board() {
		int din;
		cout << "Enter difficulty: Easy, Medium or Hard?";
		cin >> din;
		switch (din) {
		case easy:
			sizeX = 9;
			sizeY = sizeX;
			break;
		case medium:
			sizeX = 9;
			sizeY = sizeX;
			break;
		case hard:
			sizeX = 9;
			sizeY = sizeX;
			break;
		}
	}
};

class Sudoku : public Board {
public:
	int board[9][9]{
	};
	void createBoard(int arr[9][9]) {
		for (int d = 0; d < 9; d++) {
			for (int e = 0; e < 9; e++) {
				arr[d][e] = 1 + (rand() % 9);

			}
		}
		for (int r = 0; r < 35; r++) {
			arr[(0 + (rand() % 8))][(0 + (rand() % 8))] = 0;
		}
	}

	void printBoard(int arr[9][9]) {
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
	}
};

int main() {
	Board setUp;
	//Sudoku gameObj;
	
	//gameObj.createBoard(gameObj.board);
	//gameObj.printBoard(gameObj.board);

	
	/*
	int array1[9]{ 0,1,2,3,4,5,6,7,8 };
	for (int i = 0; i < (sizeof(array1) / sizeof(*array1)); i++) {
		cout << array1[i] << endl;
	}
	*/

	return 0;
}