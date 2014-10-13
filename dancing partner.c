#include <iostream>
using namespace std;
#define maxsize 100
typedef struct{
char name[30];
char sex;
}person;
struct QUEUE{
person per[maxsize];
int front;
int rear;
};
void makenull(QUEUE &q)
{
    q.rear=q.front=0;
}
bool empty(QUEUE q)
{
    if(q.rear==q.front)
    return true;
    else
    return false;
}
void enqueue(QUEUE &q,person p)
{

   // q.rear=(q.rear+1)%maxsize;
    q.per[q.rear]=p;
      q.rear=(q.rear+1)%maxsize;
}
void dequeue(QUEUE &q)
{
//q.front=(q.front+1)%maxsize;
   cout<<q.per[q.front].name;
    q.front=(q.front+1)%maxsize;
}
person qfront(QUEUE q)
{
    return q.per[q.front];
}
void dancepartner(person dancer[],int num)
{
    int i;
    person p,h;
    QUEUE wdancer,mdancer;//women舞者,man舞者
    makenull(wdancer);
    makenull(mdancer);
    for(i=0;i<num;i++)
    {
        p=dancer[i];
        if(p.sex=='w')
        enqueue(wdancer,p);
        else if(p.sex=='m')
        enqueue(mdancer,p);
    }
    while(!empty(wdancer)&&!empty(mdancer))
    {
        cout<<"已找到相应舞伴的人为"<<endl;
        dequeue(wdancer);
        dequeue(mdancer);
        cout<<endl;
    }
    if(!empty(wdancer))
    {
        cout<<"女士剩余人数为"<<endl;
        cout<<wdancer.rear-wdancer.front<<endl;
        h=qfront(wdancer);
        cout<<"等待的第一位为"<<endl;
        cout<<h.name;
        cout<<endl;
    }
    else if(!empty(mdancer))
    {
        cout<<"男士剩余人数为"<<endl;
        cout<<mdancer.rear-mdancer.front<<endl;
        h=qfront(mdancer);
        cout<<"等待的第一位为"<<endl;
        cout<<h.name;
        cout<<endl;
    }
}
int main()
{
    person dancer[maxsize];

    int num;
    cout<<"舞者的人数为"<<endl;
    cin>>num;
    for(int i=0;i<num;i++)
    {
        cin>>dancer[i].sex;
        cin>>dancer[i].name;
    }
    dancepartner(dancer,num);
}
