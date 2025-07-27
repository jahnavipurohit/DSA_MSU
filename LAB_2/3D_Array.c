#include <stdio.h>

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

    printf("Traversing 3D Array (2x3x4):\n");
    for(int i = 0; i < 2; i++) {
        printf("Layer %d:\n", i);
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 4; k++) {
                printf("%d ", arr[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

void search3DArray() {
    int arr[3][3][3];
    int x;
    
    printf("Enter elements of 3x3x3 array:\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++) {
                scanf("%d", &arr[i][j][k]);
            }
        }
    }

    printf("Enter element to search: ");
    scanf("%d", &x);

    int found = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++) {
                if(arr[i][j][k] == x) {
                    printf("Found at Layer %d, Row %d, Column %d\n", i, j, k);
                    found = 1;
                }
            }
        }
    }

    if(!found)
        printf("Element not found in the 3D array.\n");
}

void sum3DArray() {
    int arr[2][2][2];
    int sum = 0;

    printf("Enter elements of 2x2x2 array:\n");
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 2; k++) {
                scanf("%d", &arr[i][j][k]);
                sum += arr[i][j][k];
            }
        }
    }

    printf("Sum of all elements: %d\n", sum);
}

int main() {
    int choice;
    do {
        printf("\n=== Part B: 3D Array Operations ===\n");
        printf("1. Traverse 3D Array (2x3x4)\n");
        printf("2. Search in 3D Array (3x3x3)\n");
        printf("3. Sum of Elements in 3D Array (2x2x2)\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: traverse3DArray(); break;
            case 2: search3DArray(); break;
            case 3: sum3DArray(); break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while(choice != 0);

    return 0;
}
