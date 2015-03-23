#include <stdlib.h>
#include <stdio.h>

struct node {
	int data;
	struct node* next;
};

void moveToFront(struct node **head_ref)
{
	if(*head_ref == NULL  || (*head_ref)->next == NULL)
	return;
	// initialize the last and second last pointer 
	struct node* secLast = NULL;
	struct node* last = (*head_ref);
	while(last->next != NULL)
	{
		secLast = last;
		last = secLast->next;
	}
	
	secLast->next = NULL;
	last->next = *head_ref;
	*head_ref = last;
}

void push(struct node** head_ref, int new_data)
{
	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	
	new_node->data = new_data;
	new_node->next = *head_ref;
	*head_ref = new_node;
}

void printList(struct node * node)
{
	while(node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	
	}
}

/* Druver program to test above function */
int main()
{
  struct node *start = NULL;   
 
  /* The constructed linked list is:
   1->2->3->4->5 */
  push(&start, 5);
  push(&start, 4);
  push(&start, 3);
  push(&start, 2);
  push(&start, 1);
 
  printf("\n Linked list before moving last to front ");
  printList(start);
 
  moveToFront(&start);
 
  printf("\n Linked list after removing last to front ");
  printList(start);
 
  getchar();
}      
