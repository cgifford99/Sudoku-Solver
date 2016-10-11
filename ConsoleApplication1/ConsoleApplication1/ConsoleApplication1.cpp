// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
//#include <algorithm>
using namespace std;

class Board {
public:
	//int sizeX;
	//int sizeY;
	//const enum diffInput { easy, medium, hard, };
	
	Board(){
		resetVector(numVec);
		cout << "did thing" << endl;
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
		genBoard(sBoard, numVec);
		printBoard(sBoard);
	}
	
	void genBoard(int arr[9][9], vector<int> &numV) {
		for (int x = 0; x < 9; x++) { //Sets values for the board
			printBoard(arr);
			for (int y = 0; y < 9; y++) {
				makeNum(sBoard, numV, x);
			}
			resetVector(numV);
			var = 9;
		}
	}

	void makeNum(int arr[9][9], vector<int> &numV, int x) { //Generates a random horizontal vector of numbers 1-9
		int randPos = 0 + (rand() % numV.size()); //******MAGIC******//Finds a random position in the 1-9 list
		yPos = numV[randPos];
		cout << "randPos= " << randPos << endl; //Debug
		numV.erase(numV.begin() + randPos); //Currently doesn't erase the value ???
		numV.shrink_to_fit();
		//cout << numV.capacity() << endl;
		for (int i = 0; i < numV.size(); i++) { //Prints the current vector
			cout << numV[i];
		}
		cout << endl;
		cout << " x= " << x; //Debug
		cout << " y= " << yPos << endl; //Debug
		arr[x][yPos] = var;
		cout << " sBoard= " << sBoard[x][yPos] << endl; //Debug
		var--;
	}

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

	void resetVector(vector<int> &vec) {
		int arrOfTen[9] = { 0,1,2,3,4,5,6,7,8 };
		vec.assign(arrOfTen, arrOfTen + 9);
		printVector(vec, vec.size());
	}
	
	void printVector(vector<int> &vec, int vecRange) {
		for (int y = 0; y < vecRange; y++) {
			cout << vec[y] << endl;
		}
	}
	
private:
	vector<int> numVec;
	int var = 9;
	int yPos;

protected:
	int sBoard[9][9];
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