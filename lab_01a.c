#include <stdio.h>

int main() {
    int n, i;
    int sumEven = 0, sumOdd = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++) {
        if ((i + 1) % 2 == 0)   
            sumEven += arr[i];
        else                                
        sumOdd += arr[i];
    }

    printf("Sum of numbers at odd positions: %d\n", sumOdd);
    printf("Sum of numbers at even positions: %d\n", sumEven);

    return 0;
}