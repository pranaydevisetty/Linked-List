//Generic Linked-List
#include <stdio.h>
#include <stdlib.h>

struct node
{
	void* data;
	struct node* next;
};

void insert_end(struct node**h_ref,void* new_data, int new_data_size)
{
	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	new_node->data = malloc(new_data_size);
	new_node->next = NULL;
	
	int i;
	
	for(i=0;i<new_data_size;i++)
	{
		*(char*)((new_node->data)+i) = *(char*)((new_data)+i);
	}
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

void printlist(struct node* node, void (*fptr)(void*))
{
	while(node!=NULL)
	{
		(*fptr)(node->data);
		node = node->next;	
	}	
	printf("\n");
}
 
void PrintInt(void* data)
{
	printf("%d->",*(int*)(data));
}

void PrintFloat(void* data)
{
	printf("%f->",*(float*)(data));
}

void PrintChar(void* data)
{
	printf("%c->",*(char*)(data));
}


int main()
{
	
	struct node* head = NULL;
	struct node* headf = NULL;
	struct node* headc = NULL;
	
	int ai[7] = {3,4,5,6,7,8,9};
	insert_end(&head,&ai[0],sizeof(int));
	insert_end(&head,&ai[1],sizeof(int));
	insert_end(&head,&ai[2],sizeof(int));
	insert_end(&head,&ai[3],sizeof(int));
	insert_end(&head,&ai[4],sizeof(int));
	insert_end(&head,&ai[5],sizeof(int));
	insert_end(&head,&ai[6],sizeof(int));
	printlist(head,PrintInt);
	
	float af[7] = {3.22,4.323,5.4,6.3,7.25,8.33,9.4};
	insert_end(&headf,&af[0],sizeof(float));
	insert_end(&headf,&af[1],sizeof(float));
	insert_end(&headf,&af[2],sizeof(float));
	insert_end(&headf,&af[3],sizeof(float));
	insert_end(&headf,&af[4],sizeof(float));
	insert_end(&headf,&af[5],sizeof(float));
	insert_end(&headf,&af[6],sizeof(float));
	printlist(headf,PrintFloat);
	
	char ac[7] = {'a','b','c','d','e','f','g'};
	insert_end(&headc,&ac[0],sizeof(char));
	insert_end(&headc,&ac[1],sizeof(char));
	insert_end(&headc,&ac[2],sizeof(char));
	insert_end(&headc,&ac[3],sizeof(char));
	insert_end(&headc,&ac[4],sizeof(char));
	insert_end(&headc,&ac[5],sizeof(char));
	insert_end(&headc,&ac[6],sizeof(char));
	printlist(headc,PrintChar);
	
	
	return 0;
}

