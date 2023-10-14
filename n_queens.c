#include <stdio.h>
#define N 4

int ld[30], rd[30], cl[30];

// A utility function to print the solution
void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// A recursive utility function to solve the N-Queens problem
int solveNQUtil(int board[N][N], int col) {
    // Base case: If all queens are placed, return true
    if (col >= N) {
        return 1;
    }

    // Consider this column and try placing this queen in all rows one by one
    for (int i = 0; i < N; i++) {
        // Check if the queen can be placed on board[i][col]

        // To check if a queen can be placed on board[i][col], we just need to check ld[i - col + N - 1] and rd[i + col] where ld and rd are for left and right diagonals respectively
        if (!ld[i - col + N - 1] && !rd[i + col] && !cl[i]) {
            // Place this queen in board[i][col]
            board[i][col] = 1;
            ld[i - col + N - 1] = rd[i + col] = cl[i] = 1;

            // Recur to place the rest of the queens
            if (solveNQUtil(board, col + 1)) {
                return 1;
            }

            // If placing the queen in board[i][col] doesn't lead to a solution, then remove the queen from board[i][col]
            board[i][col] = 0;
            ld[i - col + N - 1] = rd[i + col] = cl[i] = 0;
        }
    }

    // If the queen cannot be placed in any row in this column col, then return false
    return 0;
}

// This function solves the N-Queens problem using backtracking. It mainly uses solveNQUtil() to solve the problem. It returns 0 if queens cannot be placed, otherwise, it returns 1 and prints the placement of queens in the form of 1s.
// Please note that there may be more than one solution; this function prints one of the feasible solutions.
int solveNQ() {
    int board[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }

    if (!solveNQUtil(board, 0)) {
        printf("Solution does not exist\n");
        return 0;
    }

    printSolution(board);
    return 1;
}

int main() {
    if (solveNQ() == 0) {
        printf("No solution exists\n");
    }

    return 0;
}
