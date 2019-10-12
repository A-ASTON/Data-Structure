#include <iostream>
#include<queue>
#include<string>
#include<map>

using namespace std;
//×é¶ÓÁÐ
int main()
{
    int i,j,t,value;
    map <int,int> ele;
    string oper;
    cin>>t;
    queue <int> qList[t];
    for(i = 0; i < t; i++)
    {
        cin>>j;
        while(j--)
        {
            cin>>value;
            ele[value] = i;
        }
    }
    do
    {
       cin>>oper;
       if(!oper.compare("ENQUEUE"))
       {
           cin>>value;
           for(i = 0; i < t; i++)
           {
               if(qList[i].empty() || ele[qList[i].front()] == ele[value])
               {
                   qList[i].push(value);
                   break;
               }
           }
       }else if(!oper.compare("DEQUEUE"))
       {
           for(i = 0; i < t; i++)
           {
               if(!qList[i].empty())
               {
                   cout<<qList[i].front()<<endl;
                   qList[i].pop();
                   break;
               }
           }
       }
    }while(oper.compare("STOP"));


}
