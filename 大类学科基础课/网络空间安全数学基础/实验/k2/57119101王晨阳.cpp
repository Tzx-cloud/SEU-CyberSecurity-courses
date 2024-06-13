/*******************************************************************************
author:������
description:RSA���ܽ��� 
*******************************************************************************/

#include<bits/stdc++.h>
using namespace std;

const long long p=10191161;
const long long q=10191133;

//��չŷ�����
void ex_gcd(long long a,long long b,long long &x,long long &y) 
{
	if (b==0)
	{
		x=1;
		y=0;
		return;
	}
	ex_gcd(b,a%b,x,y);
	long long t=x;
	x=y;
	y=t-a/b*y;
	return;
}

//���ٳ� 
long long qMultiply(long long x,long long y,long long c)
{
    return (x*y-(long long)((long double)x/c*y)*c+c)%c;     
}

//������
long long qPower(long long base,long long power,long long c)
{
    long long ans=1,res=base;
    while(power)
    {
        if(power&1)//powerΪ���� 
          ans=qMultiply(ans,res,c)%c;
        res=qMultiply(res,res,c)%c;
        power>>=1;//power/2
    }
    return ans;
}

//��֤���� 
bool is_coprime(long long a,long long b)
{
	if (a==1 || b==1)     // �����������У�ֻ������һ����ֵΪ1������������Ϊ������
		return true;
	while (true)
    {          // ������������������Լ��
		long long t=a%b;
		if (t==0) break;
		else
        {
			a=b;
			b=t;
		}
	}
	return (b==1);
}

//RSA���� 
long long RSA_encode(long long m,long long &n,long long &d,long long &e,long long &phi_n)
{
	long long temp;
	n=p*q;
	//printf("%lld\n",n);
	phi_n=n-p-q+1;
	//printf("%lld\n",phi_n);
	srand(time(0));
	e=rand()%phi_n+1;
	while (!is_coprime(e,phi_n)) e=rand()%phi_n+1;
	ex_gcd(e,phi_n,d,temp);
	while (d<=0)
		d+=phi_n;
	//printf("phi_n=%lld\nd=%lld\ntemp=%lld\n",phi_n,d,temp);
	return (qPower(m,e,n));
}

//RSA���� 
long long RSA_decode(long long n,long long d,long long c)
{
	return (qPower(c,d,n));
}

//������ 
int main()
{
	long long m,n,d,e,phi_n,c,Message;
	printf("����Ϊ ");
	scanf("%lld",&m);
	c=RSA_encode(m,n,d,e,phi_n);
	printf("��ԿΪ (%lld,%lld)\n˽ԿΪ (%lld,%lld)\n",e,n,d,n);
	printf("����Ϊ %lld\n",c);
	Message=RSA_decode(n,d,c);
	printf("����Ϊ %lld\n",Message);
} 
