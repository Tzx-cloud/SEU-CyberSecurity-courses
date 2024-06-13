/*
	Name: ������ҵ 
	Author: 57119101������
	Date: 28/10/20 19:13
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
	Coord(int X=0,int Y=0)//��ʼ�� 
	{
		this->x=X;
		this->y=Y;
	}
	int x;
	int y;
};

Coord pre[maxRow][maxColume];

void bfs(queue<Coord> &q)//����queue�ļ�¼·���Ŀ��� 
{
	q.push(Coord(1,1));
	while (!q.empty())
	{
		Coord c(q.front().x,q.front().y);
		if (c.x==maxRow-2 && c.y==maxColume-2)
		{
			return;
		}
		q.pop();
		if (Map[c.x+1][c.y]!=1) Map[c.x+1][c.y]=1,q.push(Coord(c.x+1,c.y)),pre[c.x+1][c.y]=Coord(c.x,c.y);
		if (Map[c.x-1][c.y]!=1) Map[c.x-1][c.y]=1,q.push(Coord(c.x-1,c.y)),pre[c.x-1][c.y]=Coord(c.x,c.y);
		if (Map[c.x][c.y+1]!=1) Map[c.x][c.y+1]=1,q.push(Coord(c.x,c.y+1)),pre[c.x][c.y+1]=Coord(c.x,c.y);
		if (Map[c.x][c.y-1]!=1) Map[c.x][c.y-1]=1,q.push(Coord(c.x,c.y-1)),pre[c.x][c.y-1]=Coord(c.x,c.y);
	}
}


void Output()//��� 
{
	stack <Coord> s;
	Coord c(maxRow-2,maxColume-2);
	s.push(c);
	while (!(c.x==1 && c.y==1))
	{
		c=pre[c.x][c.y];
		s.push(c);
	}
	printf("�ҵ�·��! \n·��Ϊ ( %d , %d )\n",s.top().x,s.top().y);
	s.pop();
	while (!s.empty())
	{
		printf("    -> ( %d , %d )\n",s.top().x,s.top().y);
		s.pop();
	}
}


int main()
{
	queue <Coord> q;
	bfs(q);
	if (Map[maxRow-2][maxColume-2]!=1) printf("��ѽ��û�ҵ�·��~~(��)");
	else Output();
} 
