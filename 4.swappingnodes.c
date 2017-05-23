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
	while(pnode!=NULL)
	{
		printf("%d->",pnode->data);
		pnode = pnode->next;
	}
	printf("\n");
}

void swap_nodes(struct node** h_ref,int key1,int key2)
{
	struct node* inode = *h_ref;
	if(inode == NULL)
	{
		return;
	}
	struct node* c1 = NULL;
	struct node* c2 = NULL;
	
	struct node* p1 = NULL;
	struct node* p2 = NULL;
	
	struct node* prev = NULL;
	while(inode != NULL)
	{
		if(inode->data == key1)
		{
			p1 = prev;
			c1 = inode;
		}
		
		if(inode->data == key2)
		{
			p2 = prev;
			c2 = inode;
		}
		
		prev = inode;
		inode = inode->next;
	}
	if(p1 == NULL)
	{
		*h_ref = c2;
	}
	if(p2 == NULL)
	{
		*h_ref = c1;
	}
	if(p1!=NULL)
	p1->next = c2;
	if(p2!=NULL)
	p2->next = c1;
	struct node *temp = NULL;
	temp = c1->next;
	c1->next = c2->next;
	c2->next = temp;
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
	swap_nodes(&head,8,9);
	printlist(head);
	return 0;
}
