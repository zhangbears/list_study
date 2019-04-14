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

//打印链表
void printList(struct Node *head)
{
	while (head->next != NULL)
	{
		head = head->next;
		printf("%d\t", head->data);
	}
	return;
}

//插入链表结点,在对链表的操作,头指针最好不要动
void InsertList(struct Node *head)
{
	int i=1;
	int num;
	struct Node *pi;
	pi = head;

	printf("请输入要增加结点的位置:");
	scanf_s("%d", &num);
	while (i <= num)
	{
		//首先找到要插入结点位置的前一结点
		if (i <num)
		{
			pi = pi->next;
			i++;
		}		
		else
		{
			//if中找到要插入结点位置的前一结点,本次循环插入结点,先建立结点,将结点的NEXT指针指向上一结点的NEXT指向,
			//然后将上一结点的NEXT指向新建立的结点,插入完成.
			struct Node *p;
			p = (struct Node *)malloc(sizeof(struct Node));
			printf("请输入要增加的内容:");
			scanf_s("%d", &p->data);
			p->next = pi->next;
			pi->next = p;
			break;
		}				
	}
}

//删除链表结点

void deleteList(struct Node *head)
{
	struct Node *p, *r;
	int i=1,num;
	p = r = head;

	printf("请输入要删除结点的位置:");
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

	head = createList();//创建链表
	printList(head);//输出链表

	InsertList(head);//插入结点
	printList(head);//输出链表 

	deleteList(head);//删除结点
	printList(head);//输出结点

	return 0;
}
/*输出结果
---------------------------------
1
2
3
4
1       2       3       4       请输入要增加结点的位置:3
请输入要增加的内容:33
1       2       33      3       4       请输入要删除结点的位置:4
1       2       33      4       
-----------------------------------
*/