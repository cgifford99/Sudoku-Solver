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
	//int sizeX;
	//int sizeY;
	int sBoard[9][9];
	//const enum diffInput { easy, medium, hard, };
	
	Board(){
		for (int i = 0; i <= 8; i++) { //Adds values to the vector
			numVec.push_back(i);
		}
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
		for (int x = 0; x < 9; x++) { //Sets values for the board

			/************************TEMP DEBUG CODE*****************************/
			cout << " ----------------------- " << endl;
			for (int b = 0; b < 9; b++) {
				if (b == 3 || b == 6 || b == 9) {
					cout << "| ------+-------+--------" << endl;
				}
				cout << "| ";
				for (int c = 0; c < 9; c++) {
					cout << sBoard[b][c] << " ";
					if (c == 2 || c == 5 || c == 8) {
						cout << "| ";
					}
				}
				cout << endl;
			}
			cout << " ----------------------- " << endl;
			/************************TEMP DEBUG CODE*****************************/

			for (int y = 0; y < 9; y++) {
				makeNum(sBoard, numVec, x);
			}
			var = 9;
		}
	}

	void makeNum(int arr[9][9], vector<int> numV, int x) { //Generates a random horizontal vector of numbers 1-9
		int randPos = 0 + (rand() % 8); //Finds a random position in the 1-9 list
		yPos = numV[randPos];
		//cout << "randPos= " << randPos; //Debug
		numV.erase(numV.begin() + yPos); //Currently doesn't erase the value ???
		numV.shrink_to_fit(); 
		for (int i = 0; i <= numV.size(); i++) {
			cout << numVec[i];
		}
		cout << endl;
		cout << " x= " << x; //Debug
		cout << " y= " << yPos << endl; //Debug
		sBoard[x][yPos] = var;
		//cout << " sBoard= " << sBoard[x][yPos] << endl; //Debug
		var--;
	}
	
private:
	vector<int> numVec;
	int var = 9;
	int yPos;

//protected:
	//int diffIn;
};

class Sudoku : public Board {
public:

	void printBoard(int arr[9][9]) { //prints the sudoku board with other aesthetics
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