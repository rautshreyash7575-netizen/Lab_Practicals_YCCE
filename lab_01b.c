#include <stdio.h>
#include <stdbool.h>

// Binary Search Function
bool binarySearch(int *arr, int size, int key) {
    if (arr == NULL || size <= 0) {  // check for null or empty array
        printf("Invalid input.\n");
        return false;
    }

    int start = 0;
    int end = size - 1;

    while (start <= end) {
        int mid = (start + end) / 2;
        printf("Checking middle value: %d at index %d\n", arr[mid], mid);

        if (arr[mid] == key) {
            printf("Value %d found at index %d\n", key, mid);
            return true;
        }
        else if (arr[mid] < key) {
            printf("Value is greater than %d, adjusting start to index %d\n", arr[mid], mid + 1);
            start = mid + 1;
        }
        else {
            printf("Value is less than %d, adjusting end to index %d\n", arr[mid], mid - 1);
            end = mid - 1;
        }
    }

    printf("Value %d not found in the list.\n", key);
    return false;
}

int main() {
    int n, key;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Search list is empty.\n");
        return 0;
    }

    int arr[n];
    printf("Enter %d elements (in sorted order):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the value to search: ");
    scanf("%d", &key);

    // Call the binary search function
    binarySearch(arr, n, key);

    return 0;
}