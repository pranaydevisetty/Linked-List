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

void printlist(struct node *h_ref)
{
	struct node* pnode = h_ref;
	if(pnode == NULL)
	{
		printf("LL is empty");
	}
	while(pnode!=NULL)
	{
		printf("%d->",pnode->data);
		pnode = pnode->next;
	}
	printf("\n");
}
void printreverse(struct node* h)
{	
	if(h==NULL)
	{
		return;
	}
	
	printreverse(h->next);
	
	printf("%d->",h->data);
}
int main()
{
	struct node* head = NULL;
	int key;
	insert_end(&head,3);
	insert_end(&head,4);
	insert_end(&head,5);
	insert_end(&head,6);
	insert_end(&head,7);
	insert_end(&head,8);
	insert_end(&head,9);
	printlist(head);
	printreverse(head);
	return 0;
}
