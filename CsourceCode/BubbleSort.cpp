#include<stdio.h>
#include<stdlib.h>


void bubbleSort(int arr[], int size){
	
	for (int i=0; i<size-1;i++){
		for (int j=0; j<size-1-i;j++){
			
			if (arr[j]>arr[j+1]){
				
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	
}


int main(){
	
	int arr[] = {4,3,7,1,9};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	bubbleSort(arr,size);
	
	printf("Siralanmis Dizi: ");
	for (int i=0; i<size;i++){
		printf("%d ",arr[i]);
	}
	
	return 0;
}



