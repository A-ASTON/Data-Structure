
#include <iostream>
#include <string>
using namespace std;

class myString
{
private:
    string mainstr;
    int Size;

    void GetNext(string p, int next[]);
    int KMPFind(string p, int pos, int next[]);

public:
    myString();
    ~myString();
    myString(string s) {Size = s.length(); mainstr = s;}
    void SetVal(string sp);
    int KMPFindSubstr(string p, int pos);
};

myString::myString()
{
    Size = 0;
    mainstr = "";
}

myString::~myString()
{
    Size = 0;
    mainstr = "";
}

void myString::SetVal(string sp)
{
    mainstr = "";
    mainstr.assign(sp);
    Size = mainstr.length();
}

int myString::KMPFindSubstr(string p, int pos)
{
    int i;
    int L = p.length();
    int *next = new int[L];
    GetNext(p, next);
    for(i = 0; i<L; i++)
        cout<<next[i]<<' ';
    cout<<endl;
    int v = -1;
    v = KMPFind(p, pos, next);
    delete[] next;
    return v;
}

void myString::GetNext(string p, int next[])
{
    int j = -1, k = 0;
    next[0] = -1;
    while(k < Size - 1)
    {
        if(j == -1 || p[k] == p[j])
        {
            ++k;
            ++j;
            next[k] = j;
        }
        else j = next[j];
    }
}

int myString::KMPFind(string p, int pos, int next[])
{
    int i = pos, j = -1;
    while(i < (int)Size && j < (int)p.length())
    {
        if(j == -1 || p[j] == mainstr[i])
        {
            j++;
            i++;
        }
        else j = next[j];
    }
    if(j == (int)p.length())
    {
        return i - j;
    }
    else
    {
        return -1;
    }
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string main_string;
        cin>>main_string;
        myString mStr(main_string);
        string mode_string;
        cin>>mode_string;
        int result = mStr.KMPFindSubstr(mode_string, 0);
        if(result == -1) cout<<0<<endl;
        else cout<<result+1<<endl;
    }
    return 0;
}

/*替换串
#include <iostream>
#include <string>

using namespace std;

class myString {
private:
    string mainstr;
    int size;

    void GetNext(string p,int next[]) {
        next[0] = -1;
        next[1] = 0;
        int L = p.length();
        int temp = 0;
        for(int i = 2; i < L; i++) {
            while(p[i - 1] != p[temp] && temp > 0) {
                temp = next[temp];
            }
            if(p[i - 1] == p[temp]) {
                temp++;
            }
            next[i] = temp;
        }
    }
    int KMPFind(string p, int pos, int next[]) {
        int i=pos,j=0;

        while(mainstr[i] != '\0' && p[j] != '\0') {
            if(mainstr[i] == p[j]) {
                ++i;
                ++j;
            }
            else {
                j = next[j];
            }
            if(j == -1) {
                ++i;
                ++j;
            }
        }
        if(p[j] == '\0')
            return i - j;
        else
            return -1;
    }

public:
    myString() {size = 0; mainstr = "";}
    myString(string s) {size = s.length(); mainstr = s;}
    ~myString() {size = 0; mainstr = "";}
    void SetVal(string sp) {
        mainstr = "";
        mainstr.assign(sp);
        size  = mainstr.length();
    }
    int KMPFindSubstr(string p, int pos) {
        int i;
        int L = p.length();
        int *next = new int[L];
        GetNext(p,next);
        int v = -1;
        v = KMPFind(p, 0, next);

        delete [] next;

        return v;
    }
};




int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string templet;
        cin >> templet;
        string target;
        cin >> target;
        string subStr;
        cin >> subStr;
        myString str(templet);
        int result = str.KMPFindSubstr(target, 0);
        cout<<templet<<endl;
        if(result != -1)
        {
            templet.erase(result, target.length());
            templet.insert(result, subStr);
            cout<<templet<<endl;
        }
        else
        {
            cout<<templet<<endl;
        }
    }

    return 0;
}
*/

/* 最长的真前后缀
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        string str;
        cin>>str;
        if(str.length() < 2)
        {
            cout<<"empty"<<endl;
            continue;
        }
        string Fchildren[str.length() - 1];
        string Bchildren[str.length() - 1];
        string result = "empty";
        for(int i = 0; i < str.length() - 1; i++)
        {
            Fchildren[i] = str.substr(0, i + 1);
            Bchildren[i] = str.substr(str.length()-1-i, i + 1);
            if(Fchildren[i] == Bchildren[i])
            {
                result = Bchildren[i];
            }
        }
        cout<<result<<endl;
    }

    return 0;
}
*/

/*最长重复子串
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string test;
        cin>>test;
        string subStr;
        int i,j;
        int max = -1;
        int temp = -1;
        for(i = 0;i < test.length();i++)
        {
            for(j = 1;j <= (test.length() - i) / 2;j++)
            {
                subStr = test.substr(i, j);
                if(test.substr(i+j,test.length() - i - j).find(subStr) != string::npos)
                {
                    temp = j;
                    if(temp > max) max = temp;
                }
            }
        }
        cout<<max<<endl;
    }

    return 0;
}
*/
/*
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        string str;
        cin>>str;
        int index = -1;
        if(str.length() < 2)
        {
            cout<<0<<endl;
            continue;
        }
        string Fchildren[str.length() - 1];
        string Bchildren[str.length() - 1];
        for(int i = 0; i < str.length() / 2; i++)
        {
            Fchildren[i] = str.substr(0, i + 1);
            Bchildren[i] = str.substr(str.length()-1-i, i + 1);
            if(Fchildren[i] == Bchildren[i])
            {
                index = i;
            }
        }
        if(str.substr(str.length()-1-index,index + 1).find(str.substr(index+1,str.length()-2-2*index)) != string::npos )
        {
            cout<<0<<endl;
        }
        else
        {
            cout<<str.length()-2-2*index<<endl;
        }
    }

    return 0;
}
*/
/*
#include<stdio.h>
#include<string.h>
using namespace std;
const int maxn = 1e5 + 10;
char mo[maxn];
int Next[maxn], moL, nCase;
inline void GetNext()
{
    int i = 0, j = -1;
    Next[i] = j;
    while(i < moL){
        while( j!=-1 && mo[i]!=mo[j]) j = Next[j];
        Next[++i] = ++j;
    }
}
int ans()
{
    GetNext();
    if(Next[moL] == 0) return moL;

    int Period_len = moL - Next[moL];
    int Remain = moL % Period_len;

    if(Remain == 0) return 0;
    return Period_len - Remain;
}
int main(void)
{
    scanf("%d", &nCase);
    while(nCase--){
        scanf("%s", mo);
        moL = strlen(mo);
        printf("%d\n", ans());
    }
    return 0;
}
*/
