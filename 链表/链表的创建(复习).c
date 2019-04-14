#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};
//尾插法创建链表
struct Node *createList(void)
{
	struct Node *head, *r;
	head = (struct Node *)malloc(sizeof(struct Node));
	r = head;
	for (int i = 0;i < 4;i++)
	{
		struct Node *p;
		p = (struct Node *)malloc(sizeof(struct Node));
		scanf_s("%d", &p->data);
		r->next = p;
		r = p;
	}
	r->next = NULL;

	return head;
}

//头插法创建链表
struct Node *CreateList(void)
{
	struct Node *head;
	head = (struct Node *)malloc(sizeof(struct Node));
	head->next = NULL;
	for (int i = 0;i < 4;i++)
	{
		struct Node *p;
		p = (struct Node *)malloc(sizeof(struct Node));
		scanf_s("%d", &p->data);
		p->next = head->next;
		head->next = p;
	}
	return head;
 }
void printList(struct Node *head)
{
	while (head->next != NULL)
	{
		head = head->next;
		printf("%d\n", head->data);
	}
}
int main(void)
{
	struct Node *head;
	
	head = CreateList();
	printList(head);

	return 0;
}