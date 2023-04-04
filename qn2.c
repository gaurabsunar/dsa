#include <stdio.h>

int main() {
    int arr[15];
    int i, j, temp;

    // Prompt user to enter 15 integers
    printf("Enter 15 integers:\n");
    for (i = 0; i < 15; i++) {
        scanf("%d", &arr[i]);
    }

    // Bubble sort algorithm to sort the array in ascending order
    for (i = 0; i < 15; i++) {
        for (j = 0; j < 14-i; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap adjacent elements
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    // Print the sorted array
    printf("Sorted array in ascending order:\n");
    for (i = 0; i < 15; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
