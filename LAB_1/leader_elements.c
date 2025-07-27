#include <stdio.h>

void findLeaders(int arr[], int n) {
    int maxFromRight = arr[n - 1];
    int leaders[n];  // To store leaders
    int leaderCount = 0;

    // The rightmost element is always a leader
    leaders[leaderCount++] = maxFromRight;

    // Traverse from second last element to the beginning
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > maxFromRight) {
            maxFromRight = arr[i];
            leaders[leaderCount++] = maxFromRight;
        }
    }

    // Leaders were stored from right to left, print in reverse order
    printf("Leader elements are: ");
    for (int i = leaderCount - 1; i >= 0; i--) {
        printf("%d ", leaders[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    findLeaders(arr, n);

    return 0;
}
