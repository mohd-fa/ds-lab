//342 Mohammed FA           Implement bubble sort

#include<stdio.h>

int main(){
	int n, temp, i, j;
	printf("Enter no of elements in array : ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter elements in array : ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	for(i=0;i<n;i++)
		for(j=0; j<n-i-1;j++)
			if (arr[j] > arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
	printf("Sorted array :\n");		
	for(i=0;i<n;i++)
		printf("%d\t",arr[i]);
	return 0;
}
