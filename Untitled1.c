#include <stdio.h>
#include <string.h>

void PRINT_LCS(char C[][100], char X[], int i, int j) {
    // Base case: if we reach the beginning of either string, return
    if (i == 0 || j == 0)
        return;

    // If the characters match, move diagonally in the table and print the character
    if (C[i][j] == 'Y') {
        PRINT_LCS(C, X, i - 1, j - 1);
        printf("%c", X[i - 1]);
    }
    // If the value is 'U', move upwards in the table
    else if (C[i][j] == 'U') {
        PRINT_LCS(C, X, i - 1, j);
    }
    // If the value is 'L', move left in the table
    else {
        PRINT_LCS(C, X, i, j - 1);
    }
}

int LCS_LENGTH(char X[], char Y[], int m, int n) {
    int T[m + 1][n + 1];  // Table for lengths
    char C[m + 1][n + 1]; // Table for directions

    // Initialize the tables
    for (int i = 0; i <= m; i++) {
        T[i][0] = 0;
        C[i][0] = 0;
    }
    for (int j = 0; j <= n; j++) {
        T[0][j] = 0;
        C[0][j] = 0;
    }

    // Fill the tables using the dynamic programming approach
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                T[i][j] = T[i - 1][j - 1] + 1;
                C[i][j] = 'Y';  // Diagonal move (match)
            }
            else if (T[i - 1][j] >= T[i][j - 1]) {
                T[i][j] = T[i - 1][j];
                C[i][j] = 'U';  // Move up (T[i-1][j] is larger)
            }
            else {
                T[i][j] = T[i][j - 1];
                C[i][j] = 'L';  // Move left (T[i][j-1] is larger)
            }
        }
    }

    // Print the LCS using the backtracking function
    printf("\nLCS: ");
    PRINT_LCS(C, X, m, n);
    printf("\n");

    return T[m][n]; // Return the length of LCS
}

int main() {
    int m, n;
    char X[100], Y[100];

    // Input strings X and Y
    printf("Enter the length of the first string: ");
    scanf("%d", &m);
    printf("Enter the first string: ");
    scanf("%s", X);

    printf("Enter the length of the second string: ");
    scanf("%d", &n);
    printf("Enter the second string: ");
    scanf("%s", Y);

    // Call the LCS_LENGTH function and print the result
    int lcs_length = LCS_LENGTH(X, Y, m, n);
    printf("\nLength of LCS: %d\n", lcs_length);

    return 0;
}
