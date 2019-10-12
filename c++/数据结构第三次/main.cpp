/*
// DS单链表---类实现
// 交换结点
#include <iostream>
using namespace std;
#define ok 0
#define error -1


//链表结点类定义
class ListNode
{
public:
    int data;
    ListNode * next;
    ListNode() {  next = NULL; }
};

//带头结点的单链表类定义
class LinkList
{
public:
    ListNode * head;
    int len;
    LinkList();
    ~LinkList();
    ListNode * LL_index(int i);//返回第i个结点的指针，如果不存在返回NULL
    int LL_create(int i, int item); //初始化链表
    int swap(int pa, int pb);
    void LL_display(); //输出单链表的内容
};

LinkList::LinkList()
{
    head = new ListNode();
    len = 0;
}

LinkList::~LinkList()  //链表回收，逐个结点回收
{
    ListNode *p, *q;
    p = head;
    while (p != NULL) {
        q = p;
        p = p->next;
        delete q;
    }
    len = 0;
    head = NULL;
}

ListNode * LinkList::LL_index(int i) //返回第i个结点的指针
{
    ListNode *p;
    int j = 0;
    p = head;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    if(j != i)
    {
        return NULL;
    }
    return p;
}


int LinkList::LL_create(int i, int item) //初始化链表
{
    int j= 0;
    ListNode *p;
    p= head;
    while(p&&j< i- 1){
        p= p->next ;
        j++;
    }
    ListNode *s = new ListNode();
    s->data = item;
    p->next = s;
    len++;
}

int LinkList::swap(int pa,int pb)
{
    if(pa < 1 || pa > len || pb < 1 || pb > len)
    {
        return error;
    }
    ListNode *p1, *p2, *p3, *p4, *temp;
    temp = new ListNode();
    p1 = LL_index(pa - 1);
    p2 = LL_index(pb - 1);
    p3 = LL_index(pa + 1);
    p4 = LL_index(pb + 1);
    p1->next->next = p4;
    p2->next->next = p3;
    temp = p1->next;
    p1->next = p2->next;
    p2->next = temp;
    return ok;
}

void LinkList::LL_display()
{
    ListNode *p;
    p = head->next;
    while(p)
    {
        cout<< p->data <<' ';
        p = p->next;
    }
    cout<<endl;
}



int main()
{
    int n,i;
    int item;
    cin>>n;
    LinkList linkList;
    for(i = 0;i < n;i++)
    {
        cin>>item;
        linkList.LL_create(i+1, item);
    }
    linkList.LL_display();
    for(i = 0;i < 2;i++)
    {
        int p1,p2;
        cin>>p1>>p2;
        if(linkList.swap(p1, p2)){ cout<<"error"<<endl; }
        else{ linkList.LL_display(); }
    }
    return 0;
}
*/

/*
//链表合并
#include <iostream>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode * next;
    ListNode() {  next = NULL; }
};

//带头结点的单链表类定义
class LinkList
{
public:
    ListNode * head;
    int len;
    LinkList();
    ~LinkList();
    int LL_create(int i, int item); //初始化链表
    int LL_merge(ListNode *La, ListNode *Lb);
};

LinkList::LinkList()
{
    head = new ListNode();
    len = 0;
}

LinkList::~LinkList()  //链表回收，逐个结点回收
{
    ListNode *p, *q;
    p = head;
    while (p != NULL) {
        q = p;
        p = p->next;
        delete q;
    }
    len = 0;
    head = NULL;
}

int LinkList::LL_create(int i, int item) //初始化链表
{
    int j= 0;
    ListNode *p;
    p = head;
    while(p&&j< i- 1){
        p = p->next ;
        j++;
    }
    ListNode *s = new ListNode();
    s->data = item;
    p->next = s;
    len++;
}

int LinkList::LL_merge(ListNode *La, ListNode *Lb)
{
    ListNode *pa, *pb, *pc;
    pc = head;
    pa = La->next;
    pb = Lb->next;
    while(pa && pb){
        if(pa->data <= pb->data)
        {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }
        else
        {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
        pc->next = pa?pa : pb;
    }
    pc = head->next;
    while(pc)
    {
        cout<< pc->data <<' ';
        pc = pc->next;
    }
    cout<<endl;
    return 0;
}

int main()
{
    int n,i,item;
    cin>>n;
    LinkList linkList1;
    for(i = 0;i < n;i++)
    {
        cin>>item;
        linkList1.LL_create(i+1, item);
    }
    cin>>n;
    LinkList linkList2;
    for(i = 0;i < n;i++)
    {
        cin>>item;
        linkList2.LL_create(i+1, item);
    }
    LinkList linkList3;
    linkList3.LL_merge(linkList1.head, linkList2.head);
    return 0;
}
*/


