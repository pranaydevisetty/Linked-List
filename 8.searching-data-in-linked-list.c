#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};

int search(struct node*h1,int d)
{
	int c=1;
	struct node*n=h1;
	while(n!=NULL)
	{
		if(n->data==d)
		{
			return c;
		}
		n=n->next;
		c++;
	}
	return -1;
}

int searchr(struct node* h2,int d)
{
	static int c=1;
	if(h2==NULL)
	{
		return -1;
	}
	
	if(h2->data==d)
	{
		return c;	
	}
	c++;
	searchr(h2->next,d);
	
}
int main()
{
	//Creating a Linked list
	
	struct node* head=(struct node*)malloc(sizeof(struct node));
	struct node* second=(struct node*)malloc(sizeof(struct node));
	struct node* third=(struct node*)malloc(sizeof(struct node));
	
	int sdata;
	scanf("%d",&sdata);
	
	head->data = 2;
	head->next=second;
	
	second->data=3;
	second->next=third;
	
	third->data=4;
	third->next=NULL;
	
	int position=search(head,sdata);
	if(position!=-1)
	{
		printf("require %d is at %d(iterative)\n",sdata,position);
		
	}
	else
		printf("%d is not in linked list Sorry!!(iterative)\n",sdata);
	int position2=searchr(head,sdata);
	
	if(position2!=-1)
	{
		printf("require %d is at %d(recursive)\n",sdata,position);
		
	}
	else
		printf("%d is not in linked list Sorry!!(recursive)\n",sdata);
	return 0;
}
