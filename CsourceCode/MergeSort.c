#include<stdio.h>

/*

Birle�me
#Divide and Conquarer
#Lineer De�ildir -> O(n*logn)

#Verileri en k���k par�aya ay�r ->divide
#Birle�tirirken S�ralama
*/



void merge(int arr[], int left[], int leftSize, int right[], int rightSize) {
    int i = 0; // left dizisinin indeksi
    int j = 0; // right dizisinin indeksi
    int k = 0; // birle�tirilen dizinin indeksi

    // Sol ve sa� dizileri kar��la�t�rarak birle�tirme i�lemi
    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // E�er sol veya sa� dizide eleman kalm��sa, geriye kalan elemanlar� birle�tirilen diziye kopyala
    while (i < leftSize) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int size) {
	
	int i;
	
    if (size < 2) {
        return; // Dizi 1 elemandan az ise s�ralamaya gerek yok, ��k�� yap
    }

    int mid = size / 2; // Dizinin orta noktas�n� bul

    // Sol ve sa� dizileri olu�tur
    int left[mid];
    int right[size - mid];

    // Diziyi ikiye b�l
    for (i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    for (i = mid; i < size; i++) {
        right[i - mid] = arr[i];
    }

    // Sol ve sa� dizileri s�rala (recursive �a�r�lar)
    mergeSort(left, mid);
    mergeSort(right, size - mid);

    // S�ralanm�� sol ve sa� dizileri birle�tir
    merge(arr, left, mid, right, size - mid);
}

int main() {
    int arr[] = {4, 7, 1, 3, 9, 2, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
	int i;
	
    printf("Siralanmamis Dizi: ");
    for ( i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    mergeSort(arr, size);

    printf("Siralanmis Dizi: ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
