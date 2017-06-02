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

void delalt(struct node* head)
{
	if(head == NULL || head->next == NULL)
	{
		return;
	}
	
	struct node* inode = head;
	struct node* prev = NULL;
	
	while(inode!=NULL&&inode->next!=NULL)
	{
		prev = inode->next;
		inode->next = inode->next->next;
		free(prev);
		inode = inode->next;	
	}
}
int main()
{
	struct node* head = NULL;
	insert_end(&head,1);
	insert_end(&head,2);
	insert_end(&head,3);
	insert_end(&head,4);
	//insert_end(&head,5);
	//insert_end(&head,8);
	//insert_end(&head,9);
	printlist(head);
	delalt(head);
	printlist(head);
	return 0;
}
