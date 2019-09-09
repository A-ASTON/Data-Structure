// #include <iostream>
// #include <iomanip>
// #include <math.h>
// using namespace std;
// class Point
// {
//     double x,y;
// public:
//     Point();
//     Point(double x_value, double y_value);
//     Point(const Point &obj);
//     ~Point();
//     double getX();
//     double getY();
//     void setXY(double x1,double y1){x=x1;y=y1;}
//     void setX(double x_value);
//     void setY(double y_value);
//     double getDisTo(const Point &p);
// };

// Point::Point()
// {
//     x = 0;
//     y = 0;
//     cout<<"Coustructor."<<endl;
// }

// Point::Point(double x_value, double y_value)
// {
//     x = x_value;
//     y = y_value;
// }

// Point::Point(const Point &obj)
// {
//     x = obj.x;
//     y = obj.y;
// }

// Point::~Point()
// {
//     cout<<"Distructor."<<endl;
// }

// double Point::getDisTo(const Point &p)
// {
//     double dis;
//     dis = pow((pow((x-p.x),2) + pow((y-p.y), 2)), 0.5);
//     return dis;
// }

// int main()
// {
//     int i, t;
//     cin>>t;
//     for(i = 0;i < t; i++)
//     {
//         int n,j,k, first, second;
//         double longest = 0;
//         double temp;
//         cin>>n;
//         Point *p = new Point[n];
//         for(j = 0;j < n; j++)
//         {
//             double x, y;
//             cin>>x>>y;
//             p[j].setXY(x, y);
//         }
//         for(j = 0;j < n-1;j++)
//         {

//             for(k = j;k < n; k++)
//             {
//                 temp = p[j].getDisTo(p[k]);
//                 if(temp > longest)
//                 {
//                     longest = temp;
//                     first = j;
//                     second = k;
//                 }
//             }
            
//         }
//         cout<<"The longest distance is "<<setprecision(4)<<longest<<", between p["<<first<<"] and p["<<second<<"]."<<endl;
//         delete [] p;
//     }
//     return 0;
// }

/*
#include <iostream>

using namespace std;

class Date
{
    private:
        int year;
        int month;
        int day;
    public:
        Date(int y, int m, int d){ year = y; month = m; day = d;}
        void print(){ cout<<year<<"."<<month<<"."<<day<<endl; }
};



class Phone
{
    private:
        char type;
        int number;
        int state;
        Date *date;
    public:
        Phone(char t, int n, int s)
        { 
            type = t;
            number = n;
            state = s;
            date = NULL;
            cout<<"Construct a new phone "<<number<<endl;
        }
        Phone(const Phone &obj)
        {
            type = 'D';
            number = obj.number + 'X';
            state = obj.state;
            date = obj.date;
            cout<<"Construct a copy of phone "<<number<<endl;
            char *stateString = "";
            if(state == 1)
            {
                stateString = "在用";
            } else if (state == 2)
            {
                stateString = "未用";
            } else
            {
                stateString = "停用";
            }
            cout<<"类型=备份||号码="<<number<<"||State="<<stateString<<endl;
        }
        void print(){
            char *typeString = "";
            if(type == 'A')
            {
                typeString = "机构";
            } else if (type == 'B')
            {
                typeString = "企业";
            } else
            {
                typeString = "个人";
            }
            char *stateString = "";
            if(state == 1)
            {
                stateString = "在用";
            } else if (state == 2)
            {
                stateString = "未用";
            } else
            {
                stateString = "停用";
            }
            cout<<"类型="<<typeString<<"||号码="<<number<<"||State="<<stateString<<endl;
            }
        void stop(int y, int m, int d){
            char *typeString = "";
            if(type == 'A')
            {
                typeString = "机构";
            } else if (type == 'B')
            {
                typeString = "企业";
            } else
            {
                typeString = "个人";
            }
            state = 3;
            Date date(y, m, d);
            cout<<"Stop the phone "<<number<<endl;
            cout<<"类型="<<typeString<<"||号码="<<number<<"||State=停用||"<<"停机日期=";
            date.print();
            cout<<endl;
        }

};

int main()
{
    int t, i;
    cin>>t;
    for(i = 0;i < t;i++)
    {
        char type;
        int num, s, y, m, d;
        cin>>type>>num>>s>>y>>m>>d;
        Phone p1(type, num, s);
        Phone p2 = p1;
        p1.stop(y, m, d);
        cout<<"----"<<endl;
    }
    return 0;
}*/
/*
#include <iostream>
using namespace std;

void createArray()
{
    char type;
    int length;
    cin>>type>>length;
    if(type == 'I')
    {
        int *array = new int[length];
        int i, average = 0;
        for(i = 0;i < length;i ++)
        {
            cin>>*array;
            average += *array;
            array++;
        }
        cout<<average/length<<endl;
    } else if(type == 'C')
    {
        char *array = new char[length];
        int i;
        char max;
        cin>>max;
        *array++ = max;
        for(i = 0;i < length-1;i ++)
        {
            cin>>*array;
            if (*array > max)
            {
                max = *array;
            }
            array++;
        }
        cout<<max<<endl;
    } else if(type == 'F')
    {
        float *array = new float[length];
        int i;
        float min;
        cin>>min;
        *array++ = min;
        for(i = 0;i < length - 1;i ++)
        {
            cin>>*array;
            if (*array < min)
            {
                min = *array;
            }
        }
        cout<<min<<endl;
    }
}

int main()
{
    int t, i;
    cin>>t;
    for(i = 0;i < t;i++)
    {
        createArray();
    }
    return 0;
}
*/
/*

#include <iostream>

using namespace std;

class Martrix
{
private:
    int row;
    int column;
    int body[2][3];
public:
    Martrix(){row = 2; column = 3;}
    void setMartrix();
    void printRevolve();
    void print();
};

void Martrix::setMartrix(){
    int i, j;
    for(i = 0;i < row;i ++)
    {
        for(j = 0;j < column;j ++)
        {
            cin>>body[i][j];
        }
    }
}

void Martrix::printRevolve(){
    cout<<*(*body+2)<<" "<<*(*(body+1)+2)<<endl;
    cout<<*(*body+1)<<" "<<*(*(body+1)+1)<<endl;
    cout<<*(*body)<<" "<<*(*(body+1))<<" "<<endl;
}


void Martrix::print()
{
    int i, j;
    for(i = 0;i < row;i ++)
    {
        for(j = 0;j < column;j ++)
        {
            cout<<body[i][j];
        }
    }
}

int main()
{
    int t, i;
    cin>>t;
    for (i = 0; i < t; i++)
    {
        Martrix newMartrix;
        newMartrix.setMartrix();
        newMartrix.printRevolve();
    }
}

*/

#include <iostream>

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
    SqeList();
    ~SeqList();
    int list_size();
    int list_insert(int i, int item);
    int list_del(int i);
    int list_get(int i);
    void list_display();
};

SqeList::SeqList()
{
    maxsize = 1000;
    ssize = 0;
    list = new int[maxsize];
}

SeqList::~SeqList()
{
    delete []list;
}