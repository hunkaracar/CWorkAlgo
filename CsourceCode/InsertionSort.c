#include<stdio.h>

void InsertionSort(int arr[],int size){
	int i,j, key, temp;
	for (i=1;i<size;i++){
		key = arr[i];
		j = i-1;
		while(arr[j]>key && j>=0){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1]=key;
	}
	
}



int main(){
	
	int arr[] = {4,6,7,2,1,12};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	printf("Siralanmis Dizi: ");
	InsertionSort(arr,size);
	int i;
	
	for(i=0;i<size;i++){
		printf("%d ",arr[i]);
	} 
	
	return 0;
}
