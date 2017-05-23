#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void swapNodes(struct node** href, int a, int b)
{
	struct node* thead=*href;
	
	struct node* curr=NULL;
	struct node* prev=NULL;
	
	struct node* prev1=NULL;
	struct node* prev2=NULL;
	
	struct node* node1=NULL;
	struct node* node2=NULL;
	
	curr=thead;
	
	while(curr!=NULL)
	{
		if(curr->data==a)
		{
			prev1=prev;
			node1=curr;
		}
		if(curr->data==b)
		{
			prev2=prev;
			node2=curr;
		}
		prev=curr;
		curr=curr->next;	
	}
if(node1==NULL||node2==NULL)
{
	if(node1==NULL)
	{
		printf("\n %d is not present",a);
	}
	if(node2==NULL)
	{
		printf("\n %d is not present",b);
	}
	return;
}
if(prev1==NULL)//a is in the head node
{
	*href=node2;
}

if(prev2==NULL)//b is in the head node
{
	*href=node1;	
}

//this has to be done before
if(prev1!=NULL)
	prev1->next=node2;
if(prev2!=NULL)
	prev2->next=node1;
//after that to stop infinitite looping or self looping of a linked list-node
struct node *temp=node1->next;
node1->next=node2->next;
node2->next=temp;

	
}

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
 
/* Function to print nodes in a given linked list */
void printList(struct node *node)
{
    while(node != NULL)
    {
        printf("%d->", node->data);
        node = node->next;
    }
}
 
/* Druver program to test above function */
int main()
{
    struct node *start = NULL;
 
    /* The constructed linked list is:
     1->2->3->4->5->6->7 */
    push(&start, 7);
    push(&start, 6);
    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    push(&start, 1);
 
    printf("\n Linked list before calling swapNodes() ");
    printList(start);
 	 printf("NULL");
    swapNodes(&start, 1,2);
 
    printf("\n Linked list after calling swapNodes() ");
    printList(start);
    printf("NULL");
    swapNodes(&start, 1,7);
 
    printf("\n Linked list after calling swapNodes() ");
    printList(start);
 	 printf("NULL");
    return 0;
}
