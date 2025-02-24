#include<iostream>
using namespace std;

int main() {
    // q is queens and c is column
    int q[8], c = 0, count = 0;
    q[0] = 0;

start:  
    c++;
    // goto statement 
    if (c == 8) goto print;

    q[c] = -1;

next_row:
    q[c]++; // goto statement 
    if (q[c] == 8) goto backtrack;

    for (int i = 0; i < c; i++) {
        // Check for problums with the columns              // goto statement 
        if (q[i] == q[c] || q[c] - q[i] == c - i || q[i] - q[c] == c - i) goto next_row;
    }
    // goto statement 
    goto start;

backtrack:
    c--;
    if (c == -1) {
        // Giving a total
        cout << "Number of solutions: " << count << endl;
        return 0;
    }
    // goto statement 
    goto next_row;

print:
    count++;
    // Showing solution numbers
    cout << "Solution #" << count << ":" << endl;

    // Print 1d array
    for (int i = 0; i < 8; i++) {
        cout << q[i] << " ";
    }
    cout << endl << endl;

    // Print the 8x8 board
    // r is for row
    for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
            // Indicating the queen
            if (q[c] == r) cout << "q ";
            // Indicating empty space 
            else cout << "0 ";
        }
        cout << endl;
    }
    cout << endl;
    // goto statement 
    goto backtrack;
}