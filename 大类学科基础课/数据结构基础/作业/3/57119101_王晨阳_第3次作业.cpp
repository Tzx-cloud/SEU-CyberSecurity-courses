/*
	Name: ��������ҵ 
	Author: 57119101������
	Date: 21/10/20 19:15 
	Description: 
		> ����һ����������Ϊ�¿�������ĳ��ȣ����������飬������������ǰһ�룬��һ��Ϊ�գ�
		> ����һ����������Ϊ����λ�ã��ڸ�λ�ò���0��
		> ����һ��������ɾ����λ�õ����ݣ�
		> �����ݽ���ת�á�
*/


#include<bits/stdc++.h>
using namespace std;


typedef int ElemType;

typedef struct LNode
{   
    ElemType data;
    struct LNode *next;
	struct LNode *prior;
}LNode,*LinkList;

int maxSize;


int InitList_Sq(LinkList &L)
{
	printf("input the size of sqlist:     ");
	scanf("%d",&maxSize);
	LinkList p=NULL,q=NULL;
	L=new LNode;
	L->next=NULL; 
	L->prior=NULL;
	q=L;
	srand(time(0));
	for (int i=0;i<maxSize/2;++i)
	{
		p=new LNode;
		p->data=rand();
		p->prior=q;
		q->next=p;    
		p->next=L->next;
		L->next->prior=p;
		q=p;      
	}
	for (int i=maxSize/2;i<maxSize;++i)
	{
		p=new LNode;
		p->data=0;     
		p->prior=q;
		q->next=p;    
		p->next=L->next;
		L->next->prior=p;
		q=p;      
	}
	delete p;
	delete q;
}

bool ListInsert_Sq(LinkList &L,int i,ElemType &e)
{
	LinkList p=NULL,s=NULL;
	p=L;
	int j=0;
	while (p && j<i-1) 
	{
		p=p->next;
		++j;
	}             
	s=new LNode;
	s->data=e;
	s->next=p->next;
	p->next->prior=s;
	p->next=s;
	s->prior=p;
	return true;
}

bool ListDelete_Sq(LinkList &L,int i,ElemType &e)
{
	LinkList p=NULL,q=NULL;
	p=L;
	int j=0;
	while (p->next && j<i-1)
	{
		p=p->next;
		++j;
	}
	q=p->next;
	p->next=q->next;
	q->next->prior=p;                                 
	e=q->data;
	delete q;
	return true;
}

void ListReverse_Sq(LinkList &L)
{
	LinkList p=NULL,q=NULL,r=NULL;
	p=L->next;
	q=p->next;
	r=q->next;
	do
	{
		p->prior=q;
		q->next=p;
		p=q;
		q=r;
		r=r->next;
	}while (p!=L->next);
	L->next=p->next;
}

void ListDisplay_Sq(LinkList &L)
{
	LinkList p=NULL;
	p=L;p=p->next;
	printf("%d\t",*p);
	p=p->next;
	while (p!=L->next)
	{
		printf("%d\t",*p);
		p=p->next;
	}
	printf("\n");
}


int main()
{
	LinkList sl;
	
	//��ʼ�� 
	InitList_Sq(sl);
	printf("sqlist after initialize:      ");
	ListDisplay_Sq(sl);
	printf("\n");
	
	//���� 
	int pos,val,num=0;
	printf("input the position to insert: ");
	scanf("%d",&pos);
	ListInsert_Sq(sl,pos,num);
	printf("sqlist after insert:          ");
	ListDisplay_Sq(sl);
	printf("\n");
	
	//ɾ�� 
	int deletedElem;					//��ɾ����Ԫ�� 
	printf("input the position to delete: ");
	scanf("%d",&pos);
	ListDelete_Sq(sl,2,deletedElem);
	printf("sqlist after delete:          ");
	ListDisplay_Sq(sl);
	printf("the element deleted is:       %d\n",deletedElem);
	printf("\n");
	
	//ת�� 
	ListReverse_Sq(sl);
	printf("sqlist after reverse:         ");
	ListDisplay_Sq(sl);
	printf("\n");
}
