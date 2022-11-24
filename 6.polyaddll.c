//342 Mohammed FA           Implement polynomial addition(linked list)

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
			while(ptr->next != NULL){
				printf(" %0.2fx^%d +",ptr->coeff,ptr->exp);
				ptr = ptr->next;
			}
			printf(" %0.2f=0\n\n",ptr->coeff,ptr->exp);
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

	int d1,d2,temp,tempco;
	char o;

	struct Term *ahead=NULL, *bhead=NULL, *result=NULL, *new, *aptr, *bptr, *rptr;
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
	bptr=bhead;
	rptr==result;
	while(aptr!=NULL && bptr!=NULL){
		if (aptr->exp == bptr->exp){
			
			new = (struct Term*)malloc(sizeof(struct Term));
			new->exp = aptr->exp;
			new->coeff = aptr->coeff + bptr->coeff;
			new->next = NULL;
			if (result == NULL){
				result=new;
				rptr = result;
			}
			else{
				rptr->next = new;
				rptr = rptr->next;
			}
			aptr = aptr->next;
			bptr = bptr->next;
		}
		else if (aptr->exp > bptr->exp){
			new = (struct Term*)malloc(sizeof(struct Term));
			new->exp = aptr->exp;
			new->coeff = aptr->coeff;
			new->next = NULL;
			if (result == NULL){
				result=new;
				rptr = result;
			}
			else{
				rptr->next = new;
				rptr = rptr->next;
			}
			aptr = aptr->next;
		}
		else {
			new = (struct Term*)malloc(sizeof(struct Term));
			new->exp = bptr->exp;
			new->coeff = bptr->coeff;
			new->next = NULL;
			if (result == NULL){
				result=new;
				rptr = result;
			}
			else{
				rptr->next = new;
				rptr = rptr->next;
			}
			bptr = bptr->next;
		}
	}
	while(aptr!=NULL){
		new = (struct Term*)malloc(sizeof(struct Term));
		new->exp = aptr->exp;
		new->coeff = aptr->coeff;
		new->next = NULL;
		if (result == NULL){
			result=new;
			rptr = result;
		}
		else{
			rptr->next = new;
			rptr = rptr->next;
		}
		aptr = aptr->next;
	}
	while(bptr!=NULL){
		new = (struct Term*)malloc(sizeof(struct Term));
		new->exp = bptr->exp;
		new->coeff = bptr->coeff;
		new->next = NULL;
		if (result == NULL){
			result=new;
			rptr = result;
		}
		else{
			rptr->next = new;
			rptr = rptr->next;
		}
		bptr = bptr->next;
	}

	printf("\nResult:\n");
	display(result);

	freell(ahead);
	freell(bhead);
	freell(result);
}


