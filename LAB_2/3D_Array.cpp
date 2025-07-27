#include <iostream>
#include <vector>

using namespace std;

void traverse3DArray() {
    int arr[2][3][4] = {
        {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12}
        },
        {
            {13, 14, 15, 16},
            {17, 18, 19, 20},
            {21, 22, 23, 24}
        }
    };

    cout << "Traversing 3D Array (2x3x4):\n";
    for (int i = 0; i < 2; i++) {
        cout << "Layer " << i << ":\n";
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 4; k++) {
                cout << arr[i][j][k] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
}

void search3DArray() {
    vector<vector<vector<int>>> arr(3, vector<vector<int>>(3, vector<int>(3)));
    int x;

    cout << "Enter elements of 3x3x3 array:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                cin >> arr[i][j][k];
            }
        }
    }

    cout << "Enter element to search: ";
    cin >> x;

    bool found = false;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (arr[i][j][k] == x) {
                    cout << "Found at Layer " << i << ", Row " << j << ", Column " << k << "\n";
                    found = true;
                }
            }
        }
    }

    if (!found)
        cout << "Element not found in the 3D array.\n";
}

void sum3DArray() {
    vector<vector<vector<int>>> arr(2, vector<vector<int>>(2, vector<int>(2)));
    int sum = 0;

    cout << "Enter elements of 2x2x2 array:\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                cin >> arr[i][j][k];
                sum += arr[i][j][k];
            }
        }
    }

    cout << "Sum of all elements: " << sum << "\n";
}

int main() {
    int choice;
    do {
        cout << "\n=== Part B: 3D Array Operations ===\n";
        cout << "1. Traverse 3D Array (2x3x4)\n";
        cout << "2. Search in 3D Array (3x3x3)\n";
        cout << "3. Sum of Elements in 3D Array (2x2x2)\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: traverse3DArray(); break;
            case 2: search3DArray(); break;
            case 3: sum3DArray(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
