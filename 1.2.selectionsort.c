//342 Mohammed FA           Implement selection sort

#include<stdio.h>

int main(){
	int n, temp, i, j,min;
	printf("Enter no of elements in array : ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter elements in array : ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	for(i=0;i<n;i++){
		min = i;
		for(j=i+1;j<n;j++)
			if (arr[j] < arr[min])
				min=j;
		if (i != min){
			temp = arr[min];
			arr[min] = arr[i];
			arr[i] = temp;
		}
	}
	printf("Sorted array :\n");		
	for(i=0;i<n;i++)
		printf("%d\t",arr[i]);
	return 0;
}
