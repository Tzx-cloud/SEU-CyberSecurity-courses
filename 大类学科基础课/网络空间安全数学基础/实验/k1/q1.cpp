/*******************************************************************************
author:������
description:����Miller-Rabin���������㷨��ͬʱ���ÿ������㷨�ӿ������� 
*******************************************************************************/


#include<bits/stdc++.h>
using namespace std;


const long long reversedStudentNumber=10191175;//ѧ������ 
long long prime[10]={2,3,5,7,11,13,17,19,23,29};//ǰ30������ 
//30������������ȫ��ͨ������ֱ���ж�ѧ�ŷ�Χ�ڵ���ȫ�����жϴ��� 


long long qPower(long long base,long long power,long long c)//������
{
    long long ans=1,res=base;
    while(power)
    {
        if(power&1)//powerΪ���� 
          ans=(ans*res)%c;
        res=(res*res)%c;
        power>>=1;//power/2
    }
    return ans;
}


bool mr(long long number)//Miller-Rabin�㷨����
{
    long long a,b,s=0,t=number-1;
    
	//���ڱ������жϵ�������2����߿���ʡ�� 
	//    if(number==2)  return true;
	//    if(number<2||!(number&1))  return false;

	//��x-1�ֽ��(2^s)*t
    while(!(t&1))//tΪż�� 
    {
        s++;
        t>>=1;
    }
    
    //ͨ����������в��� 
    for(long long i=0;i<10/* && prime[i]<x*/;i++)
    {
        a=qPower(prime[i],t,number);//����prime[i]^t
        for(long long j=1;j<=s;j++)
        {
            b=(a*a)%number;//����b��ƽ�� 
            if(b==1 && a!=1 && a!=number-1)//����̽��
              return false;
            a=b;
        }
        if(a!=1)//����С����
			return false; 
    }
    return true;
}


int main()
{
	long long finded=0;//�Ѿ��ҵ�����������
	long long temp=reversedStudentNumber;//Ŀǰ���ڼ������
	if (!(temp&1))//�ų�ż�� 
		temp--;
	while (finded<2)
	{
		if(mr(temp))//��������� 
		{
			finded++;
			printf("��%lld�������Ϊ%lld\n",finded,temp);//������ 
		}
    	temp-=2;
    }
    return 0;
}

/*
ѧ�ţ�
57119101

���н���� 
��1�������Ϊ10191161
��2�������Ϊ10191133
*/ 
