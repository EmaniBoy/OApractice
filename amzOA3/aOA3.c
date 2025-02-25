#include <stdio.h>
#include <stdlib.h>

// Comparison function for sorting in ascending order
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Function to calculate the minimum lag
long getMinDistance(int center[], int destination[], int n) {
    // Step 1: Sort both arrays
    qsort(center, n, sizeof(int), compare);
    qsort(destination, n, sizeof(int), compare);

    long total_lag = 0;

    // Step 2: Compute the absolute differences and sum them
    for (int i = 0; i < n; i++) {
        total_lag += abs(center[i] - destination[i]);
    }

    return total_lag;
}

int main() {
    // Example input
    int center[] = {1, 2, 2};
    int destination[] = {5, 2, 4};
    int n = sizeof(center) / sizeof(center[0]);

    // Compute and print the minimum lag
    printf("Minimum total lag: %ld\n", getMinDistance(center, destination, n));

    return 0;
}
