#include<bits/stdc++.h>
using namespace std;

void getNext(string str,int *next)
{
    next[0]=-1;
    int j=0,k=-1;
	while (j<str.length()-1)
	{
		if (k<0 || str[j]==str[k]) next[++j]=++k;
        else k=next[k];
	}
}

bool KMP(string str1,string str2)
{
    int i=0,j=0,str2length=str2.length(),next[str2length+5];
    bool finded=false;
	getNext(str2,next);
    while (i<str1.length() && j<str2length)
    {
        if (j==-1 || str1[i]==str2[j]) i++,j++;
        else j=next[j];
        if (j==str2length)
		{
			if (!finded) printf("\n�ҵ��ˣ�\n���Դ�ģʽ����\n");
			finded=true;
			printf("��%d���ַ�\n",i-j+1);
			i=i-j+1;
			j=0;
		}
    }
    if (finded) printf("��ʼƥ��\n");
    return finded;
}

int main()
{
	string str1,str2;
	printf("ģʽ��Ϊ: ");
	cin>>str1;
	printf("ƥ�䴮Ϊ: ");
	cin>>str2;
	if (!KMP(str1,str2)) printf("\n�����ӣ�û���ҵ�Ŷ\n");
}
