#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	char name[30];
	int age;
	float score;
	struct Node *next;
};
/*
struct Node *create_list(void)
{
	struct Node *head, *new, *rear;
	int i;
	head = (struct Node *)malloc(sizeof(struct Node));
	rear = head;

	//new = (struct Node *)malloc(sizeof(struct Node));
	//head->next = new;
	//printf("请输入年龄:");
	//scanf_s("%d",&new->age);
	//rear->next = new;
	//rear = new;
	//
	//new = (struct Node *)malloc(sizeof(struct Node));
	//printf("请输入年龄:");
	//scanf_s("%d", &new->age);
	//rear->next = new;
	//rear = new;

	//new = (struct Node *)malloc(sizeof(struct Node));
	//printf("请输入年龄:");
	//scanf_s("%d", &new->age);
	//rear->next = new;
	//rear = new;
	for (i = 0;i < 3;i++)
	{
		new = (struct Node *)malloc(sizeof(struct Node));
		printf("请输入年龄:");
		scanf_s("%d", &new->age);
		if (i == 0)
		{
			head->next = new;
			rear->next = new;
			rear = new;
		}
		else
		{
			rear->next = new;
			rear = new;
		}
	}
	rear->next = NULL;
	return head;
}
*/

struct Node *create_list()
{
	struct Node *head, *new, *p;
	head = (struct Node *)malloc(sizeof(struct Node));
	head->next = NULL;
	p = head;
	for (int i = 0;i < 4;i++)
	{
		new = (struct Node *)malloc(sizeof(struct Node));
		printf("输入年龄:");
		scanf_s("%d",&new->age);
		if (head->next = NULL)
		{
			head->next = new;
			p->next = new;
			p = new;
		}
		else
		{			
			p->next = new;
			p = new;
		}
		p->next = NULL;		
	}
	return head;
}
void print_list(struct Node *pNode)
{
	pNode = pNode->next;
	while (pNode != NULL)
	{
		//printf("%s%d%.1f",pNode->name,pNode->age,pNode->score);
		printf("%d\n", pNode->age);
		pNode = pNode->next;
	}
}
int main(void)
{
	struct Node *Head;

	Head = create_list();
	print_list(Head);

	return 0;
}