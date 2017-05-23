#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};


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

void delete_position(struct node** h_ref,int position)
{
	struct node *inode = *h_ref;
	struct node *prev = NULL;
	int i = 0;
	while(inode != NULL)
	{
		if(i==position)
		{
			break;
		}
		prev = inode;
		inode = inode->next;
		i++;
	}
	if(prev==NULL)
	{
		*h_ref = inode->next;
		free(inode);
		return;
	}
	
	if(inode == NULL)
	{
		printf("there is no node at %d \n",position+1);
		return;
	}
	prev->next = inode->next;
	free(inode);
}

void delete_key(struct node**h_ref,int key)
{
	struct node *inode = *h_ref;
	
	struct node *prev = NULL;
	
	while(inode !=NULL )
	{
		if(inode->data==key)
		{
			break;
		}
		prev = inode;
		inode = inode->next;
	}
	
	if(prev == NULL)
	{
		*h_ref = (*h_ref)->next;
		free(inode);
		return;
	}
	if(inode==NULL)
	{
		printf("%d is not in the linked list to delete \n",key);
		return;
	}
	prev->next = inode->next;
	free(inode);
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
	delete_key(&head,3);
	printlist(head);
	delete_position(&head,0);
	printlist(head);
	return 0;
}
