#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

//������ĳ�ʼ��,����ͷ���
struct Node *ListInit()
{
	struct Node *head;
	head = (struct Node *)malloc(sizeof(struct Node));
	if (head == NULL)
		printf("����ռ�ʧ��!\n");
	head->next = NULL;
	return head;
}

//������Ľ���	1) ͷ�巨  ��Ҫ�����ṹ��ָ��
struct Node *CreateList(void)
{
	//����ͷ���ռ�
	struct Node *H;
	H = (struct Node *)malloc(sizeof(struct Node));
	H->next = NULL;

	//int a;//�����洢����,�������ݸ�ֵ���ڵ�����ݱ���,������ͨ��a���ж������whileѭ��
	for(int i=0;i<4;i++)
	{
		struct Node *p;
		p = (struct Node *)malloc(sizeof(struct Node));
		printf("����������");
		scanf_s("%d",&p->data);
		p->next = H->next;
		H->next = p;
		
	}
	return H;
}
//����Ĵ���,2) β�巨��Ҫ�����ṹ��ָ��
struct Node *C_List(void)
{
	struct Node *head,*r;
	r = head = (struct Node *)malloc(sizeof(struct Node));
	head->next = NULL;
	for (int i = 0;i < 4;i++)
	{
		struct Node *p;
		p = (struct Node *)malloc(sizeof(struct Node));
		printf("����������:");
		scanf_s("%d", &p->data);
		r->next = p;
		r = p;
	}
	r->next = NULL;

	return head;
}
//��������
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

	head = C_List();
	printList(head);

	return 0;
}