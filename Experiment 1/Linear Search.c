//Write a C program to check whether a given element is present in an array of elements using linear search.
//The program should prompt the user to enter the size of the array, the elements of the array, and the element to search for.

#include <stdio.h>

int main() {
    int n, key, i, found = 0;
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &key);

    for(i=0;i<n;i++){
		if(arr[i] == key){
			found = 1;
			break;
		}
	}
	if(found==1){
		printf("Found at position %d\n", i);
	}else{
		printf("%d not Found\n", key);
	}
}
