#include <iostream>

using namespace std;

int main() {
    // Makes the board 0
    // a is queen b is row and c is column 
    int a[8][8] = {0};

    // Start in the 1st row and column, as while as the queen place
    int b = 0, c = 0;
    a[b][c] = 1;

nextCol:
    c++;  // Moves to the next column

    if (c > 7) 
        goto print;

    b = -1;  // Reset the row for the next column

nextRow:
    b++;  // Move to the next row

    if (b > 7) // If you have passed the end of the column, backtrack
        goto backtrack;

    // Check for queens on the whole left diagonal
    for (int i = 1; i <= c; i++) {
        if (a[b][c - i] == 1) goto nextRow;
    }
    for (int i = 1; b - i >= 0 && c - i >= 0; i++) {
        if (a[b - i][c - i] == 1) goto nextRow;
    }
    for (int i = 1; b + i < 8 && c - i >= 0; i++) {
        if (a[b + i][c - i] == 1) goto nextRow;
    }

    // Place a queen on the square
    a[b][c] = 1;
    goto nextCol;

backtrack:
    c--;  // Moves to the previous column

    if (c < 0) // If you move left of the board, exit the program
        return 0;

    for (int i = 0; i < 8; i++) {
        if (a[i][c] == 1) {  // Find the queen in the column
            b = i;
            break;
        }
    }

    // Remove the queen from the square and try the next row
    a[b][c] = 0;
    goto nextRow;

print:
    static int numSolutions = 0;
    cout << "Solution #" << ++numSolutions << ":\n";

    // Print the chessboard
    for (int i = 0; i < 8; i++) {
        for (int d = 0; d < 8; d++) {
            cout << a[d][d];
        }
        cout << endl;
    }
    cout << endl;

    // print 2D array goto backtrack
    goto backtrack;

    return 0;
}