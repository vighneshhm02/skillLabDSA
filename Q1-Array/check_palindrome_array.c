#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int is_palindrome(int n) {
    int reversed = 0, temp = n;
    while (temp > 0) {
        reversed = reversed * 10 + temp % 10;
        temp /= 10;
    }
    return reversed == n;
}


bool all_elements_palindrome(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (!is_palindrome(arr[i]))
            return false; 
    }
    return true; 
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf(all_elements_palindrome(arr, n));
    return 0;
}
