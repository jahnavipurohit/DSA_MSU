#include <stdio.h>

void createNullMatrix() {
    int matrix[3][3] = {0};
    printf("Null Matrix 3x3:\n");
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void createIdentityMatrix() {
    int matrix[4][4];
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            matrix[i][j] = (i == j) ? 1 : 0;
        }
    }
    printf("Identity Matrix 4x4:\n");
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void checkSquareMatrix() {
    int rows, cols;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    if(rows == cols)
        printf("Matrix is Square\n");
    else
        printf("Matrix is Not Square\n");
}

void checkIdentityMatrix() {
    int n;
    printf("Enter size of square matrix: ");
    scanf("%d", &n);

    int matrix[n][n];
    printf("Enter elements of matrix:\n");
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int isIdentity = 1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if((i == j && matrix[i][j] != 1) || (i != j && matrix[i][j] != 0)) {
                isIdentity = 0;
                break;
            }
        }
        if(!isIdentity) break;
    }

    if(isIdentity)
        printf("Matrix is an Identity Matrix\n");
    else
        printf("Matrix is NOT an Identity Matrix\n");
}

void defineAndDisplay2DArray() {
    int matrix[2][3] = { {1, 2, 3}, {4, 5, 6} };
    printf("Defined 2D Array:\n");
    for(int i=0; i<2; i++) {
        for(int j=0; j<3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void inputAndDisplay2DArray() {
    int rows, cols;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int matrix[rows][cols];
    printf("Enter elements of the matrix:\n");
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("The matrix is:\n");
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int choice;
    do {
        printf("\n=== 2D Matrix ===\n");
        printf("1. Create Null Matrix (3x3)\n");
        printf("2. Create Identity Matrix (4x4)\n");
        printf("3. Check if Matrix is Square\n");
        printf("4. Check if Matrix is Identity\n");
        printf("5. Define and Display Predefined 2D Array\n");
        printf("6. Input and Display 2D Array\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: createNullMatrix(); break;
            case 2: createIdentityMatrix(); break;
            case 3: checkSquareMatrix(); break;
            case 4: checkIdentityMatrix(); break;
            case 5: defineAndDisplay2DArray(); break;
            case 6: inputAndDisplay2DArray(); break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while(choice != 0);

    return 0;
}
