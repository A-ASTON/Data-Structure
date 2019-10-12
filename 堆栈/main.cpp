/* ¶ÑÕ»£ºÄæÐòÊä³ö
#include <iostream>
#include <stack>
#include "string"
using namespace std;

int main()
{
    int i, t;
    cin>>t;
    for(i = 0;i < t;i++)
    {
        string str;
        stack <char> s;
        cin>>str;
        int j, len = str.length();
        for(j = 0;j < len;j++)
        {
            s.push(str[j]);
        }
        for(j = 0;j < len;j++)
        {
            cout<<s.top();
            s.pop();
        }
        cout<<endl;
    }
    return 0;
}
*/

/*ÐÐ±à¼­
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i = 0;i < t;i++)
    {
        string str;
        cin>>str;
        int j, len = str.length();
        stack <char> result;
        for(j = 0;j < len;j++)
        {
            if(str[j] == '#')
            {
                if(!result.empty())
                {
                    result.pop();
                }
                else
                {
                    continue;
                }
            }
            else
            {
                result.push(str[j]);
            }
        }
        if(result.empty())
        {
            cout<<"NULL"<<endl;
        }
        else
        {
            stack <char> final_result;
            int stlen = result.size();
            for(j = 0;j < stlen;j++)
            {
                final_result.push(result.top());
                result.pop();
            }
            for(j = 0;j < stlen;j++)
            {
                cout<<final_result.top();
                final_result.pop();
            }
            cout<<endl;
        }
    }
    return 0;
}
*/

/* ¶ÑÕ»£ºÀ¨ºÅÆ¥Åä
#include <iostream>
#include <stack>
#include "string"
using namespace std;
int braceMatching(string expression);

int main()
{
    int i, t;
    cin>>t;
    for(i = 0;i < t;i++)
    {
        string expression;
        cin>>expression;
        int result = braceMatching(expression);
        if(result)
        {
            cout<<"ok"<<endl;
        }
        else
        {
            cout<<"error"<<endl;
        }
    }
    return 0;
}

int braceMatching(string expression)
{
    int j, len = expression.length();
    stack <char> test;
    for(j = 0;j < len;j++)
    {
        switch(expression[j])
        {
        case '(':
        case '[':
        case '{':
            test.push(expression[j]);
            break;
        case ')':
            if(test.top() == '(')
            {
                test.pop();
            }
            else
            {
                return 0;
            }
            break;
        case ']':
            if(test.top() == '[')
            {
                test.pop();
            }
            else
            {
                return 0;
            }
            break;
        case '}':
            if(test.top() == '{')
            {
                test.pop();
            }
            else
            {
                return 0;
            }
            break;
        default:
            continue;
        }
    }
    if(test.empty())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
*/
/*ÊýÖÆ×ª»»
#include <iostream>
#include <iomanip>
#include <stack>
#include <queue>

using namespace std;
void changeSystem(double n, int k);

int main()
{
    int i, t;
    cin>>t;
    for(i = 0;i < t;i++)
    {
        double n;
        int k;
        cin>>n>>k;
        changeSystem(n, k);
        cout<<endl;
    }
    return 0;
}

void changeSystem(double n, int k)
{
    int z = (int) n;
    double s = n - z;
    stack <int> zh;
    queue <double> sm;
    while(z != 0)
    {
        zh.push(z % k);
        z /= k;
    }
    while(s != 0)
    {
        s *= k;
        int temp = (int) s;
        sm.push(temp);
        s = s - temp;
    }
    if(!zh.empty())
    {
        int stlen = zh.size(), j;
        for(j = 0;j < stlen;j++)
        {
            if(k == 16)
            {
                switch (zh.top())
                {
                    case 10: cout<<'A';break;
                    case 11: cout<<'B';break;
                    case 12: cout<<'C';break;
                    case 13: cout<<'D';break;
                    case 14: cout<<'E';break;
                    case 15: cout<<'F';break;
                }
                zh.pop();
            }
            else
            {
                cout<<zh.top();
                zh.pop();
            }
        }
    }
    if(!sm.empty())
    {
        int qulen = sm.size(), j, t;
        cout<<'.';
        if(qulen > 3)
        {
            t = 3;
            for(j = 0;j < t;j++)
            {
                cout<<sm.front();
                sm.pop();
            }
        }
        else
        {
            t = qulen;
            for(j = 0;j < t;j++)
            {
                cout<<sm.front();
                sm.pop();
            }
            for(j = 0;j < 3 - qulen;j++)
            {
                cout<<0;
            }
        }
    }
}
*/
/*ÃÔ¹¬Çó½â
#include <iostream>
#include <stack>


using namespace std;
struct pos
{
    pos(int x, int y)
    {
      this->xp = x;
      this->yp = y;
    };
    int xp;
    int yp;
};

int main()
{
    int i, t;
    cin>>t;
    for(i = 0;i < t;i++)
    {
        int n,k,j;
        stack <pos> path;
        struct pos cpos(0,0);
        cin>>n;
        int maze[n][n];
        for(k = 0;k < n;k++)
        {
            for(j = 0;j < n;j++)
            {
                cin>>maze[k][j];
            }
        }
        do{
            if(maze[cpos.xp][cpos.yp] == 0)
            {
                path.push(cpos);
                maze[cpos.xp][cpos.yp] = 1;
                if(cpos.xp == n - 1 && cpos.yp == n - 1)
                {
                    break;
                }
                else
                {
                    cpos.xp++;
                }
            }
            else
            {
                cpos = path.top();
                if(!path.empty())
                {
                    if(maze[cpos.xp][++cpos.yp] == 0)
                    {
                        continue;
                    }
                    else if(maze[--cpos.xp][cpos.yp] == 0)
                    {
                        continue;
                    }
                    else if(maze[cpos.xp][--cpos.yp] == 0)
                    {
                        continue;
                    }
                    else
                    {
                        path.pop();
                        cpos = path.top();
                    }
                }
            }

        }while(!path.empty());

        if (!path.empty())
        {
            int i=0,len;
            stack <pos> path1;
            len = path.size();
            for(i = 0;i < len;i++)
            {
                path1.push(path.top());
                path.pop();
            }
            i = 0;
            while (!path1.empty())
            {
                cpos = path1.top();
                if ( (++i)%4 == 0 )
                    cout<<'['<<cpos.xp<<','<<cpos.yp<<']'<<"--"<<endl;
                else
                    cout<<'['<<cpos.xp<<','<<cpos.yp<<']'<<"--";
                    path1.pop();
            }
            cout<<"END"<<endl;
        }
        else
        cout<<"no path"<<endl; //ÕÒ²»µ½Â·¾¶Êä³öno path
    }
    return 0;
}
*/
/*ÅÅ¶ÓÓÎÏ·*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main()
{
    int i,len;
    char boy;
    string children;
    stack<int> boys;
    cin>>children;
    len = children.length();
    boy = children[0];
    for(i = 0; i < len; i++)
    {
        if(children[i] != boy)
        {
            cout<<i<<" "<<boys.top()<<endl;
            boys.pop();
        }
        else boys.push(i);
    }
}
