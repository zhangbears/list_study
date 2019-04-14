/*头部插入结点法创建链表*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};
//头插法创建链表,需要两个结构体指针
struct Node *createList(void)
{
	struct Node *head;
	head = (struct Node *)malloc(sizeof(struct Node));
	head->next = NULL;

	for (int i = 0;i < 5;i++)
	{
		struct Node *p;
		p = (struct Node *)malloc(sizeof(struct Node));
		printf("请输入数据:");
		scanf_s("%d",&p->data);
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
		printf("%d\n",head->data);
	}
}
int main(void)
{
	struct Node *head;

	head = createList();
	printList(head);

	return 0;
}