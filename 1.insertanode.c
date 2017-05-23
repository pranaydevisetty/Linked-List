#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* next;
};
void insert_end(struct node**h_ref,int new_data)
{
	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	new_node->data = new_data;
	new_node->next = NULL;
	struct node* i_node = *h_ref;
	if(*h_ref == NULL)
	{
		*h_ref = new_node;
		return;	
	}
	
	while(i_node->next!=NULL)
	{
		i_node = i_node->next;
	}
	
	i_node->next = new_node;
}

void insert_begin(struct node**h_ref, int new_data)
{
	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	new_node->data = new_data;
	new_node->next = *h_ref;
    *h_ref = new_node;
	
}

void insert_middle(struct node*prev,int new_data)
{
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	
	if(prev == NULL)
	{
		printf("previous node cannot be NULL");
		return;
	}
	new_node->data = new_data;
	new_node->next = prev->next;
	prev->next = new_node;
}

void printlist(struct node *h_ref)
{
	struct node* pnode = h_ref;
	if(pnode==NULL)
	{
		printf("LL is Empty");
	}
	while(pnode!=NULL)
	{
		printf("%d->",pnode->data);
		pnode = pnode->next;
	}
	printf("\n");
}
int main()
{
	struct node* head = NULL;
	insert_end(&head,3);
	insert_end(&head,4);
	insert_end(&head,5);
	insert_end(&head,6);
	insert_end(&head,7);
	insert_end(&head,8);
	insert_end(&head,9);
	printlist(head);
	int key;
	struct node* prevnode = head;
	printf("insert the position a node has to be inserted with starting index as 0:");
	scanf("%d",&key);
	int i=0;
	while(i<key-1)
	{
		//printf("%d->",prevnode->data);
		prevnode = prevnode->next;
		i++;
	}
	insert_middle(prevnode,10);
	
	printlist(head);
	return 0;
}
