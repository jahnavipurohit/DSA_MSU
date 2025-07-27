#include <iostream>
#include <vector>

using namespace std;

void createNullMatrix() {
    vector<vector<int>> matrix(3, vector<int>(3, 0));
    cout << "Null Matrix 3x3:\n";
    for (const auto& row : matrix) {
        for (int val : row)
            cout << val << " ";
        cout << "\n";
    }
}

void createIdentityMatrix() {
    int n = 4;
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
        matrix[i][i] = 1;

    cout << "Identity Matrix 4x4:\n";
    for (const auto& row : matrix) {
        for (int val : row)
            cout << val << " ";
        cout << "\n";
    }
}

void checkSquareMatrix() {
    int rows, cols;
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    if (rows == cols)
        cout << "Matrix is Square\n";
    else
        cout << "Matrix is Not Square\n";
}

void checkIdentityMatrix() {
    int n;
    cout << "Enter size of square matrix: ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    cout << "Enter elements of matrix:\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> matrix[i][j];

    bool isIdentity = true;
    for (int i = 0; i < n && isIdentity; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((i == j && matrix[i][j] != 1) || (i != j && matrix[i][j] != 0)) {
                isIdentity = false;
                break;
            }
        }
    }

    if (isIdentity)
        cout << "Matrix is an Identity Matrix\n";
    else
        cout << "Matrix is NOT an Identity Matrix\n";
}

void defineAndDisplay2DArray() {
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}};
    cout << "Defined 2D Array:\n";
    for (const auto& row : matrix) {
        for (int val : row)
            cout << val << " ";
        cout << "\n";
    }
}

void inputAndDisplay2DArray() {
    int rows, cols;
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));
    cout << "Enter elements of the matrix:\n";
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            cin >> matrix[i][j];

    cout << "The matrix is:\n";
    for (const auto& row : matrix) {
        for (int val : row)
            cout << val << " ";
        cout << "\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\n=== 2D Matrix ===\n";
        cout << "1. Create Null Matrix (3x3)\n";
        cout << "2. Create Identity Matrix (4x4)\n";
        cout << "3. Check if Matrix is Square\n";
        cout << "4. Check if Matrix is Identity\n";
        cout << "5. Define and Display Predefined 2D Array\n";
        cout << "6. Input and Display 2D Array\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: createNullMatrix(); break;
            case 2: createIdentityMatrix(); break;
            case 3: checkSquareMatrix(); break;
            case 4: checkIdentityMatrix(); break;
            case 5: defineAndDisplay2DArray(); break;
            case 6: inputAndDisplay2DArray(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
