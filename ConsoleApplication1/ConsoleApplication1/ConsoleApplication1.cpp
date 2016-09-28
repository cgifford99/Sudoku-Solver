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
	int** sBoard;
	const enum diffInput { easy, medium, hard, };

	Board(){
		cout << "Enter difficulty: Easy, Medium or Hard?";
		cin >> din;
		switch (din) {
		case easy:
			sizeX = 6;
			sizeY = 6;
			break;
		case medium:
			sizeX = 9;
			sizeY = 9;
			break;
		case hard:
			sizeX = 16;
			sizeY = 16;
			break;
		}
		allocate(sBoard);
		sBoard[sizeX][sizeY];
	}
	
	void allocate(int** arr) {
		arr = new int*[sizeX];
		for (int x = 0; x < sizeX; x++) {
			arr[x] = new int[sizeY];
		}
		cout << sizeX << endl;
		cout << sizeY << endl;
	}

protected:
	int din;
};

class Sudoku : public Board {
public:
	void createBoard(int** arr) {
		arr[sizeX][sizeY];
		for (int d = 0; d < sizeX; d++) {
			for (int e = 0; e < sizeY; e++) {
				arr[d][e] = 1 + (rand() % sizeX);
			}
		}
		for (int r = 0; r < 35; r++) {
			arr[(0 + (rand() % sizeX-1))][(0 + (rand() % sizeX-1))] = 0;
		}
	}

	void printBoard(int** arr) {
		arr[sizeX][sizeY];
		for (int b = 0; b < sizeX; b++) {
			/*
			if (b == 3 || b == 6 || b == 9) {
				cout << "| ------+-------+--------" << endl;
			}
			cout << "| ";
			*/
			for (int c = 0; c < 9; c++) {
				cout << arr[b][c] << " ";
				//if (c == 2 || c == 5 || c == 8) {
				//	cout << "| ";
				//}
			}
			cout << endl;
		}
	}
};

int main() {
	Sudoku gameObj; 
	gameObj.createBoard(gameObj.sBoard);
	gameObj.printBoard(gameObj.sBoard);
	return 0;
}