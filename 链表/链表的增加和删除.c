#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

//β�巨��������
struct Node *createList(void)
{
	struct Node *head,*rear;
	rear = head = (struct Node *)malloc(sizeof(struct Node));
	head->next = NULL;

	for (int i = 0;i < 4;i++)
	{
		struct Node *p;
		p = (struct Node *)malloc(sizeof(struct Node));
		scanf_s("%d", &p->data);
		rear->next = p;
		rear = p;
	}
	rear->next = NULL;

	return head;
}

//��ӡ����
void printList(struct Node *head)
{
	while (head->next != NULL)
	{
		head = head->next;
		printf("%d\t", head->data);
	}
	return;
}

//����������,�ڶ�����Ĳ���,ͷָ����ò�Ҫ��
void InsertList(struct Node *head)
{
	int i=1;
	int num;
	struct Node *pi;
	pi = head;

	printf("������Ҫ���ӽ���λ��:");
	scanf_s("%d", &num);
	while (i <= num)
	{
		//�����ҵ�Ҫ������λ�õ�ǰһ���
		if (i <num)
		{
			pi = pi->next;
			i++;
		}		
		else
		{
			//if���ҵ�Ҫ������λ�õ�ǰһ���,����ѭ��������,�Ƚ������,������NEXTָ��ָ����һ����NEXTָ��,
			//Ȼ����һ����NEXTָ���½����Ľ��,�������.
			struct Node *p;
			p = (struct Node *)malloc(sizeof(struct Node));
			printf("������Ҫ���ӵ�����:");
			scanf_s("%d", &p->data);
			p->next = pi->next;
			pi->next = p;
			break;
		}				
	}
}

//ɾ��������

void deleteList(struct Node *head)
{
	struct Node *p, *r;
	int i=1,num;
	p = r = head;

	printf("������Ҫɾ������λ��:");
	scanf_s("%d", &num);

	while (i < num)
	{
		p = p->next;
		i++;
	}
	r = p->next;
	p->next = r->next;
	free(r);
}
int main(void)
{
	struct Node *head;	

	head = createList();//��������
	printList(head);//�������

	InsertList(head);//������
	printList(head);//������� 

	deleteList(head);//ɾ�����
	printList(head);//������

	return 0;
}
/*������
---------------------------------
1
2
3
4
1       2       3       4       ������Ҫ���ӽ���λ��:3
������Ҫ���ӵ�����:33
1       2       33      3       4       ������Ҫɾ������λ��:4
1       2       33      4       
-----------------------------------
*/