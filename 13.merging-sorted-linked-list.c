#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
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

void move(struct node** dest, struct node** src)
{
	struct node* newnode = *src;
	
	assert(newnode!=NULL);
	
	*src = newnode->next;
	
	newnode->next = *dest;
	
	*dest = newnode;
}
struct node* sort_list(struct node* h1,struct node* h2)
{
	
	struct node dummy ;
	struct node* tail = &dummy;
	dummy.next = NULL;
	while(1)
	{
		if(h1 == NULL)
		{
			tail->next = h2;
			break;
		}
		
		if(h2 == NULL)
		{
			tail->next = h1;
			break;
		}
		
		if(h1->data<=h2->data)
		{
			move(&(tail->next),&h1);
		}
		else
		{
			move(&(tail->next),&h2);		
		}
		
		tail = tail->next;
	}
	
	return (dummy.next);
}
int main()
{
	struct node* head = NULL;
	struct node* head2 = NULL;
	struct node* head3 = NULL;
	int key;
	insert_end(&head,5);
	insert_end(&head,10);
	insert_end(&head,15);
	/*insert_end(&head,3);
	insert_end(&head,5);
	insert_end(&head,6);
	insert_end(&head,7);
	insert_end(&head,8);
	insert_end(&head,9);
	insert_end(&head,11);
	
	insert_end(&head2,4);
	insert_end(&head2,12);
	insert_end(&head2,13);
	insert_end(&head2,14);
	insert_end(&head2,15);
	insert_end(&head2,16);
	insert_end(&head2,17);*/
	insert_end(&head2,2);
	insert_end(&head2,3);
	insert_end(&head2,20);
	printlist(head);
	printlist(head2);
	head3 = sort_list(head,head2);
	printlist(head3);
	return 0;
}
