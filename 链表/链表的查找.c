#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
	char name[20];
	int age;
	struct Node *next;
};

struct Node *creatList(void)
{
	struct Node *head, *rear;
	int num;

	rear = head = (struct Node *)malloc(sizeof(struct Node));
	head->next = NULL;	//��ʼ��ͷ���,ͷָ����Ҫָ��NULL

	printf("����������ĳ���:");
	scanf_s("%d", &num);
	for (int i = 0;i < num;i++)
	{
		struct Node *p;
		p = (struct Node *)malloc(sizeof(struct Node));
		printf("����������:");
		scanf_s("%s", p->name, 19);
		printf("����������:");
		scanf_s("%d", &p->age);
		rear->next = p;
		rear = p;
	}
	rear->next = NULL;

	return head;
}

void printList(struct Node *head)
{
	printf("-----------------------\n");
	printf("����\t����\t\n");
	while (head->next != NULL)
	{
		head = head->next;
		printf("%s\t%d\n", head->name, head->age);
	}
	return;
}

void searchList(struct Node *head)
{
	char name[20];

	printf("������Ҫ��ѯ������:");
	scanf_s("%s", name, 19);

	while (head->next != NULL)
	{
		head = head->next;
		if (strcmp(head->name, name) == 0)
		{
			printf("%s\t%d\n", head->name, head->age);
			break;
		}
	}
	return;
}
int main(void)
{
	struct Node *head;

	head = creatList();
	printList(head);

	searchList(head);

	return 0;
}