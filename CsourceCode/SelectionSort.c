#include <stdio.h>

void SelectionSort(int arr[], int size) {
    int i, j, key, temp;
    for (i = 0; i < size; i++) {
        key = i;
        for (j = i + 1; j < size; j++) {
            if (arr[key] > arr[j]) {
                key = j;
            }
        }
        temp = arr[key];
        arr[key] = arr[i];
        arr[i] = temp;
    }
}

int main() {
	
    printf("Siralanmis Dizi: ");
    int arr[] = {3, 6, 1, 0, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    SelectionSort(arr, size);
	
	int i;
	
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

