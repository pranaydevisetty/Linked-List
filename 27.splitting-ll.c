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

void split(struct node* head,struct node** h1,struct node** h2)
{
	if(head == NULL || head->next == NULL)
	{
		return;
	}
	struct node dummy1;
	struct node dummy2;
	struct node* inode = head;
	struct node* prev1 = &dummy1;
	struct node* prev2 = &dummy2;
	struct node* temp = NULL;
	prev1->next = NULL;
	prev2->next = NULL;
	int data;
	while(inode!=NULL&&inode->next!=NULL)
	{
		printf("inode->%d\n",inode->data);
		insert_end((&prev1->next),inode->data);
		insert_end((&prev2->next),inode->next->data);
		inode = inode->next->next;
	}
	if(inode!=NULL)
	{
		insert_end((&prev1->next),inode->data);
	}
	*h1 = dummy1.next;
	*h2 = dummy2.next;
	//return dummy.next;
}
int main()
{
	struct node* head = NULL;
	struct node* head2 = NULL;
	struct node* part1 = NULL;
	struct node* part2 = NULL;
	insert_end(&head,1);
	insert_end(&head,2);
	insert_end(&head,3);
	insert_end(&head,4);
	insert_end(&head,5);
	insert_end(&head,6);
	insert_end(&head,9);
	printlist(head);
	split(head,&part1,&part2);
	printlist(head);
	printlist(part1);
	printlist(part2);
	return 0;
}