//多项式相加
#include <iostream>
using namespace std;

class ListNode
{
public:
    int coefficient;
    int index;
    ListNode * next;
    ListNode() { next = NULL; }
};

class Polynomial
{
public:
    int len;
    ListNode * head;
    Polynomial(){ len = 0; head = new ListNode; }
    ~Polynomial(){
        ListNode *p, *q;
        p = head;
        while (p != NULL) {
            q = p;
            p = p->next;
            delete q;
        }
        head = NULL;
    }
    void P_create(int i, int c, int index);
    void P_display();
    void P_merge(ListNode *P1, ListNode *P2);
};

void Polynomial::P_create(int i, int c, int index)
{
    ListNode * p;
    int j = 0;
    p = head;
    while(p && j < i - 1)
    {
        p = p->next;
        j++;
    }
    ListNode * s;
    s = new ListNode();
    s->coefficient = c;
    s->index = index;
    p->next = s;
    len++;
}

void Polynomial::P_display()
{
    int j = 1;
    ListNode * p;
    p = head->next;
    while(p && j <= len)
    {
        if(p->coefficient > 0)
        {
            if(p->index > 0)
            {
                cout<<p->coefficient<<"x^"<<p->index;
            }
            else if(p->index == 0)
            {
                cout<<p->coefficient;
            }
            else
            {
                cout<<p->coefficient<<"x^("<<p->index<<')';
            }
        }
        else if(p->coefficient < 0)
        {
            if(p->index > 0)
            {
                cout<<'('<<p->coefficient<<")x^"<<p->index;
            }
            else if(p->index == 0)
            {
                cout<<'('<<p->coefficient<<')';
            }
            else
            {
                cout<<'('<<p->coefficient<<")x^("<<p->index<<')';
            }
        }
        if(j != len && p->coefficient != 0 && p->next->coefficient != 0)
        {
            cout<<" + ";
        }
        j++;
        p = p->next;
    }
    cout<<endl;
}

void Polynomial::P_merge(ListNode *P1, ListNode *P2)
{
    ListNode *p, *p1, *p2;
    p = new ListNode;
    p = head;
    p1 = P1->next;
    p2 = P2->next;
    while(p1 && p2)
    {
        if(p1->index < p2->index)
        {
            p->next = p1;
            p = p1;
            p1 = p1->next;
        }
        else if(p1->index > p2->index)
        {
            p->next = p2;
            p = p2;
            p2 = p2->next;
        }
        else
        {
            ListNode *temp;
            temp = new ListNode;
            temp->coefficient =  p1->coefficient + p2->coefficient;;
            temp->index = p1->index;
            p->next = temp;
            p = p->next;
            p1 = p1->next;
            p2 = p2->next;
        }
        len++;
    }
    p->next = p1?p1:p2;
    p = p->next;
    while(p)
    {
        len++;
        p = p->next;
    }
    delete P1;
    delete P2;
}

int main()
{
    int i,t;
    cin>>t;
    for(i = 0;i < t;i++)
    {
        int n,k,c,index;
        cin>>n;
        Polynomial p1;
        for(k = 0;k < n;k++)
        {
            cin>>c>>index;
            p1.P_create(k+1, c, index);
        }
        cin>>n;
        Polynomial p2;
        for(k = 0;k < n;k++)
        {
            cin>>c>>index;
            p2.P_create(k+1, c, index);
        }
        Polynomial p3;
        p1.P_display();
        p2.P_display();
        p3.P_merge(p1.head, p2.head);
        p3.P_display();
    }
    return 0;
}






