#include <iostream>
using namespace std;

bool isWon(char, char[][3]);
bool isDraw(char[][3]);
void displayBoard(char[][3]);
void makeAMove(char[][3], char);

int main() {

	char board[3][3] = { { ' ', ' ', ' ' },{ ' ', ' ', ' ' },{ ' ', ' ', ' ' } };
	displayBoard(board);

	while (true) {
		// The first player makes a move
		makeAMove(board, 'X');
		displayBoard(board);
		if (isWon('X', board)) {
			cout << "X player won" << endl;
			exit(0);
		}
		else if (isDraw(board)) {
			cout << "No winner" << endl;
			exit(0);
		}

		// The second player makes a move
		makeAMove(board, 'O');
		displayBoard(board);

		if (isWon('O', board)) {
			cout << "O player won" << endl;
			exit(0);
		}
		else if (isDraw(board)) {
			cout << "No winner" << endl;
			exit(0);
		}
	}


	return 0;
}


//start to implement the functions

void displayBoard(char arr[][3])
{
	//based off of the sample output make a tic tac toe "board"
	//it is a simple 2d array with total of 3 columns and 3 rows

	cout << "-------------" << endl;

	for (int i = 0; i < 3; i++) {
		cout << " | " << arr[i][0] << " | " << arr[i][1] << " | " << arr[i][2] << endl;
	}

	cout << "-------------" << endl;
}

void makeAMove(char arr[][3], char x
) {

	int row, column = -1;
	//do while loop; do what user asks while its all true
	do {
		//get user input to see what row and column they want to select
		cout << "Enter a row (0, 1, 2) for player " << x << "    : ";
		cin >> row;
		cout << "Enter a column (0, 1, 2) for player " << x << " : ";
		cin >> column;

		//check for valid input, correct row and column
		if (row >= 0 && row < 3 && column >= 0 && column < 3) {
			//check to see if the space the user chose is empty or not
			if (arr[row][column] == ' ') {
				//place an X inside that box if it was empty
				arr[row][column] = x;
				break;
			}
			else cout << "This cell is already occupied. Try a different cell" << endl;
		}
		else cout << "Invalid row or column, please choose between (0, 1, 2)" << endl;
	} while (true);

}

bool isWon(char x, char arr[][3]) {
	//check to see if the if the user won 3 ina row
	//use for loop to go thru 2d array
	for (int i = 0; i < 3; i++) {
		//first is to check to see if 3 ina row VERTICAL
		if (arr[0][i] == x && arr[1][i] == x && arr[2][i] == x) {
			return true;
		}

		//second is to check to see if 3 ina row HORIZONTAL
		else if (arr[i][0] == x && arr[i][1] == x && arr[i][2] == x) {
			return true;
		}
	}

	//check to see if 3 ina row DIAGONAL
	if ((arr[0][0] == x && arr[1][1] == x && arr[2][2] == x) || (arr[0][2] == x && arr[1][1] == x && arr[2][0] == x)) {
		return true;
	}

	//if none of the top results happens, means no winner
	return false;
}

bool isDraw(char arr[][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (arr[i][j] == ' ') {
				return false;//empty slot so the game is not a draw yet
			}
		}
	}
	return true;
}

