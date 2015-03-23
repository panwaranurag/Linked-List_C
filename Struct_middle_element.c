#include<stdio.h>
#include<stdlib.h>
 
/* Link list node */
struct node
{
    int data;
    struct node* next;
};

/* Function to reverse the linked list */
static void reverse(struct node** head_ref)
{
    struct node* prev   = NULL;
    struct node* current = *head_ref;
    struct node* next;
    while (current != NULL)
    {
        next  = current->next;  
        current->next = prev;   
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
/*method 2 for reversing the linked list*/
void recursiveReverse(struct node** head_ref)
{
    struct node* first;
    struct node* rest;
      
    /* empty list */
    if (*head_ref == NULL)
       return;   
 
    /* suppose first = {1, 2, 3}, rest = {2, 3} */
    first = *head_ref;  
    rest  = first->next;
 
    /* List has only one node */
    if (rest == NULL)
       return;   
 
    /* reverse the rest list and put the first element at the end */
    recursiveReverse(&rest);
    first->next->next  = first;  
     
    /* tricky step -- see the diagram */
    first->next  = NULL;          
 
    /* fix the head pointer */
    *head_ref = rest;              
}

/*Function to claculate the number of count*/
int count(struct node* head, int search_element)
{
	struct node* current = head;
	int count = 0;
	while(current!=NULL)
	{
		if (current->data == search_element)
			count++;
		current = current->next;
	}
	return count;
}

 /*Delete whole linked list from head*/
 void deleteLinkedList(struct node** head_ref)
 {
 	struct node* current = *head_ref;
 	struct node* next;
	 
	 while(current!=NULL)
	 {
	 	next = current->next;
	 	free(current);
	 	current = next;
	 }
	 *head_ref = NULL;
 }
 
 
 
/*function to get the nth node from the last of a linked list*/
void printNthFromLast(struct node * head, int n)
{
	struct node *temp = head;
	int count = 0, i;
	//Count number of elements in list
	while(temp!=NULL)
	{
		temp = temp->next;
		count++;
	}
	if (n>count)
	return;
	
	temp = head;
	for( i =1; i < count-n+1; i++)
	{
		temp = temp->next;
	}
	printf("%d element from end of the linked list is %d", n, temp->data);
	return;
}
 
 
/* Function to get the middle of the linked list*/
void printMiddle(struct node *head)
{
    struct node *slow_ptr = head;
    struct node *fast_ptr = head;
 
    if (head!=NULL)
    {
        while (fast_ptr != NULL && fast_ptr->next != NULL)
        {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
        printf("The middle element is [%d]\n\n", slow_ptr->data);
    }
}

//Method 2 for finding the middle element using bit operation
/* Function to get the middle of the linked list*/
void printMiddle_method2(struct node *head)
{
    int count = 0;
    struct node *mid = head;
 
    while (head != NULL)
    {
        /* update mid, when 'count' is odd number */
        if (count & 1)
            mid = mid->next;
 
        ++count;
        head = head->next;
    }
 
    /* if empty list is provided */
    if (mid != NULL)
        printf("The middle element is [%d]\n\n", mid->data);
}
//End of method 2
 
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));
 
    /* put in the data  */
    new_node->data  = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
// A utility function to print a given linked list
void printList(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
 
/* Drier program to test above function*/
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;
    int i;
 
    for (i=10; i>0; i--)
    {
        push(&head, 2*i);
        printList(head);
        printMiddle_method2(head);
    }
 	printNthFromLast(head, 5);
 	printf("\n");
 	 push(&head, 1); 
    push(&head, 3); 
    push(&head, 1);  
    push(&head, 2);
    push(&head, 1); 
    
    printList(head);
    
     printf("count of 1 is %d", count(head, 1)); 
     
     recursiveReverse(&head);                   
     printf("\n Reversed Linked list \n");
     printList(head);
	/*printf("\n Deleting linked list");
    deleteLinkedList(&head);  
    
    printf("\n Linked list deleted ");
    
    printf("\n Linked list after deletion ");
    printList(head);
    getchar();*/
    return 0;
}
