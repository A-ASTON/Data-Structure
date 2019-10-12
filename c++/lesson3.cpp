// // DS单链表---类实现
// #include <iostream>
// using namespace std;
// #define ok 0
// #define error -1


// //链表结点类定义
// class ListNode
// {
// public:
//     int data;
//     ListNode * next;
//     ListNode() {  next = NULL; }
// };

// //带头结点的单链表类定义
// class LinkList
// {
// public:
//     ListNode * head;
//     int len;
//     LinkList();
//     ~LinkList();
//     ListNode * LL_index(int i);//返回第i个结点的指针，如果不存在返回NULL
//     int LL_create(int i, int item); //初始化链表
//     int LL_get(int i); //获取第i个结点的数据
//     int LL_insert(int i, int item); //把数值item插入第i个位置
//     int LL_del(int i); //删除第i个结点
//     void LL_display(); //输出单链表的内容
// };

// LinkList::LinkList()
// {
//     head = new ListNode();
//     len = 0;
// }

// LinkList::~LinkList()  //链表回收，逐个结点回收
// {
//     ListNode *p, *q;
//     p = head;
//     while (p != NULL) {
//         q = p;
//         p = p->next;
//         delete q;
//     }
//     len = 0;
//     head = NULL;
// }

// ListNode * LinkList::LL_index(int i) //返回第i个结点的指针
// {
//     ListNode *p;
//     int j = 1;
//     p = head->next;
//     while (p && j < i)
//     {
//         p = p->next;
//         j++;
//     }
//     if(j != i)
//     {
//         return NULL;
//     }
//     return p;
// }

// int LinkList::LL_get(int i) //获取第i个元素的数据
// {
//     ListNode *p;
//     p = LL_index(i);
//     if(!p)
//     {
//         return error;
//     }
//     cout<<p->next<<endl;
//     return ok;
// }

// int LinkList::LL_create(int i, int item) //初始化链表
// {
//     int j= 0;
//             ListNode *p;
//             p= head;
//             while(p&&j< i- 1){
//                 p= p->next ;
//                 j++;

//             }

//             ListNode *s = new ListNode();
//             s->data = item;
//             p->next = s;
//             len++;
//     // ListNode *p, *q;
//     // q = new ListNode();
//     // p = LL_index(i);
//     // if(i < 1 || i > len + 1) { return error; }
//     // p->data = item;
//     // p->next = q;
//     // len++;
//     // return ok;
// }

// int LinkList::LL_insert(int i, int item) //插入结点
// {
//     ListNode *p, *q;
//     q = new ListNode();
//     p = LL_index(i - 1);
//     if(!p || i < 1 || i > len + 1) { return error; }
//     q->data = item;
//     q->next = p->next;
//     p->next = q;
//     len++;
//     return ok;
// }

// int LinkList::LL_del(int i) //删除结点
// {
//     ListNode *p;
//     p = LL_index(i);
//     if(!p) { return error; }  
//     p->next = p->next->next;
//     return ok;
// }

// void LinkList::LL_display()
// {
//     ListNode *p;
//     p = head->next;
//     while(p)
//     {
//         cout<< p->data <<' ';
//         p = p->next;
//     }
//     cout<<endl;
// }



// int main()
// {
//     int n,i;
//     int item;
//     cin>>n;
//     LinkList linkList;
//     for(i = 0;i < n;i++)
//     {        
//         cin>>item;
//         linkList.LL_create(i+1, item);
//     }
//     linkList.LL_display();
//     for(i = 0;i < 2;i++)
//     {
//         int index, item;
//         cin>>index>>item;
//         if(linkList.LL_insert(index, item)){ cout<<"error"<<endl; }
//         else{ linkList.LL_display(); }
//     }
//     for(i = 0;i < 2;i++)
//     {
//         int index;
//         cin>>index;
//         if(linkList.LL_del(index)){ cout<<"error"<<endl; }
//         else{ linkList.LL_display(); }
//     }
//     for(i = 0;i < 2;i++)
//     {
//         int index;
//         cin>>index;
//         if(linkList.LL_get(index)){ cout<<"error"<<endl; }
//     }
//     return 0;
// }


// DS单链表---类实现
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
    int LL_create(int i, int item); //初始化链表
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

int LinkList::LL_create(int i, int item) //初始化链表
{
    ListNode *p, *q;
    q = new ListNode;
    int j = 0;
    p = head;
    while(p || j < i - 1)
    {
        p = p->next;
        j ++;
    }
    if(j != i - 1){ return error; }
    p->data = item;
    p->next = q;
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
    int n, i, item;
    cin>>n;
    LinkList list;
    list.LL_create(1, 2);
    list.LL_display();
    return 0;
}