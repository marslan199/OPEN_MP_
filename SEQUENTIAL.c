#include <stdio.h>
#include <time.h>  // For clock()

// Function to perform sequential bubble sort
void sequentialBubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap the elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to calculate execution time
double calculateExecutionTime(clock_t start, clock_t end) {
  
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

   
    clock_t start = clock();

  
    printf("Original array: ");
    printArray(arr, n);

   
    sequentialBubbleSort(arr, n);

   
    clock_t end = clock();

    // Print the sorted array
    printf("Sorted array: ");
    printArray(arr, n);

    double executionTime = calculateExecutionTime(start, end);
    printf("Execution time: %f seconds\n", executionTime);

    return 0;
}
