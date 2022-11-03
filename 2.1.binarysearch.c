//342 Mohammed FA           Implement binary search

#include<stdio.h>

int main(){
	int n, temp, i,j, k, first = 0,last,mid;
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
	printf("\nEnter element to search : ");
	scanf("%d",&k);
	last = n-1;
	while(first<=last){
		mid = (first +last)/2;
		if(arr[mid] == k){
			printf("Element is found at %d index",mid);
			return 0;
		}
		else if(arr[mid] > k)
			last = mid -1;
		else
			first = mid +1;
	}
	printf("Element not found.");
	return 0;
}

