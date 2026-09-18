#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//board this states that the board is a 9x9 of number
int board[9][9];

//this creates a boarder for the board for better presentation
void boardboarders(){
    for(int i = 0; i < 9; i++){
        if (i == 3 || i == 6) {
            cout << string(24, '-') << "\n"; //this creates a horizontal line after the third and sixth row
        }
        for(int j = 0; j < 9; j++){
            if (j == 3 || j == 6) {
                cout << " | "; //this creates a vetical line after the third and sixth column
            }
            cout << board[i][j] << " "; // this puts a space in between the numbers for better readablity
        }
        cout << "\n";
    }
    cout << "\n";
}
//per column, row and 3x3 grid
bool validcheck(int row, int col, char num) {
    //row
    for(int j=0; j<9; j++){
        if(board[row][j] == num) 
            return false; //if num repeats in row = invalid
    }
    //column
    for(int i=0; i<9; i++){
        if(board[i][col] == num)
            return false; //if num repeats in column = invalid
    }
    //3×3 subgrid
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(board[row - (row % 3) + i][col - (col % 3) + j] == num)
                return false; //if num repeats in 3x3 grid = invalid
        }
    }
    return true;
}

//solving
bool solve() {
    for(int row = 0; row < 9; row++) {
        for(int col = 0; col < 9; col++) {
            if(board[row][col] == 0) { // if space is empty 

                for(int num = 1; num <= 9; num++) { // try numbers 1-9
                    if(validcheck(row, col, num)) { // can we place num here?
                        board[row][col] = num;

                        if(solve()) return true;

                        board[row][col] = 0; // if theres an error reset the cell to 0
                    }
                }
                return false; // cannot place any number
            }
        }
    }
    return true; // solved
}


//input and output - main program
int main (){

    cout << setw(70) << "<< Welcome! This program will solve your Sudoku puzzle. >>\n";
    cout << string(80, '=') << "\n";    

    cout << "\nPlease enter your Sudoku puzzle row by row, using 0 for empty cells:\n";
    
    //loop
    do {

        for (int i = 0; i < 9; i++){ // counts rows
            for (int j = 0; j < 9; j++){ // counts columns
                cin >> board[i][j]; 
            }
        }

        if (solve()){
            cout << "\nHere is your solved sudoku puzzle!\n";
            boardboarders(); //If the puzzle is solvable, display the solved board
        }
        else
            cout << "Sorry, this Sudoku puzzle cannot be solved.\n";


        cout << "Would you like to solve another puzzle? (y/n): "; //Asks the user if they want to solve another puzzle

        char choice;
        cin >> choice;

        while (true){ //loop to validate user input
            if (choice == 'n' || choice == 'N') {
                cout << "Thank you for using the Sudoku solver. Goodbye!\n";
                break; // Exit the loop if the user does not want to solve another puzzle
            } else if (choice == 'y' || choice == 'Y') {
                cout << "Please enter the new puzzle row by row, using 0 for empty cells:\n";
                break; // Exit the loop if the user wants to solve another puzzle
            }
            else {
                cout << "Invalid choice. Please enter either 'y' or 'n'\n";
                break; // Exit the loop on invalid inpu
            }
        }

    } while (true);

    return 0;
}