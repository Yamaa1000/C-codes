#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int board[8] = {0}, column = 0, solutionNum = 0;
    int adjacents[][5] = { 
        {-1, -1, -1, -1, -1}, // No adjacents for column 0
        {0, -1, -1, -1, -1},  // Column 1 for column 0
        {0, 1, -1, -1, -1},   // Column 2 for columns 0 and 1
        {0, 2, -1, -1, -1},   // Column 3 for columns 0 and 2
        {1, 2, -1, -1, -1},   // Column 4 for columns 1 and 2
        {1, 2, 3, 4, -1},     // Column 5 for columns 1 and 2 and 3 and 4
        {2, 3, 5, -1, -1},    // Column 6 for columns 2 and 3 and 5
        {4, 5, 6, -1, -1}     // Column 7 for columns 4 and 5 and 6
    };

    board[0] = 1; // Place the first queen in row 1 of column 0

tryNextColumn:
    column++;    // Move to the next column
    if (column == 8) goto displaySolution;  // If all columns are filled then display the solution

    board[column] = 0;

tryNextRow:
    board[column]++;  // Move the queen to the next row in the current column
    if (board[column] == 9) goto goBack;  // If the queen moves past row 8 then backtrack to the previous column
   
    for (int i = 0; i < column; i++) {
        if (board[column] == board[i]) goto tryNextRow;  // If the queen is already in the same row then try the next row
    }

    for (int i = 0; adjacents[column][i] != -1; i++) {
        if (abs(board[column] - board[adjacents[column][i]]) == 1) goto tryNextRow;
    }

    // If no problems then move to the next column.
    goto tryNextColumn;

goBack:
    column--;  // Backtrack to the previous column
    if (column == -1) return 0; 
    goto tryNextRow;  // Go to the next row of the previous column

displaySolution:
    solutionNum++;
    cout << "Solution #" << solutionNum << ":\n";

    for (int i = 0; i < 8; i++) {
        cout << board[i] << " ";
    }
    cout << "\n\n";

    // The 8x8 board
    cout << "  " << board[1] << " " << board[4] << "   \n";
    cout << board[0] << " " << board[2] << " " << board[5] << " " << board[7] << "\n";
    cout << "  " << board[3] << " " << board[6] << "   \n\n";

    goto goBack;  // Goto go back
}