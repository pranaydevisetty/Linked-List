#include <stdio.h>
#include <stdlib.h>

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

removeduplicates(struct node* node1)
{
	struct node* ptr1 = node1;
	struct node* ptr2 = node1;
	struct node* inode = NULL;
	struct node* prev1 = NULL;
	while(ptr1!=NULL)
	{
		ptr2  = ptr1;
		while(ptr2->next!=NULL)
		{
			if(ptr1->data == ptr2->next->data)
			{
				inode = ptr2->next->next;
				free(ptr2->next);
				ptr2->next = inode;
			}
			else
				ptr2 = ptr2->next;
		}
		//printf("ptr1->%d\n",ptr1->data);
		ptr1 = ptr1->next;
	}
	
	
}

int main()
{
	struct node* head = NULL;
	int key;
	insert_end(&head,3);
	insert_end(&head,3);
	insert_end(&head,6);
	insert_end(&head,6);
	insert_end(&head,3);
	insert_end(&head,6);
	insert_end(&head,7);
	insert_end(&head,8);
	insert_end(&head,9);
	insert_end(&head,9);
	printlist(head);
	removeduplicates(head);
	printlist(head);
	return 0;
}
