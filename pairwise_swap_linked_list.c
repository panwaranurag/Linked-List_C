/* Program to pairwise swap elements in a given linked list */
#include<stdlib.h>
#include<stdio.h>


struct node {
	int data;
	struct node* next;
};

void swap(int *a,  int *b);


/* Recursive function to pairwise swap elements of a linked list */
void pairWiseSwap(struct node *head)
{
  /* There must be at-least two nodes in the list */
  if(head != NULL && head->next != NULL)
  {
    /* Swap the node's data with data of next node */
    swap(&head->data, &head->next->data);
    
    /* Call pairWiseSwap() for rest of the list */
    pairWiseSwap(head->next->next);
  }  
}



void pairwiseSwap(struct node *head)
{
	struct node *temp = head;
	while(temp != NULL &&temp->next != NULL)
	{
		swap(&temp->data, &temp->next->data);
		
		temp = temp->next->next;
	}
}

/*Utility functions*/

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

//Function to add a element in the beginning of the linked list
void push(struct node** head_ref, int new_value)
{
	//Allocate the new node
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = new_value;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void printList(struct node* node)
{
	while(node != NULL)
	{
		printf("%d", node->data);
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
 
  printf("\n Linked list before calling  pairWiseSwap() ");
  printList(start);
 
  pairWiseSwap(start);
 
  printf("\n Linked list after calling  pairWiseSwap() ");
  printList(start);
 
  getchar();
  return 0;
}
