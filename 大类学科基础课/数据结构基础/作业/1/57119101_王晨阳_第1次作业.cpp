/*
	Name: ��һ����ҵ 
	Author: 57119101������
	Date: 09/10/20 20:00 
	Description: 
		> ����һ����������Ϊ�¿�������ĳ��ȣ����������飬������������ǰһ�룬��һ��Ϊ�գ�
		> ����һ����������Ϊ����λ�ã��ڸ�λ�ò���0��
		> ����һ��������ɾ����λ�õ����ݣ�
		> �����ݽ���ת�á�
*/

#include<bits/stdc++.h>
using namespace std;


typedef int ElemType;
typedef struct 
{
	ElemType *elem;
	int length;								//��ǰ�����ݳ��� 
	int listsize;							//��ʹ��������
}SqList;


int InitList_Sq(SqList &L) 
{
	int maxSize;
	printf("input the size of sqlist:     ");
	scanf("%d",&maxSize);
	L.elem=new ElemType[maxSize];
	L.length=maxSize/2; 					//�ձ�ǰ����Ϊ0
	L.listsize=maxSize; 					//��ʼ�洢����
	srand(time(0));
	for (int i=0;i<L.length;i++)
		L.elem[i]=rand();
}

bool ListInsert_Sq(SqList &L,int i,ElemType e)
{
	ElemType *p;
	if (i<1 || i>L.length+1) return false;	//i�ĺϷ�ֵΪ1��i��L.length+1  
	if (L.length>=L.listsize) return false;	//�����ǲ����Ѿ�����
	ElemType *q=&(L.elem[i-1]);
	for (p=&(L.elem[L.length-1]);p>=q;--p)
        *(p+1)=*p;
	*q=e; 
	++L.length; 
	return true;
}

bool ListDelete_Sq(SqList &L,int i,ElemType &e)
{
	ElemType *p,*q;
	if (i<1 || i>L.length) return false; 	//i�ĺϷ�ֵΪ1��i��L.length
	p=&(L.elem[i-1]);
	e=*p;
	q=L.elem+L.length-1;
	for (++p;p<=q;++p)
		*(p-1)=*p;  						//��ɾ��Ԫ��֮���Ԫ������
	--L.length;
	return true;
}

void ListReverse_Sq(SqList &L)
{
	ElemType *p,*q;
	p=&(L.elem[0]);
	q=&(L.elem[L.length-1]);
	while (p<q)
	{
		swap(*p,*q);
		++p;
		--q;
	}
}

void ListDisplay_Sq(SqList &L)
{
	ElemType *p;
	for (p=&(L.elem[0]);p<=&(L.elem[L.length-1]);++p)
		printf("%d\t",*p);
	printf("\n");
}


int main()
{
	SqList sl;
	
	//��ʼ�� 
	InitList_Sq(sl);
	printf("sqlist after initialize:      ");
	ListDisplay_Sq(sl);
	printf("\n");
	
	//���� 
	int pos,val;
	printf("input the position to insert: ");
	scanf("%d",&pos);
	ListInsert_Sq(sl,pos,0);
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
	
	delete []sl.elem;
}
