/*******************************************************************************
author:������
description:����ŷ�����շת��������gcd��lcm 
*******************************************************************************/


#include<bits/stdc++.h>
using namespace std;

//ȫ����long long��ֹ��� 
const long long StudentNumber		 =57119101;//ѧ�� 
const long long reversedStudentNumber=10191175;//ѧ������ 


long long gcd(long long a,long long b)//�ݹ�ʹ��ŷ�����շת��������gcd 
{
    if (a%b==0)
        return b;
    return gcd(b,a%b);
}

long long lcm(long long a,long long b)//��gcd��lcm 
{
    return a*b/gcd(a,b);
}


int main()
{
    printf("���Լ��Ϊ%lld\n",gcd(StudentNumber,reversedStudentNumber));
	printf("��С������Ϊ%lld\n",lcm(StudentNumber,reversedStudentNumber));
    return 0;
}

/*
ѧ�ţ�
57119101

���н���� 
���Լ��Ϊ1
��С������Ϊ582110754133675
*/ 
