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

struct node* intersection(struct node* node1,struct node* node2)
{
	struct node* inode1 = node1;
	struct node* inode2 = node2;
	struct node dummy;
	struct node* in_ll = &dummy;
	in_ll->next = NULL;
	struct node* temp = NULL;
	if(node1==NULL || node2==NULL)
	{
		return;
	}
	while(inode1!=NULL && inode2!=NULL)
	{
		if(inode1->data==inode2->data)
		{
			insert_end((&in_ll->next),inode1->data);
			in_ll = in_ll->next;
			inode1 = inode1->next;
			inode2 = inode2->next;
		}
		else
		{
			if(inode1->data<inode2->data)
				inode1 = inode1->next;
			else
				inode2 = inode2->next;
		}
	}
	//in_ll->next = NULL;
	return dummy.next;
}
int main()
{
	struct node* head = NULL;
	struct node*head2 = NULL;
	struct node* in_ll = NULL;
	int key;
	insert_end(&head,1);
	insert_end(&head,2);
	insert_end(&head,3);
	insert_end(&head,4);
	insert_end(&head,6);
//	insert_end(&head,8);
//	insert_end(&head,9);
	
	insert_end(&head2,2);
	insert_end(&head2,4);
	insert_end(&head2,6);
	insert_end(&head2,8);
	//insert_end(&head2,9);
	in_ll = intersection(head,head2);
	printlist(head);
	printlist(head2);
	printlist(in_ll);
	return 0;
}
