//342 Mohammed FA           Implement insertion sort

#include<stdio.h>

int main(){
	int n, temp, i, j;
	printf("Enter no of elements in array : ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter elements in array : ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	for(i=1;i<n;i++){
		temp = arr[i];
		for(j=i-1; j>=0 && arr[j]>temp; j--){
			arr[j+1] = arr[j];
			arr[j] = temp;
		}
	}
	printf("Sorted array :\n");		
	for(i=0;i<n;i++)
		printf("%d\t",arr[i]);
	return 0;
}

