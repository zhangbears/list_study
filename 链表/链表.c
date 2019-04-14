#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

//单链表的初始化,创建头结点
struct Node *ListInit()
{
	struct Node *head;
	head = (struct Node *)malloc(sizeof(struct Node));
	if (head == NULL)
		printf("申请空间失败!\n");
	head->next = NULL;
	return head;
}

//单链表的建立	1) 头插法  需要两个结构体指针
struct Node *CreateList(void)
{
	//申请头结点空间
	struct Node *H;
	H = (struct Node *)malloc(sizeof(struct Node));
	H->next = NULL;

	//int a;//用来存储数据,并将数据赋值给节点的数据变量,还可以通过a来判断下面的while循环
	for(int i=0;i<4;i++)
	{
		struct Node *p;
		p = (struct Node *)malloc(sizeof(struct Node));
		printf("请输入数据");
		scanf_s("%d",&p->data);
		p->next = H->next;
		H->next = p;
		
	}
	return H;
}
//链表的创建,2) 尾插法需要三个结构体指针
struct Node *C_List(void)
{
	struct Node *head,*r;
	r = head = (struct Node *)malloc(sizeof(struct Node));
	head->next = NULL;
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
//链表的输出
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