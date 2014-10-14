//二叉排序树
#include<iostream>  
#include<cstdio>  
#include<cstdlib>  
using namespace std;  
struct node  
{  
    int key;  
    node *lc;  
    node *rc;  
};  
void Insert(int x,node *&p)  
{  
    if(p==NULL)  
    {  
        p=new node;  
        p->key=x;  
        p->lc=NULL;  
        p->rc=NULL;  
    }  
    else if(p->key>x)  
        Insert(x,p->lc);  
    else if(p->key<x)  
        Insert(x,p->rc);  
    else if(p->key==x)return ;  
}  
node* create(int n)  
{  
    int a;  
    node* F=NULL;  
    while(n--)  
    {  
        cin >>a;  
        Insert(a,F);  
    }  
    return F;  
}  
void pre_order(node * p)  
{  
    if(p!=NULL)  
    {  
        cout << p->key << " ";  
        pre_order(p->lc);  
        pre_order(p->rc);  
    }  
}  
void in_order(node * p)  
{  
    if(p!=NULL)  
    {  
        in_order(p->lc);  
        cout << p->key << " ";  
        in_order(p->rc);  
    }  
}  
void post_order(node * p)  
{  
    if(p!=NULL)  
    {  
        post_order(p->lc);  
        post_order(p->rc);  
         cout << p->key << " ";  
    }  
}  
void Free(node * p)  
{  
    if(p!=NULL)  
    {  
        Free(p->lc);  
        Free(p->rc);  
        free(p);  
    }  
}  
int main()  
{  
    int n;  
    while(scanf("%d",&n)!=EOF)  
    {  
        node *R=create(n);  
        pre_order(R);  
        cout << endl;  
        in_order(R);  
        cout << endl;  
        post_order(R);  
        cout << endl;  
        Free(R);  
    }  
    return 0;  
}  

/htfvgktyggybouyhju
