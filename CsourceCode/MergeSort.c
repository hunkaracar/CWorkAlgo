#include<stdio.h>

/*

Birleþme
#Divide and Conquarer
#Lineer Deðildir -> O(n*logn)

#Verileri en küçük parçaya ayýr ->divide
#Birleþtirirken Sýralama
*/



void merge(int arr[], int left[], int leftSize, int right[], int rightSize) {
    int i = 0; // left dizisinin indeksi
    int j = 0; // right dizisinin indeksi
    int k = 0; // birleþtirilen dizinin indeksi

    // Sol ve sað dizileri karþýlaþtýrarak birleþtirme iþlemi
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

    // Eðer sol veya sað dizide eleman kalmýþsa, geriye kalan elemanlarý birleþtirilen diziye kopyala
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
        return; // Dizi 1 elemandan az ise sýralamaya gerek yok, çýkýþ yap
    }

    int mid = size / 2; // Dizinin orta noktasýný bul

    // Sol ve sað dizileri oluþtur
    int left[mid];
    int right[size - mid];

    // Diziyi ikiye böl
    for (i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    for (i = mid; i < size; i++) {
        right[i - mid] = arr[i];
    }

    // Sol ve sað dizileri sýrala (recursive çaðrýlar)
    mergeSort(left, mid);
    mergeSort(right, size - mid);

    // Sýralanmýþ sol ve sað dizileri birleþtir
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
