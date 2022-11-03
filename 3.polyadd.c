//342 Mohammed FA           Implement polynomial addition

#include<stdio.h>

int main(){
	int d1,d2,temp,tempco,n1=0,n2=0,n3=0,i=0,j=0,k=0;
	struct term{ 
		int exp;
		float coeff;
	};
	struct term poly1[10], poly2[10],sum[10];
	printf("Enter the degree of polynomial 1 :");
	scanf("%d",&d1);
	n1=0;
	for (temp=d1; temp>=0; temp--){
		printf("Enter the coeff of at %dth degree term:",temp);
		scanf("%d",&tempco);
		if (tempco != 0){
			poly1[n1].exp = temp;
			poly1[n1].coeff = tempco;
			n1++;
		}
	}
	printf("Enter the degree of polynomial 2 :");
	scanf("%d",&d2);
	n2=0;
	for (temp=d2; temp>=0; temp--){
		printf("Enter the coeff of at %dth degree term:",temp);
		scanf("%d",&tempco);
		if (tempco != 0){
			poly2[n2].exp = temp;
			poly2[n2].coeff = tempco;
			n2++;
		}
	}
	while(i<n1&&j<n2){
		if (poly1[i].exp == poly2[j].exp){
			sum[k].exp = poly1[i].exp;
			sum[k].coeff = poly1[i].coeff + poly2[j].coeff;
			k++,i++,j++;
		}
		else if (poly1[i].exp > poly2[j].exp){
			sum[k].exp = poly1[i].exp;
			sum[k].coeff = poly1[i].coeff;
			k++,i++;
		}
		else {
			sum[k].exp = poly2[j].exp;
			sum[k].coeff = poly2[j].coeff;
			k++,j++;
		}
	}
	while(i<n1){
		sum[k].exp = poly1[i].exp;
		sum[k].coeff = poly1[i].coeff;
		k++,i++;
	}
	while(j<n2){
		sum[k].exp = poly2[j].exp;
		sum[k].coeff = poly2[j].coeff;
		k++,j++;
	}
	printf("Sum :\n");
	printf("exp\t\tcoeff\n");
	for(i=0;i<k;i++)
		printf("%d\t\t%f\n",sum[i].exp,sum[i].coeff);
	return 0;
}
