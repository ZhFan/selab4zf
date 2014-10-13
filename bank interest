#include <iostream>
using namespace std;
#define maxsize 100
struct bank{
int date;
double rent;
};
struct list{
bank b[maxsize];
int last;
};
void createlist(list &l)
{
    int d,flag=0;
    double r;
    l.last=0;
    while(flag==0)
    {
    cout<<"请输入存款时长对应的存款利率"<<endl;
    cin>>d;
    cin>>r;
    l.b[l.last].date=d;
    l.b[l.last].rent=r;
    l.last++;
    cout<<"结束建表吗？flag=0表示否，flag=其他表示是"<<endl;
    cin>>flag;
    }
}
void insert(list &l)
{
    int d,i,m;
    double r;
    cout<<"请输入您要插入的时长及对应的利率"<<endl;
    cin>>d>>r;
    for(i=0;i<=l.last;i++)
    {
        if(l.b[i].date<d)
        i++;
        else
        break;
    }
    for(m=l.last;m>=i;m--)
    {
        l.b[m+1]=l.b[m];
    }
    l.b[i].date=d;
    l.b[i].rent=r;
    l.last++;
}
void renew (list &l)
{
    int q;
    double p;
    cout<<"请输入您要修改的存款时长及对应的利率"<<endl;
    cin>>q;
    cin>>p;
    int i=0;
    while(i<=l.last)
    {
        if(l.b[i].date==q)
        {
            cout<<"已找到"<<endl;
            l.b[i].rent=p;
        }
        else
        i++;

    }
}
void deletel(list &l)
{
    int d,i=0,p=0;
    cout<<"请输入您要删除的时长及利率"<<endl;
    cin>>d;
    while(i<=l.last)
    {
        if(l.b[i].date==d)
        {
            l.last=l.last-1;
            for(p=i;p<=l.last;p++)
            {
                l.b[p]=l.b[p+1];
            }
        }
        else
        i++;
    }
}
void display(list l)
{
    int i;
    cout<<"存款时长"<<"          "<<"利率"<<endl;
    for(i=0;i<l.last;i++)
    {
        cout<<l.b[i].date<<"        "<<l.b[i].rent<<endl;

    }
}
int main()
{
    list l;
    cout<<"欢迎进入银行利率表管理系统"<<endl;
    cout<<"0.定期存款****************"<<endl;
    cout<<"1.活期存款****************"<<endl;
    cout<<"2本息计算***************"<<endl;
    cout<<"3.显示利率表************"<<endl;
    cout<<"4退出*******************"<<endl;

    int choice,m,flag=0;
    double activerent;
    while(flag==0)
    {
        cout<<"请输入您的选择"<<endl;
        cin>>choice;
    if(choice==0)
    {
        cout<<"0.定期存款****************"<<endl;
        cout<<"请输入活期存款的利率******"<<endl;
        cin>>activerent;
    }
    else if(choice==1)
    {
        cout<<"1.活期存款****************"<<endl;
        cout<<"1.1建立银行利率表**********"<<endl;
        cout<<"1.2插入新的利率***********"<<endl;
        cout<<"1.3修改已有利率**********"<<endl;
        cout<<"1.4删除某些利率***********"<<endl;
        cout<<"请输入选择****************"<<endl;
        cin>>m;
        switch(m)
        {
            case 1:
            {
            cout<<"1.1建立银行利率表**********"<<endl;
            createlist(l);
            break;
            }
            case 2:
            {
                cout<<"1.2插入新的利率***********"<<endl;
                insert(l);
                break;
            }
            case 3:
            {
                 cout<<"1.3修改已有利率**********"<<endl;
                 renew(l);
                 break;
            }
            case 4:
            {
                cout<<"1.4删除某些利率***********"<<endl;
                deletel(l);
                break;
            }

        }

    }
    else if(choice==3)
    {
        cout<<"3.显示利率表************"<<endl;
        display(l);
    }
    else if(choice==2)
    {
        int i=0;
         cout<<"2本息计算***************"<<endl;
         int d;
         double cash,money;
         cout<<"请输入存款金额"<<endl;
         cin>>cash;
         cout<<"请输入存款时长"<<endl;
         cin>>d;
         while(i<=l.last)
         {
             if(l.b[i].date==d)
             {
                 money=cash+cash*l.b[i].rent;
                 cout<<"本金和为"<<money;
                 break;
             }
             else
             i++;
         }
    }
    else if(choice==4)
    {

        break;
    }
    }
}
