//Intersection of two Nodes
//There are many ways to Solve this I choose Hash-table method as it is easy to visualize 
//produce correct results
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
	int check;
};

int getIntersectionNode(struct node* head1,struct node* head2)
{
	struct node* node1 = head1;
	struct node* node2 = head2;
	struct node* resnode = NULL;
	if(head1==NULL&&head2==NULL)
	{
		return -1;	
	}
	while(node1!=NULL)
	{
		//printf("node1->%d\n",node1->data);
		node1->check = 1;
		node1 = node1->next;
	}
	while(node2!=NULL)
	{
		if(node2->check == 1)
		{
			//printf("node2->%d",node2->data);
			return node2->data;
		}
		//printf("node2->%d",node2->data);
		node2 = node2->next;
	}
	return -1;
}
int main()
{
  /*
    Create two linked lists
 
    1st 3->6->9->15->30
    2nd 10->15->30
 
    15 is the intersection point
  */
 
  struct node* newNode;
   struct node* newNode2;
  struct node* head1 =
            (struct node*) malloc(sizeof(struct node));
  head1->data  = 10;
 
  struct node* head2 =
            (struct node*) malloc(sizeof(struct node));
  head2->data  = 3;
 
  newNode = (struct node*) malloc (sizeof(struct node));
  newNode->data = 6;
  head2->next = newNode;
 
  newNode = (struct node*) malloc (sizeof(struct node));
  newNode->data = 9;
  head2->next->next = newNode;
 
  newNode = (struct node*) malloc (sizeof(struct node));
  newNode2 = (struct node*) malloc (sizeof(struct node));
  newNode->data = 15;
  newNode2->data = 15;
  head1->next = newNode2;
  head2->next->next->next  = newNode;
 
  newNode = (struct node*) malloc (sizeof(struct node));
  newNode->data = 30;
  head1->next->next= newNode;
  head2->next->next->next->next = newNode;
  head1->next->next->next = NULL;
 
  printf("\n The node of intersection is %d \n",
          getIntersectionNode(head1, head2));
 
return 0;
}
