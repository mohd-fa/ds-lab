//342 Mohammed FA           Implement linear search

#include<stdio.h>

int main(){
	int n, temp, i, k, flag =0;
	printf("Enter no of elements in array : ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter elements in array : ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("Enter element to search : ");
	scanf("%d",&k);
	for(i=0;i<n;i++)
		if (arr[i]==k){
			printf("Element is found at %d index",i);
			flag = 1;
		}
	if (flag == 0){
		printf("Element not found.");
	}
	return 0;
}

