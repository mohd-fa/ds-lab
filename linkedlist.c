//342 Mohammed FA           Implement linkedlist functions

#include<stdio.h>
#include<stdlib.h>

struct Node{ 
	int value;
	struct Node* next;
};
	
int main(){
	struct Node *head = NULL, *new, *ptr, *preptr;
	int o,value;
	int i=1;
	int x;
	while(i==1){
		printf("\n0-display\n1-add element to begining\n2-add element to end\n3-add elem at specific pos\n4-delete element form begining\n5-delete element from end\n6-delete elem at specific pos\n9-exit program\nEnter option from list :");
		
		scanf("%d",&o);
		//insert at beg
		switch(o){
		case 0:
			// view
			ptr = head;
			if (ptr == NULL)
				printf("\nNo element in list\n");
			else
				while(ptr != NULL){
					printf("%d\t", ptr->value);
					ptr = ptr->next;
				}
			printf("\n");
			break;
		case 1:
			//add beg
			printf("\nEnter value to add :");
			scanf("%d",&value);
			new = (struct Node*)malloc(sizeof(struct Node));
			new->value = value;
			new->next = head;
			head = new;
			printf("\nElement added to begining of linked list\n");
			break;
		case 2:
			//add end
			printf("\nEnter value to add :");
			scanf("%d",&value);
			new = (struct Node*)malloc(sizeof(struct Node));
			new->value = value;
			new->next = NULL;
			ptr = head;
			while(ptr->next != NULL)
				ptr = ptr->next;
			ptr->next = new;
			printf("\nElement added to end of linked list\n");
			break;
		case 3:
			//todo add elem at random pos 
			if(head == NULL){
				printf("\nEntered elements not in linked list\n");
			}
			else{
				ptr = head;
				printf("\nEntered elements to search:\n");
				scanf("%d",&x);
				while(ptr->next != NULL && ptr->value != x)
					ptr = ptr->next;
				if (ptr->value = x){
					printf("\nEnter value to add :");
					scanf("%d",&value);
					new = (struct Node*)malloc(sizeof(struct Node));
					new->value = value;
					new->next = ptr->next;
					ptr->next = new;
					printf("\nElement added after element with value %d\n",x);
				}
				else
					printf("\nEntered elements not in linked list\n");
			}
			break;
		case 4:
			//remove beg
			if(head != NULL){
				ptr = head;
				head = head->next;
				free(ptr);
				printf("\nElement deleted from begining of linked list\n");
			}
			else
				printf("\nNo elements in linked list\n");
			break;
		case 5:
			//remove end
			if(head == NULL){
				printf("\nNo elements in linked list\n");
			}
			else{
				ptr = head;
				while(ptr->next->next != NULL)
					ptr = ptr->next;
				free(ptr->next);
				ptr->next = NULL;
				printf("\nElement deleted from begining of linked list\n");
			}
			break;
		case 6:
			//remove from specific position
			if(head == NULL){
				printf("\nNo elements in linked list\n");
			}
			else{
				ptr = head;
				printf("\nEntered elements to delete:\n");
				scanf("%d",&x);
				while(ptr->next != NULL && ptr->value != x){
					preptr = ptr;
					ptr = ptr->next;
				}
				if (ptr->value = x){
					preptr->next = ptr->next;
					free(ptr);
					printf("\nElement with value %d deleted\n",x);
				}
				else
					printf("\nEntered elements not in linked list\n");
			}
			break;
		case 9:
			while(head != NULL){
				ptr = head;
				head = head->next;
				free(ptr);
			}
			printf("\nProgram exitted");
			return 0;
		default:
			printf("\nError");
		}
	}
}
