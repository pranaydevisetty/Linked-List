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

void reverselli(struct node** h_ref)
{
	struct node* cnode = *h_ref;
	struct node* nnode = NULL;
	struct node* pnode = NULL;
	while(cnode != NULL)
	{
		nnode = cnode->next;
		cnode->next = pnode;
		pnode = cnode;
		cnode = nnode;
	}
	
	*h_ref = pnode;	
}

void reversellr(struct node** h_ref)
{
	if(*h_ref == NULL)
		return;
	struct node* cnode = *h_ref;
	struct node* nnode = (*h_ref)->next;
	if(cnode->next == NULL)
	{
		return;
	}
	reversellr(&(nnode));
	cnode->next->next = cnode;
	cnode->next  = NULL;
	*h_ref = nnode;
	//printf("nnode->%d ",nnode->data);
//	printf("cnode->%d ",cnode->data);
//	printf("h_ref->%d",(*h_ref)->data);
	//printf("\n");
}

int main()
{
	struct node* head = NULL;
	struct node* head2 = NULL;
	int key;
	insert_end(&head,3);
	insert_end(&head,4);
	insert_end(&head,5);
	insert_end(&head,6);
	insert_end(&head,7);
	insert_end(&head,8);
	insert_end(&head,9);
	head2 = head;
	printlist(head2);
	printlist(head);
	reverselli(&head);
	printlist(head);
	printlist(head2);
	reversellr(&head);
	printlist(head);
	printlist(head2);
	return 0;
}

