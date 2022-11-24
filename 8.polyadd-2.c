//342 Mohammed FA           Implement polynomial addition(linked list)

#include <stdio.h>
#include <stdlib.h>


int main(){

	struct Term{
		int x;
		int y;
		float coeff;
		struct Term *next;
	};

	void display(struct Term *head){
		struct Term *ptr = head;
		if (ptr == NULL)
			printf("0\n\n");
		else{
			while(ptr != NULL){
				printf(" %0.2fx^%dy^%d +",ptr->coeff,ptr->x,ptr->y);
				ptr = ptr->next;
			}
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

	int n1,n2,i,c,x,y;
	char o;

	struct Term *ahead=NULL, *bhead=NULL, *result=NULL, *new, *aptr, *bptr, *rptr;
	printf("Enter no of terms in polinomial 1:");
	scanf("%d",&n1);
	for (i=0; i<n1; i++){
		new = (struct Term*)malloc(sizeof(struct Term));
		printf("Enter the coeff:");
		scanf("%d",&c);
		new->coeff = c;
		printf("Enter the x exponent:");
		scanf("%d",&x);
		new->x = x;
		printf("Enter the y exponent:");
		scanf("%d",&y);
		new->y = y;
		new->next = NULL;
		if(ahead == NULL){
			ahead = new;
			aptr =ahead;
		}
		else{
			aptr->next = new;
			aptr = aptr->next;
		}
	}
	
	printf("\nPolynomial A :\n");
	display(ahead);
	
	printf("Enter no of terms in polinomial 2:");
	scanf("%d",&n2);
	for (i=0; i<n2; i++){
		new = (struct Term*)malloc(sizeof(struct Term));
		printf("Enter the coeff:");
		scanf("%d",&c);
		new->coeff = c;
		printf("Enter the x exponent:");
		scanf("%d",&x);
		new->x = x;
		printf("Enter the y exponent:");
		scanf("%d",&y);
		new->y = y;
		new->next = NULL;
		if(bhead == NULL){
			bhead = new;
			bptr =bhead;
		}
		else{
			bptr->next = new;
			bptr = bptr->next;
		}
	}

	printf("\nPolynomial B :\n");
	display(bhead);

	aptr=ahead;
	bptr=bhead;
	rptr==result;
	while(aptr!=NULL && bptr!=NULL){
		if (aptr->x == bptr->x){
			if (aptr->y == bptr->y){
				new = (struct Term*)malloc(sizeof(struct Term));
				new->x = aptr->x;
				new->y = aptr->y;
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
			else if (aptr->y > bptr->y){
				new = (struct Term*)malloc(sizeof(struct Term));
				new->x = aptr->x;
				new->y = aptr->y;
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
				new->x = bptr->x;
				new->y = bptr->y;
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
		else if (aptr->x > bptr->x){
			new = (struct Term*)malloc(sizeof(struct Term));
			new->x = aptr->x;
			new->y = aptr->y;
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
			new->x = bptr->x;
			new->y = bptr->y;
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
		new->x = aptr->x;
		new->y = aptr->y;
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
		new->x = bptr->x;
		new->y = bptr->y;
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


