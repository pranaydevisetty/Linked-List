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
	if(h_ref==NULL)
	{
		printf("LL is Empty");
		return;
	}
	struct node* pnode = h_ref;
	while(pnode!=NULL)
	{
		printf("%d->",pnode->data);
		pnode = pnode->next;
	}
	printf("\n");
}

void deleteat(struct node** nodeptr)
{
	struct node* p = *nodeptr;
	struct node* n = p->next;
	if(n == NULL)
	{
		free(p);
		*nodeptr = NULL;
		return;
	}
	if(n!=NULL)
	{
		p->data = n->data;
		p->next = n->next;
	}
	free(n);
}
int main()
{
	struct node* head = NULL;
	insert_end(&head,3);
	insert_end(&head,4);
	/*insert_end(&head,5);
	insert_end(&head,6);
	insert_end(&head,7);
	insert_end(&head,8);
	insert_end(&head,9);*/
	printlist(head);
	deleteat(&(head->next));
	printlist(head);
	return 0;
}
