//342 Mohammed FA           Implement polynomial addition

#include <stdio.h>
#include <stdlib.h>


int main(){

    struct Term{
        int exp;
        float coeff;
        struct Term *next;
    };

    void display(struct Term *head){
        struct Term *ptr = head->next;
        if (ptr == NULL)
            printf("%d\t\t%f\n",0,0);
        else
            printf("exp\t\tcoeff\n");
            while(ptr != NULL){
                printf("%d\t\t%f\n",ptr->exp,ptr->coeff);
                ptr = ptr->next;
            }
    }

    void freell(){
        struct Term *ptr = head->next;
        if (ptr == NULL)
            printf("\nLL freed.\n");
        else
            while(ptr != NULL){
                temp = ptr;
                ptr = ptr->next;
                free(temp);
                printf("\nLL freed.\n");
            }
    }
    
	int d1,d2,temp,tempco;
    char o;

    struct Term *ahead, *bhead, *sum, *new, *aptr, *bptr, *sptr;
	printf("Enter the degree of polynomial 1 :");
	scanf("%d",&d1);
    ahead = (struct Term*)malloc(sizeof(struct Term));
    ahead->exp = 0;
    ahead->coeff = 0;
    ahead->next = NULL;
    aptr = ahead;
	for (temp=d1; temp>=0; temp--){
		printf("Enter the coeff of at %dth degree term:",temp);
		scanf("%d",&tempco);
		if (tempco != 0){
			new = (struct Term*)malloc(sizeof(struct Term));
			new->exp = temp;
			new->coeff = tempco;
            new->next = NULL;
            aptr->next=new;
			aptr=aptr->next;
		}
	}

	printf("\nPolynomial A :\n");
    display(ahead);

	printf("Enter the degree of polynomial 2 :");
	scanf("%d",&d2);
    bhead = (struct Term*)malloc(sizeof(struct Term));
    bhead->exp = 0;
    bhead->coeff = 0;
    bhead->next = NULL;
    bptr = bhead;
	for (temp=d2; temp>=0; temp--){
		printf("Enter the coeff of at %dth degree term:",temp);
		scanf("%d",&tempco);
		if (tempco != 0){
			new = (struct Term*)malloc(sizeof(struct Term));
			new->exp = temp;
			new->coeff = tempco;
            new->next = NULL;
            bptr->next=new;
			bptr=bptr->next;
		}
	}

	printf("\nPolynomial B :\n");
    display(bhead);

	printf("\nEnter the polynomial opreation '+' or '*':");
	scanf("%c",&o);

    aptr=ahead->next;
    bptr=bhead->next;
    sum = (struct Term*)malloc(sizeof(struct Term));
    sum->exp = 0;
    sum->coeff = 0;
    sum->next = NULL;
    sptr=sum;

    switch (o){
        case '+':
            while(aptr!=NULL && bptr!=NULL){
                if (aptr->exp == bptr->exp){
                    new = (struct Term*)malloc(sizeof(struct Term));
                    new->exp = aptr->exp;
                    new->coeff = aptr->coeff + bptr->coeff;
                    new->next = NULL;
                    sptr->next = new;
                    sptr = sptr->next;
                    aptr = aptr->next;
                    bptr = bptr->next;
                }
                else if (aptr->exp > bptr->exp){
                    new = (struct Term*)malloc(sizeof(struct Term));
                    new->exp = aptr->exp;
                    new->coeff = aptr->coeff;
                    new->next = NULL;
                    sptr->next = new;
                    sptr = sptr->next;
                    aptr = aptr->next;
                }
                else {
                    new = (struct Term*)malloc(sizeof(struct Term));
                    new->exp = bptr->exp;
                    new->coeff = bptr->coeff;
                    new->next = NULL;
                    sptr->next = new;
                    sptr = sptr->next;
                    bptr = bptr->next;
                }
            }
            while(aptr!=NULL){
                new = (struct Term*)malloc(sizeof(struct Term));
                new->exp = aptr->exp;
                new->coeff = aptr->coeff;
                new->next = NULL;
                sptr->next = new;
                sptr = sptr->next;
                aptr = aptr->next;
            }
            while(bptr!=NULL){
                new = (struct Term*)malloc(sizeof(struct Term));
                new->exp = bptr->exp;
                new->coeff = bptr->coeff;
                new->next = NULL;
                sptr->next = new;
                sptr = sptr->next;
                bptr = bptr->next;
            }
            break;
        default:
            printf("Invalid operation.");
            return 0;
    }

    printf("\nResult:\n");
    display(sum);
    
    freell(ahead);
    freell(bhead);
    freell(sum);
}


