#include<bits/stdc++.h>
using namespace std;

int BinarySearch(int a[],int l,int r,int num)
{
//	printf("%d %d %d %d\n",l,r,(l+r)/2,a[(l+r)/2]);
	int mid=(l+r)/2;
	if (a[mid]==num)
		return mid;
	if (l>=r)
		return -1;
	if (a[mid]<num)
		return BinarySearch(a,mid+1,r,num);
	else
		return BinarySearch(a,l,mid-1,num);
}

int main()
{
	int a[30],num,ans;
	srand(time(0));
	a[0]=0;
	printf("������ɵ�����Ϊ��");
	for (int i=1;i<=25;i++)
	{
		a[i]=a[i-1]+rand();
		printf("%d\t",a[i]);
	}
	printf("\n������Ҫ���ҵ�����");
	scanf("%d",&num);
	ans=BinarySearch(a,1,25,num);
	if (ans==-1)
		printf("Fuck��û�ҵ���");
	else 
		printf("�ҵ��ˣ��ڵ�%d����",ans); 
}
