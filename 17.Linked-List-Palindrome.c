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
struct node* middle_element(struct node *head)
{
	struct node *fptr = head;
	struct node* sptr = head;
	
	while(fptr!=NULL && fptr->next!=NULL)
	{
		//printf("SPTR-%d,FPTR-%d\n",sptr->data,fptr->data);
		fptr = fptr->next->next;
		sptr = sptr->next;
		
	}
	//odd
	if(fptr==NULL)
	{	
		return sptr;
	}
	//even
	if(fptr->next==NULL)
	{
		return sptr->next;
	}
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
int comparelists(struct node* fh, struct node* sh)
{
	struct node* node1 = fh;
	struct node* node2 = sh;
	
	while(node1!=NULL && node2!=NULL)
	{
	//	printf("node1->%d\n",node1->data);
	//	printf("node2->%d\n",node2->data);
		if(node1->data!=node2->data)
		{
			return 0;
		}
		node1 = node1->next;
		node2 = node2->next;
	}

return 1;
}
int palindrome(struct node* head)
{
	struct node *fptr = head;
	struct node* sptr = head;
	struct node* prev_middle = NULL;
	int res;
	while(fptr!=NULL && fptr->next!=NULL)
	{
		//printf("SPTR-%d,FPTR-%d\n",sptr->data,fptr->data);
		prev_middle = sptr;
		fptr = fptr->next->next;
		sptr = sptr->next;
		
	}
	struct node * middle = NULL;
	if(fptr !=NULL)
	{
		middle = sptr;
		sptr = sptr->next;
	}
	prev_middle->next = NULL;
	reverselli(&sptr);
//	printf("middle->%d\n",middle->data);
	res = comparelists(head,sptr);
	reverselli(&sptr);
	
	if(middle!=NULL)
	{
		prev_middle->next = middle;
	}
	
	else
	{
		prev_middle->next = sptr;
	}
	
	return res;
}

int main()
{
	struct node* head = NULL;
	int result;
	int key;
	insert_end(&head,3);
	insert_end(&head,4);
	//insert_end(&head,5);
	insert_end(&head,4);
	insert_end(&head,3);
	//insert_end(&head,8);
	//insert_end(&head,9);
	printlist(head);
	result = palindrome(head);
	if(result)
		printf("string is palindrome\n");
	else
		printf("string is not palindrome\n");
		
	printlist(head);
	return 0;
}
	
