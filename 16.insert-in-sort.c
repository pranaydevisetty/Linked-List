//insert node according to the sort order

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

void insert_sort(struct node** h_ref, int data)
{
	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	new_node->data = data;
	struct node* inode = *h_ref;
	
	struct node* prev = NULL;
	if(*h_ref == NULL)
	{
		*h_ref = new_node;
		new_node->next = NULL;
		return;
	}
	while(inode!=NULL && inode->data < data )
	{
		prev = inode;
		inode = inode->next;
	}
	if(prev == NULL)
	{
		new_node->next = *h_ref;
		*h_ref = new_node;
	}
	else
	{
		new_node->next = prev->next;
		prev->next = new_node;
	}
	//printf("sas");
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
	insert_sort(&head,1);
	insert_sort(&head,2);
	insert_sort(&head,0);
	insert_sort(&head,11);
	insert_sort(&head,10);
	insert_sort(&head,-1);
	
	printlist(head);
	return 0;
}
