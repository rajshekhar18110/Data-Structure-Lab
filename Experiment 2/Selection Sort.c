//Write a program to sort the elements of an array in descending order using the Selection Sort algorithm.

#include <stdio.h>

void selectionSort(int arr[], int n) {
	int i,j,max,temp;
	for (i = 0 ; i < n-1 ; i++) {
		max = i;
		for(j = i + 1; j < n; j++) {
			if (arr[j] > arr[max]) {
				max = j;
			}
		}
		if (max != i) {
			temp = arr[i];
			arr[i] = arr[max];
			arr[max] = temp;
		}
	}
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    selectionSort(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
