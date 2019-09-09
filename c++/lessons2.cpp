/*线性表-顺序结构-顺序表*/
/*#include <iostream>
using namespace std;

#define ok 0
#define error -1

//顺序表类定义
class SeqList
{
private:
    int *list;
    int maxsize;
    int size;
public:
    SeqList();
    SeqList(int n);
    ~SeqList();
    int list_size();
    int list_insert(int i, int item);
    int list_del(int i);
    int list_get(int i);
    void list_display();
};

SeqList::SeqList()
{
    maxsize = 1000;
    size = 0;
    list = new int[maxsize];
}

SeqList::~SeqList()
{
    delete []list;
}

SeqList::SeqList(int n)
{
    maxsize = 1000;
    size = n;
    list = new int[maxsize];
    for(int i = 0; i < n; i++) {
        cin >> list[i];
    }
}

int SeqList::list_size()
{
    return size;
}

int SeqList::list_insert(int i, int item)
{
    int j;
    if(i < 1 || i > size)
    {
        return error;
    }
    for(j = size - 1;j >= i - 1;j --)
    {
        list[j + 1] = list[j];
    }
    list[i - 1] = item;
    size++;
    return ok;
}

int SeqList::list_del(int i)
{
    int *q;
    if(i < 1 || i > size) return error;
    for(q = list + i - 1; q <= list + size; q++ )
    {
        *q = *(q+1);
    }
    size --;
    return ok;
}

int SeqList::list_get(int i)
{
    if(i < 1 || i > size) return error;
    else
    {
        cout<<list[i - 1];
        return ok;
    }
}

void SeqList::list_display()
{
    int i;
    cout<<this->list_size()<<' ';
    for(i = 0;i < size;i ++)
    {
        cout<<list[i]<<' ';
    }
    cout<<endl;
}

int main()
{
    int n;
    cin>>n;
    SeqList newList(n);
    newList.list_display();
    int insert1, insert2, item1, item2;
    cin>>insert1>>item1;
    if(newList.list_insert(insert1, item1)) cout<<"error"<<endl;
    else newList.list_display();
    cin>>insert2>>item2;
    if(newList.list_insert(insert2, item2)) cout<<"error"<<endl;
    else newList.list_display();
    int delete1, delete2;
    cin>>delete1;
    if(newList.list_del(delete1)) cout<<"error"<<endl;
    else newList.list_display();
    cin>>delete2;
    if(newList.list_del(delete2)) cout<<"error"<<endl;
    else newList.list_display();
    int get1, get2;
    cin>>get1;
    if(newList.list_get(get1)) cout<<"error"<<endl;
    cin>>get2;
    if(newList.list_get(get2)) cout<<"error"<<endl;
    return 0;
};
*/
/*
#include <iostream>
using namespace std;

class SeqList
{
private:
    int *list;
    int maxsize;
    int size;
public:
    SeqList();
    SeqList(int n);
    ~SeqList();
    int list_size();
    void multiinsert(int i, int n, int item[]);
    void multidel(int i, int n);
    void list_display();
};


SeqList::SeqList()
{
    maxsize = 1000;
    size = 0;
    list = new int[maxsize];
}

SeqList::~SeqList()
{
    delete []list;
}

SeqList::SeqList(int n)
{
    maxsize = 1000;
    size = n;
    list = new int[maxsize];
    for(int i = 0; i < n; i++) {
        cin >> list[i];
    }
}

int SeqList::list_size()
{
    return size;
}

void SeqList::multiinsert(int i, int n, int item[])
{
    int num, j;
    j = 0;
    for(num = size - 1;num >= i - 1;num--)
    {
        list[num + n] = list[num];
    }
    for(num = i - 1;num < i + n - 1;num++)
    {
        list[num] = item[j];
        j++;
    }
    size += n;
}

void SeqList::multidel(int i, int n)
{
    int j;
    for(j = i - 1;j < i + n - 1;j ++)
    {
        list[j] = list[j + n];
    }
    size -= n;
}


void SeqList::list_display()
{
    int i;
    cout<<this->list_size()<<' ';
    for(i = 0;i < size;i ++)
    {
        cout<<list[i]<<' ';
    }
    cout<<endl;
}

int main()
{
    int n,i,k,j,*item;
    cin >> n;
    SeqList newList(n);
    newList.list_display();
    cin >> i >> k;
    item = new int[k];
    for(j = 0;j < k;j++)
    {
        cin >> item[j];
    }
    newList.multiinsert(i, k, item);
    newList.list_display();
    cin >> i >> k;
    newList.multidel(i, k);
    newList.list_display();
    return 0;
}
*/

