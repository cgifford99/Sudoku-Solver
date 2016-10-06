// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Board {
public:
	int sizeX;
	int sizeY;
	int sBoard[9][9];
	const enum diffInput { easy, medium, hard, };
	
	Board(){
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
	}
	
	void genBoard() {
		for (int i = 1; i <= 9; i++) { //Adds values to the vector
			numVec.push_back(i);
		}
		for (int x = 0; x < 9; x++) { //Sets values for the board
			for (int y = 0; y < 9; y++) {
				makeNum(sBoard, numVec, x);
			}
			var = 9;
		}
	}

	void makeNum(int arr[9][9], vector<int> arrV, int x) { //Generates a random horizontal vector of numbers 1-9
		int randPos = 0 + (rand() % 8);
		yPos = arrV[randPos];
		arrV.erase(arrV.begin()+randPos);
		arrV.shrink_to_fit();
		cout << "x= " << x << endl;
		cout << "yPos= " << yPos << endl;
		sBoard[x][yPos] = var;
		cout << "sBoard= " << sBoard[x][yPos] << endl;
		var--;
	}
	
private:
	vector<int> numVec;
	int var = 9;
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