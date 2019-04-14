#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};
//尾插法创建链表,需要三个结构体指针
struct Node *createList(void)
{
	struct Node *head,*r;
	head = (struct Node *)malloc(sizeof(struct Node));
	head->next = NULL;
	r = head;
	for (int i = 0;i < 4;i++)
	{
		struct Node *p;
		p = (struct Node *)malloc(sizeof(struct Node));
		printf("请输入数据:");
		scanf_s("%d", &p->data);
		r->next = p;
		r = p;
	}
	r->next = NULL;

	return head;
}
void printList(struct Node *head)
{
	while (head->next != NULL)
	{
		head = head->next;
		printf("%d\n", head->data);
	}
	return;
}
int main(void)
{
	struct Node *head;
	head = createList();
	printList(head);

	return 0;
}