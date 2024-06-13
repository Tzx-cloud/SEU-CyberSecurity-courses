#include <bits/stdc++.h>
using namespace std;

struct Node
{
    bool ltag,rtag;
    int data;
    Node *lchild,*rchild;
    Node()
    {
        ltag=rtag=false;
        data=-1;
        lchild=rchild=nullptr;
    }
};

class TBT
{
public:
    TBT();
    void addHeader();                       // ����
    void print();                           // �������
private:
    Node *create();
    void threaded(Node *cur, Node *& pre);  // ������
    Node *getSuc(Node *node);               // ���غ��
    Node *getPre(Node *node);               // ����ǰ��
    Node *header;  							// ͷ���
    Node *root;                             // �����
};

TBT::TBT()
{
    header=new Node;
    root=create();
}

Node *TBT::create()
{
    Node *p=nullptr;
    int x;
    scanf("%d",&x);
    if (x==-1) p=nullptr;
    else
    {
        p=new Node;
        p->data=x;
        p->lchild=create();
        p->rchild=create();
    }
    return p;
}

void TBT::threaded(Node *cur, Node *& pre)
{
    if (cur==nullptr) return;
    else
    {
        threaded(cur->lchild,pre);//������ 
        if (cur->lchild==nullptr)//��ǰ�ڵ� 
        {
            cur->ltag=true;
            cur->lchild=pre;
        }
        if (cur->rchild==nullptr) cur->rtag=true;
        if (pre->rtag) pre->rchild=cur;
        pre=cur;
        threaded(cur->rchild, pre);//������ 
    }
}

void TBT::addHeader()
{
    header->ltag=true;
    header->rtag=true;
    header->lchild=header->rchild=header;
    Node *pre=header;
    threaded(root, pre);//������
    pre->rtag=true;
    pre->rchild=header;
    header->lchild=pre;
}

Node *TBT::getSuc(Node *node)
{
    if (node->rtag) return node->rchild;
    Node *p=node->rchild;
    while (p->ltag==false) p=p->lchild;
    return p;
}

Node *TBT::getPre(Node *node)
{
    if (node->ltag) return node->lchild;
    Node *p=node->lchild;
    while (p->rtag==false) p=p->rchild;
    return p;
}

void TBT::print()
{
    cout<<"�������Ϊ��";
    Node *p=header->rchild;
    while (p!=header)
    {
    	printf("%d ",p->data);
        p=getSuc(p);
    }
}

int main()
{
    TBT Tree;
    Tree.addHeader();
    Tree.print();
}
