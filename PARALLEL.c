#include <stdio.h>
#include <omp.h>       
#include <time.h>      

// Function to perform parallel bubble sort
void parallelBubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Parallelize the inner loop using OpenMP
        #pragma omp parallel for
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
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


double calculateExecutionTime(clock_t start, clock_t end) {
    
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Record the start time
    clock_t start = clock();

    // Print the original array
    printf("Original array: ");
    printArray(arr, n);

    // Perform parallel bubble sort
    parallelBubbleSort(arr, n);

    // Record the end time
    clock_t end = clock();

    // Print the sorted array
    printf("Sorted array: ");
    printArray(arr, n);

    // Calculate and print the execution time
    double executionTime = calculateExecutionTime(start, end);
    printf("Execution time: %f seconds\n", executionTime);

    return 0;
}
