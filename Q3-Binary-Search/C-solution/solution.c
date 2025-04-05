#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int canPlaceCows(int stalls[], int n, int cows, int minDist) {
    int count = 1, lastPos = stalls[0];

    for (int i = 1; i < n; i++) {
        if (stalls[i] - lastPos >= minDist) {
            count++;
            lastPos = stalls[i];
            if (count == cows) return 1;
        }
    }
    return 0;
}

int aggressiveCows(int stalls[], int n, int cows) {
    qsort(stalls, n, sizeof(int), compare);
    int low = 1, high = stalls[n - 1] - stalls[0], best = 0;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (canPlaceCows(stalls, n, cows, mid)) {
            best = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return best;
}

int main() {
    int stalls[] = {1, 2, 8, 4, 9};
    int n = sizeof(stalls) / sizeof(stalls[0]);
    int cows = 3;

    printf("%d\n", aggressiveCows(stalls, n, cows));  // Output: 3
    return 0;
}