/*
#include <iostream>
using namespace std;


class SeqList
{
private:
    int *list;
    int maxsize;
    int size;
public:
    SeqList();
    SeqList(int n);
    ~SeqList();
    int *return_list();
    int list_size();
    void MergeList(SeqList L1, SeqList L2);
    void list_display();
};


SeqList::SeqList()
{
    maxsize = 1000;
    size = 0;
    list = new int[maxsize];
}

SeqList::~SeqList()
{
    delete []list;
}

SeqList::SeqList(int n)
{
    maxsize = 1000;
    size = n;
    list = new int[maxsize];
    for(int i = 0; i < n; i++) {
        cin >> list[i];
    }
}

int *SeqList::return_list()
{
    return list;
}

int SeqList::list_size()
{
    return size;
}

void SeqList::list_display()
{
    int i;
    cout<<this->list_size()<<' ';
    for(i = 0;i < size;i ++)
    {
        cout<<list[i]<<' ';
    }
    cout<<endl;
}

void SeqList::MergeList(SeqList L1, SeqList L2)
{
    int *p1 = L1.return_list();
    int *p2 = L2.return_list();
    int *p3 = list;
    size = L1.list_size() + L2.list_size();
    int *p1_last = L1.return_list() + L1.list_size() - 1;
    int *p2_last = L2.return_list() + L2.list_size() - 1;
    while(p1 <= p1_last && p2 <= p2_last)
    {
        if(*p1 < *p2) *p3++ = *p1++;
        else *p3++ = *p2++;
    }
    while(p1 <= p1_last) *p3++ = *p1++;
    while(p2 <= p2_last) *p3++ = *p2++;
}

int main()
{
    int n;
    cin >> n;
    SeqList list1(n);
    cin >> n;
    SeqList list2(n);
    SeqList list3;
    list3.MergeList(list1, list2);
    list3.list_display();
    return 0;
}

*/
#include <iostream>
using namespace std;

class SeqList
{
private:
    int *list;
    int maxsize;
    int size;
public:
    SeqList();
    SeqList(int n);
    ~SeqList();
    int list_size();
    void list_display();
    void shift(int d, int num);
};

SeqList::SeqList()
{
    maxsize = 1000;
    size = 0;
    list = new int[maxsize];
}

SeqList::~SeqList()
{
    delete []list;
}

SeqList::SeqList(int n)
{
    maxsize = 1000;
    size = n;
    list = new int[maxsize];
    for(int i = 0; i < n; i++) {
        cin >> list[i];
    }
}

int SeqList::list_size()
{
    return size;
}

void SeqList::list_display()
{
    int i;
    for(i = 0;i < size;i ++)
    {
        cout<<list[i]<<' ';
    }
    cout<<endl;
}

void SeqList::shift(int d, int num)
{
    int sub, time, i;
    if(d == 0)
    {
        for(time = 0;time < num;time++)
        {
            sub = list[0];
            for(i = 1;i < size;i++)
            {
                list[i - 1] = list[i];
            }
            list[size - 1] = sub;
        }
    } 
    else if(d == 1)
    {
        for(time = 0;time < num;time++)
        {
            sub = list[size - 1];
            for(i = size - 1;i >= 0;i--)
            {
                list[i] = list[i - 1];
            }
            list[0] = sub;
        }
    }
}

int main()
{
    int n, direction, num;
    cin>>n;
    SeqList list1(n);
    list1.list_display();
    for(n = 0;n < 2;n++)
    {
        cin>>direction>>num;
        list1.shift(direction, num);
        list1.list_display();
    }
    return 0;
}