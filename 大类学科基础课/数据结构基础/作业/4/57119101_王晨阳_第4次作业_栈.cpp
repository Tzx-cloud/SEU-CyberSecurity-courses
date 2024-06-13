/*
	Name: ������ҵ 
	Author: 57119101������
	Date: 21/10/20 19:00 
	Description: 
		> ʹ��ջ�����зֱ����һ���㷨�����Թ�·�����ң������ж�ά�����ʾ�Թ���
		  1��ʾ����ͨ����0��ʾ����ͨ�������Ͻ�2Ϊ��㣬���½�3Ϊ�յ㣩
*/


#include<bits/stdc++.h>
using namespace std;


#define maxRow 15//Map���� 
#define maxColume 15//Map���� 


int Map[maxRow][maxColume] = { { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
            				   { 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
            				   { 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1 },
            				   { 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1 },
            				   { 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1 },
            				   { 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1 },
            				   { 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1 },
            				   { 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1 },
            				   { 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1 },
            				   { 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1 },
            				   { 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1 },
            				   { 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1 },
            				   { 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1 },
            				   { 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 1 },
            				   { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }};
            				   
            				   
struct Coord//��¼���� 
{
	Coord(int X,int Y)//��ʼ�� 
	{
		this->x=X;
		this->y=Y;
	}
	int x;
	int y;
};


bool dfs(int a,int b,stack<Coord> &s)//����stack�ļ�¼·�������� 
{
	if (Map[a][b]==1) return false;//����ǽ�����Ѿ��߹��ĵط� 
	Map[a][b]=1;
	Coord c(a,b);
	s.push(c);
	if (a==maxRow-2 && b==maxColume-2)//���յ��� 
		return true;
	bool finded;
	//�����ĸ������������һ���ҵ��ˣ��Ͳ������� 
	finded=dfs(a+1,b,s);
	if (!finded) finded=dfs(a,b+1,s);
	if (!finded) finded=dfs(a-1,b,s);
	if (!finded) finded=dfs(a,b-1,s);
	if (!finded)
	{
		s.pop();
		return false;
	}
	return true;
}


void Output(stack<Coord> &s)//��� 
{
	stack <Coord> op;
	//stack pop����·���Ƿ������ģ�����һ��stack���������� 
	while (!s.empty())
	{
		op.push(s.top());
		s.pop();
	}
	printf("�ҵ�·��! \n·��Ϊ ( %d , %d )\n",op.top().x,op.top().y);
	op.pop();
	while (!op.empty())
	{
		printf("    -> ( %d , %d )\n",op.top().x,op.top().y);
		op.pop();
	}
}


int main()
{
	bool finded;
	stack <Coord> s;
	finded=dfs(1,1,s);
	if (!finded) printf("��ѽ��û�ҵ�·��~~(��)");
	else Output(s);
} 
