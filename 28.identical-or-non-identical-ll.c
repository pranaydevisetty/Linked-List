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
int identical(struct node* node1,struct node* node2)
{
	if(node1==NULL&&node2==NULL)
		return 1;
	if(node1!=NULL&&node2!=NULL)
		return identical(node1->next,node2->next)&&(node1->data==node2->data);
	return 0;
}
int main()
{
	struct node* head = NULL;
	struct node* head2 = NULL;
	insert_end(&head,6);
	insert_end(&head,7);
	insert_end(&head,8);
	insert_end(&head2,6);
	insert_end(&head2,7);
	insert_end(&head2,8);
	//insert_end(&head2,9);
	printlist(head);
	printlist(head2);
	if(identical(head,head2))
	{
		printf("IDENTICAL\n");
	}
	else
	{
		printf("NON-IDENTICAL\n");
	}
	return 0;
}
