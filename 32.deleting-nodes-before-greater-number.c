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

void remnext(struct node** h_ref)
{
	struct node* inode = *h_ref;
	struct node* temp = NULL;
	struct node* prev = NULL;
	while(inode!=NULL&&inode->next!=NULL)
	{
		if(inode->data<inode->next->data)
		{
			if(inode==*h_ref)
			{
				temp = inode;
				*h_ref = inode->next;
				//inode = inode->next;
				//inode  = temp->next;
				
			}
			else
			{
				temp = inode;
				prev->next = inode->next;
				//inode = inode->next;
				//inode = temp->next;
				//free(temp);
				//temp = NULL;
			}
		}
		//printf("inode-%d\n",inode->data);
		prev = inode;
		inode = inode->next;
		free(temp);
		temp = NULL;
	}
}
int main()
{
	struct node* head = NULL;
	insert_end(&head,18);
	insert_end(&head,15);
	insert_end(&head,10);
	insert_end(&head,11);
	insert_end(&head,5);
	insert_end(&head,6);
	insert_end(&head,2);
	insert_end(&head,3);
	printlist(head);
	remnext(&head);
	printlist(head);
	return 0;
}
