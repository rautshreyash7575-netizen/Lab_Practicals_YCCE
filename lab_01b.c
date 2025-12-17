#include <stdio.h>

int binarySearch(int arr[], int n, int key) {
    int start = 0, end = n - 1;

    while (start <= end) {
        int mid = (start + end) / 2;

        if (arr[mid] == key)
            return 1;
        else if (arr[mid] < key)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return 0;
}

int main() {
    int n, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter value to search: ");
    scanf("%d", &key);

    if (binarySearch(arr, n, key))
        printf("Found");
    else
        printf("Not Found");

    return 0;
}
