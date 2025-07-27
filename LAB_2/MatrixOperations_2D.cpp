#include <iostream>
#include <vector>

using namespace std;

void matrixAddition() {
    int m, n;
    cout << "Enter the number of rows and columns: ";
    cin >> m >> n;

    vector<vector<int>> A(m, vector<int>(n));
    vector<vector<int>> B(m, vector<int>(n));
    vector<vector<int>> C(m, vector<int>(n));

    cout << "Enter elements of Matrix A:\n";
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << "Enter elements of Matrix B:\n";
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> B[i][j];

    cout << "Sum Matrix C = A + B:\n";
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
            cout << C[i][j] << " ";
        }
        cout << "\n";
    }
}

void matrixMultiplication() {
    int m, p, n;
    cout << "Enter dimensions of Matrix A (rows m and columns p): ";
    cin >> m >> p;
    cout << "Enter number of columns n for Matrix B: ";
    cin >> n;

    vector<vector<int>> A(m, vector<int>(p));
    vector<vector<int>> B(p, vector<int>(n));
    vector<vector<int>> C(m, vector<int>(n, 0));

    cout << "Enter elements of Matrix A:\n";
    for(int i = 0; i < m; i++)
        for(int j = 0; j < p; j++)
            cin >> A[i][j];

    cout << "Enter elements of Matrix B:\n";
    for(int i = 0; i < p; i++)
        for(int j = 0; j < n; j++)
            cin >> B[i][j];

    // Matrix multiplication logic
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < p; k++)
                C[i][j] += A[i][k] * B[k][j];

    cout << "Resultant Matrix C = A × B:\n";
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
            cout << C[i][j] << " ";
        cout << "\n";
    }
}

void transposeMatrix() {
    int m, n;
    cout << "Enter the number of rows and columns: ";
    cin >> m >> n;

    vector<vector<int>> A(m, vector<int>(n));
    vector<vector<int>> T(n, vector<int>(m));

    cout << "Enter elements of Matrix A:\n";
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> A[i][j];

    // Transpose logic
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            T[j][i] = A[i][j];

    cout << "Original Matrix A:\n";
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
            cout << A[i][j] << " ";
        cout << "\n";
    }

    cout << "Transpose Matrix AT:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cout << T[i][j] << " ";
        cout << "\n";
    }
}

void determinant2x2() {
    vector<vector<int>> a(2, vector<int>(2));
    cout << "Enter elements of 2x2 matrix:\n";
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            cin >> a[i][j];

    int det = (a[0][0] * a[1][1]) - (a[0][1] * a[1][0]);
    cout << "Determinant = " << det << "\n";
}

void saddlePoint() {
    int m, n;
    cout << "Enter number of rows and columns: ";
    cin >> m >> n;
    vector<vector<int>> a(m, vector<int>(n));

    cout << "Enter matrix elements:\n";
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            cin >> a[i][j];

    bool found = false;
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
        bool isSaddle = true;
        for(int k=0; k<m; k++) {
            if(a[k][colIdx] > min) {
                isSaddle = false;
                break;
            }
        }

        if(isSaddle) {
            cout << "Saddle Point Found at (" << i << "," << colIdx << "): " << min << "\n";
            found = true;
        }
    }

    if(!found)
        cout << "No Saddle Point found.\n";
}

int main() {
    int choice;
    do {
        cout << "\n=== Part A: 2D Matrix Operations ===\n";
        cout << "1. Matrix Addition\n";
        cout << "2. Matrix Multiplication\n";
        cout << "3. Transpose of a Matrix\n";
        cout << "4. Determinant of 2x2 Matrix\n";
        cout << "5. Saddle Point of a Matrix\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: matrixAddition(); break;
            case 2: matrixMultiplication(); break;
            case 3: transposeMatrix(); break;
            case 4: determinant2x2(); break;
            case 5: saddlePoint(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while(choice != 0);

    return 0;
}
