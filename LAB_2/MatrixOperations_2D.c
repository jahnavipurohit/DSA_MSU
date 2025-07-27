#include <stdio.h>

void matrixAddition() {
    int m, n;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &m, &n);

    int A[m][n], B[m][n], C[m][n];

    printf("Enter elements of Matrix A:\n");
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    printf("Enter elements of Matrix B:\n");
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &B[i][j]);

    printf("Sum Matrix C = A + B:\n");
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
}

void matrixMultiplication() {
    int m, p, n;
    printf("Enter dimensions of Matrix A (rows m and columns p): ");
    scanf("%d %d", &m, &p);
    printf("Enter number of columns n for Matrix B: ");
    scanf("%d", &n);

    int A[m][p], B[p][n], C[m][n];

    printf("Enter elements of Matrix A:\n");
    for(int i = 0; i < m; i++)
        for(int j = 0; j < p; j++)
            scanf("%d", &A[i][j]);

    printf("Enter elements of Matrix B:\n");
    for(int i = 0; i < p; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &B[i][j]);

    // Initialize C to 0
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            C[i][j] = 0;

    // Matrix multiplication logic
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < p; k++)
                C[i][j] += A[i][k] * B[k][j];

    printf("Resultant Matrix C = A × B:\n");
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }
}

void transposeMatrix() {
    int m, n;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &m, &n);

    int A[m][n], T[n][m];

    printf("Enter elements of Matrix A:\n");
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    // Transpose logic
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            T[j][i] = A[i][j];

    printf("Original Matrix A:\n");
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
            printf("%d ", A[i][j]);
        printf("\n");
    }

    printf("Transpose Matrix AT:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            printf("%d ", T[i][j]);
        printf("\n");
    }
}

void determinant2x2() {
    int a[2][2];
    printf("Enter elements of 2x2 matrix:\n");
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            scanf("%d", &a[i][j]);

    int det = (a[0][0] * a[1][1]) - (a[0][1] * a[1][0]);
    printf("Determinant = %d\n", det);
}

void saddlePoint() {
    int m, n;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);
    int a[m][n];

    printf("Enter matrix elements:\n");
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &a[i][j]);

    int found = 0;
    for(int i=0; i<m; i++) {
        int min = a[i][0], colIdx = 0;

        // Find min in row
        for(int j=1; j<n; j++) {
            if(a[i][j] < min) {
                min = a[i][j];
                colIdx = j;
            }
        }

        // Check if it's the max in its column
        int isSaddle = 1;
        for(int k=0; k<m; k++) {
            if(a[k][colIdx] > min) {
                isSaddle = 0;
                break;
            }
        }

        if(isSaddle) {
            printf("Saddle Point Found at (%d,%d): %d\n", i, colIdx, min);
            found = 1;
        }
    }

    if(!found)
        printf("No Saddle Point found.\n");
}

int main() {
    int choice;
    do {
        printf("\n=== Part A: 2D Matrix Operations ===\n");
        printf("1. Matrix Addition\n");
        printf("2. Matrix Multiplication\n");
        printf("3. Transpose of a Matrix\n");
        printf("4. Determinant of 2x2 Matrix\n");
        printf("5. Saddle Point of a Matrix\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: matrixAddition(); break;
            case 2: matrixMultiplication(); break;
            case 3: transposeMatrix(); break;
            case 4: determinant2x2(); break;
            case 5: saddlePoint(); break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while(choice != 0);

    return 0;
}
