#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// QuickSort function
void quickSort(int arr[], int s, int e) {
    if (s >= e) return;
    int low = s;
    int high = e;
    int m = low + (high - low) / 2;
    int pivot = arr[m];
    while (low <= high) {
        while (arr[low] < pivot) low++;
        while (arr[high] > pivot) high--;
        if (low <= high) {
            // Swap arr[low] and arr[high]
            int t = arr[low];
            arr[low] = arr[high];
            arr[high] = t;
            low++;
            high--;
        }
    }
    // Recursively sort the two halves
    quickSort(arr, s, high);
    quickSort(arr, low, e);
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
                quickSort(arr, 0, n - 1); // Sort the array
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
                    quickSort(arr, 0, n - 1); // Sort the array
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
