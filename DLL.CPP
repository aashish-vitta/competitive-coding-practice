#include"stdio.h"
#include"conio.h"
#include"stdlib.h"
struct node
{
	int data;
	struct node *llink;
	struct node *rlink;
}*head;
void insbeg()
{
	int item;
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data to be inserted:");
	scanf("%d",&item);
	if(temp==NULL)
	{
		printf("Memory allocation erroe");
		return;
	}
	temp->data=item;
	if(head->rlink==NULL)
	{
		head->rlink=temp;
		temp->llink=head;
		temp->rlink=NULL;
	}
	else
	{
		struct node *temp1;
		temp1=(struct node*)malloc(sizeof(struct node));
		temp1=head->rlink;
		temp->rlink=temp1;
		temp1->llink=temp;
		temp->llink=head;
		head->rlink=temp;
	}
}
void traversal()
{
	if(head->rlink==NULL)
	{
		printf("Doubly Linked List Empty ^_^ \n");
		return;
	}
	struct node *temp1;
	temp1=(struct node*)malloc(sizeof(struct node));
	temp1=head->rlink;
	while(temp1->rlink!=NULL)
	{
		printf("%d\t",temp1->data);
		temp1=temp1->rlink;
	}
	printf("%d\t",temp1->data);
}
void insend()
{
	int item;
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data to be inserted:");
	scanf("%d",&item);
	if(temp==NULL)
	{
		printf("Memory allocation erroe");
		return;
	}
	temp->data=item;
	if(head->rlink==NULL)
	{
		head->rlink=temp;
		temp->llink=head;
		temp->rlink=NULL;
	}
	else
	{
		struct node *temp1;
		temp1=(struct node*)malloc(sizeof(struct node));
		temp1=head->rlink;
		while(temp1->rlink!=NULL)
		{
			temp1=temp1->rlink;
		}
		temp1->rlink=temp;
		temp->llink=temp1;
		temp->rlink=NULL;
	}
}
void delbeg()
{
	struct node *temp,*temp1;
	temp=(struct node*)malloc(sizeof(struct node));
	temp1=(struct node*)malloc(sizeof(struct node));
	if(head->rlink==NULL)
	{
		printf("\nDouble Linked list empty\n");
		return;
	}
	temp=head->rlink;
	head->rlink=temp->rlink;
	temp1=temp->rlink;
	temp1->llink=temp->llink;
	printf("\nDeleted element is :%d",temp->data);
	free(temp);
}
void delend()
{
	if(head->rlink==NULL)
	{
		printf("Double linked list empty");
		return;
	}
	struct node *temp,*temp1;
	temp=(struct node*)malloc(sizeof(struct node));
	temp1=(struct node*)malloc(sizeof(struct node));
	temp=head;
	temp1=head;
	while(temp->rlink!=NULL)
	{
		temp1=temp;
		temp=temp->rlink;
	}
	temp1->rlink=NULL;
	printf("Deleted element is :%d",temp->data);
	free(temp);
}
void main()
{
	int ch;
	clrscr();
	head->rlink=NULL;
	while(1)
	{
		printf("\n1.Insertion at begining");
		printf("\n2.Insertion at ending");
		printf("\n3.Deletion at begining");
		printf("\n4.Deletion at ending");
		printf("\n5.Traversal.");
		printf("\n6.Exit");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case(1):
			{
				insbeg();
				break;
			}
			case(2):
			{
				insend();
				break;
			}
			case(3):
			{
				delbeg();
				break;
			}
			case(4):
			{
				delend();
				break;
			}
			case(5):
			{
				traversal();
				break;
			}
			case(6):
			{
				exit(1);
				break;
			}
			default:
			{
				printf("Wrong choice");
				break;
			}
		}
	}
}