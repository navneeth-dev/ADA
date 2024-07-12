#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Function prototypes
void mergeSort(int arr[], int s, int e);
void merge(int arr[], int s, int e, int m);
void printArray(int arr[], int size);

// Recursive function to perform merge sort
void mergeSort(int arr[], int s, int e) {
    if (s < e) {
        int m = s + (e - s) / 2; // Calculate the middle point

        // Recursively sort the first and second halves
        mergeSort(arr, s, m);
        mergeSort(arr, m + 1, e);

        // Merge the sorted halves
        merge(arr, s, e, m);
    }
}

// Function to merge two subarrays of arr[]
void merge(int arr[], int s, int e, int m) {
    int i = 0, j = 0, k = s;
    int n1 = m - s + 1; // Size of the left subarray
    int n2 = e - m;     // Size of the right subarray

    int arr1[n1], arr2[n2]; // Temporary arrays to hold the subarrays

    // Copy data to temporary arrays arr1[] and arr2[]
    for (i = 0; i < n1; i++) {
        arr1[i] = arr[s + i];
    }
    for (j = 0; j < n2; j++) {
        arr2[j] = arr[m + 1 + j];
    }

    i = 0;
    j = 0;

    // Merge the temporary arrays back into arr[s..e]
    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            arr[k] = arr1[i];
            i++;
        } else {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of arr1[], if any
    while (i < n1) {
        arr[k] = arr1[i];
        i++;
        k++;
    }

    // Copy the remaining elements of arr2[], if any
    while (j < n2) {
        arr[k] = arr2[j];
        j++;
        k++;
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[10000], n, i, j, ch, temp;
    clock_t start, end;

    while (1) {
        // Display menu options
        printf("\n1: For manual entry of N value and array elements");
        printf("\n2: To display time taken for sorting number of elements N in the range 500 to 14500");
        printf("\n3: To exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                // Manual entry of array elements
                printf("\nEnter the number of elements: ");
                scanf("%d", &n);
                printf("\nEnter array elements: ");
                for (i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }
                start = clock(); // Start timing
                mergeSort(arr, 0, n - 1); // Sort the array
                end = clock(); // End timing
                printf("\nSorted array: ");
                printArray(arr, n); // Print sorted array
                printf("Time taken to sort %d numbers is %f Secs\n", n, ((double)(end - start)) / CLOCKS_PER_SEC);
                break;

            case 2:
                // Automated timing for various sizes of arrays
                n = 500;
                while (n <= 14500) {
                    for (i = 0; i < n; i++) {
                        arr[i] = n - i; // Initialize array in reverse order
                    }
                    start = clock(); // Start timing
                    mergeSort(arr, 0, n - 1); // Sort the array
                    // Dummy loop to create delay
                    for (j = 0; j < 500000; j++) {
                        temp = 38 / 600;
                    }
                    end = clock(); // End timing
                    printf("Time taken to sort %d numbers is %f Secs\n", n, ((double)(end - start)) / CLOCKS_PER_SEC);
                    n += 1000; // Increase the size of the array
                }
                break;

            case 3:
                // Exit the program
                exit(0);
        }
    }

    return 0;
}

