#include <iostream>
using namespace std;

const int ROWS = 3;
const int COLS = 3;

int main() {
    int arr[ROWS][COLS] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };

    cout << "2D Array in Row-Major Order:" << endl;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\n2D Array in Column-Major Order (Simulated):" << endl;
    for (int j = 0; j < COLS; ++j) {
        for (int i = 0; i < ROWS; ++i) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
