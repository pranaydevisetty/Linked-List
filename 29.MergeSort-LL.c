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

struct node* sort_merge(struct node* fh,struct node* sh)
{
	struct node* r_node = NULL;
	
	if(fh==NULL)
	{
		return sh;
	}
	if(sh==NULL)
	{
		return fh;
	}
	
	if(fh->data<=sh->data)
	{
		r_node = fh;
		r_node->next = sort_merge(fh->next,sh);
	}
	else
	{
		r_node = sh;
		r_node->next = sort_merge(sh->next,fh);
	}
	
	return r_node;
}
void divide(struct node* head, struct node** fh, struct node** sh  )
{
	struct node* sptr = head;
	if(head == NULL&&head->next == NULL)
	{
		*fh = head;
		*sh = NULL;
	}
		
	struct node* fptr = head->next;
	if(fptr==NULL)
	{
		return;
	}
	
	while(fptr!=NULL)
	{
		fptr = fptr->next;
		if(fptr!=NULL&&fptr->next!=NULL)
		{
			sptr = sptr->next;
			fptr = fptr->next;
		}
	}
	*fh = head;
	*sh = sptr->next;
	sptr->next = NULL;

	
}
void MergeSort(struct node **h_ref)
{
	struct node* first_half = NULL;
	struct node* second_half = NULL;
	
	struct node* inode = *h_ref;
	
	if(inode==NULL||inode->next==NULL)
		return;
	
	divide(*h_ref, &first_half,&second_half);
	
	
	MergeSort(&first_half);
	MergeSort(&second_half);
	printf("FH->");
	printlist(first_half);
	printf("SH->");
	printlist(second_half);
	//printf("ms\n");
	*h_ref = sort_merge(first_half,second_half);
	
}
int main()
{
	struct node* head = NULL;
	insert_end(&head,3);
	insert_end(&head,4);
	insert_end(&head,7);
	insert_end(&head,8);
	insert_end(&head,9);
	insert_end(&head,5);
	insert_end(&head,6);

	printlist(head);
	MergeSort(&head);             
	printlist(head);
	return 0;
}
