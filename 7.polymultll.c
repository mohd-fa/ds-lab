//342 Mohammed FA           Implement polynomial multiplication

#include <stdio.h>
#include <stdlib.h>


int main(){

	struct Term{
		int exp;
		float coeff;
		struct Term *next;
	};

	void display(struct Term *head){
		struct Term *ptr = head;
		if (ptr == NULL)
			printf("0\n\n");
		else{
			while(ptr != NULL && ptr->exp != 0){
				printf(" %0.2fx^%d +",ptr->coeff,ptr->exp);
				ptr = ptr->next;
			}
			if(ptr->exp == 0)
				printf(" %0.2f= 0\n\n",ptr->coeff);
			else
				printf(" = 0\n\n",ptr->coeff);
		}
	}

	void freell(struct Term *head){
		struct Term *ptr = head, *temp;
		while(ptr != NULL){
			temp = ptr;
			ptr = ptr->next;
			free(temp);	
		}
		printf("\nLL freed.\n");
	}

	int d1,d2,temp,tempco,tempexp;
	char o;

	struct Term *ahead=NULL, *bhead=NULL, *result=NULL, *new, *aptr, *bptr, *rptr, *prerptr;
	printf("Enter the degree of polynomial 1 :");
	scanf("%d",&d1);
	for (temp=d1; temp>=0; temp--){
		printf("Enter the coeff of at %dth degree term:",temp);
		scanf("%d",&tempco);
		if (tempco != 0){
			if (ahead == NULL){
				new = (struct Term*)malloc(sizeof(struct Term));
				new->exp = temp;
				new->coeff = tempco;
				new->next = NULL;
				ahead=new;
				aptr=ahead;
				
			}
			else{
				new = (struct Term*)malloc(sizeof(struct Term));
				new->exp = temp;
				new->coeff = tempco;
				new->next = NULL;
				aptr->next=new;
				aptr=aptr->next;
			}
		}
	}

	printf("\nPolynomial A :\n");
	display(ahead);

	printf("Enter the degree of polynomial 2 :");
	scanf("%d",&d2);
	for (temp=d2; temp>=0; temp--){
		printf("Enter the coeff of at %dth degree term:",temp);
		scanf("%d",&tempco);
		if (tempco != 0){
			if (bhead == NULL){
				new = (struct Term*)malloc(sizeof(struct Term));
				new->exp = temp;
				new->coeff = tempco;
				new->next = NULL;
				bhead=new;
				bptr=bhead;
			}
			else{
				new = (struct Term*)malloc(sizeof(struct Term));
				new->exp = temp;
				new->coeff = tempco;
				new->next = NULL;
				bptr->next=new;
				bptr=bptr->next;
			}
		}
	}

	printf("\nPolynomial B :\n");
	display(bhead);

	aptr=ahead;
	while(aptr!=NULL){
		bptr=bhead;
		while(bptr!=NULL){
			tempexp = aptr->exp + bptr->exp;
			rptr = result;
			if (rptr == NULL){
				new = (struct Term*)malloc(sizeof(struct Term));
				new->exp = tempexp;
				new->coeff = aptr->coeff * bptr->coeff;
				new->next = NULL;
				result=new;
			}
			else{
				while(rptr->next != NULL && rptr->exp > tempexp){
					prerptr = rptr;
					rptr = rptr->next;
				}
				if(rptr->exp == tempexp){
					rptr->coeff += aptr->coeff * bptr->coeff;
				}
				else if(rptr->exp < tempexp){
					new = (struct Term*)malloc(sizeof(struct Term));
					new->exp = tempexp;
					new->coeff = aptr->coeff * bptr->coeff;
					new->next = rptr;
					prerptr->next = new;
					
				}
				else{
					new = (struct Term*)malloc(sizeof(struct Term));
					new->exp = tempexp;
					new->coeff = aptr->coeff * bptr->coeff;
					new->next = NULL;
					rptr->next = new;
				}
			}
			bptr = bptr->next;
		}
		aptr = aptr->next;
	}
	printf("\nResult:\n");
	display(result);

	freell(ahead);
	freell(bhead);
	freell(result);
}


