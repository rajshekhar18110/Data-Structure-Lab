//Write a C program that performs a binary search to find the position of the given integer in the array.//

#include <stdio.h>

int main() {
    int n, x;

    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &x);

    int left = 0, right = n - 1;
    int result = -1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == x) {
            result = mid;
            break;
        } else if (arr[mid] > x) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    if (result != -1)
        printf("Element Found at index %d\n", result);
    else
        printf("Element not Found\n");

    return 0;
}
