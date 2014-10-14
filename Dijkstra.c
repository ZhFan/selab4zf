//Dijkstra  
#include<iostream>  
#include<cstdio>  
#include<cstdlib>  
#include<cstring>  
#include<string>  
#define INF 0x3f3f3f3f  
using namespace std;  
struct node  
{  
    int d,p;  
} mat[1010][1010];  
int main()  
{  
    int x,y,n,m,a,b,s,t,i,j,k,d[1005],p[1005],minsd,minsp,visited[1005];  
    while(scanf("%d%d",&n,&m)!=EOF&&(n!=0||m!=0))  
    {  
        memset(visited,0,sizeof(visited));  
        for(i=1; i<=n; i++)  
            for(j=1; j<=n; j++)  
            {  
                mat[i][j].d=INF;  
                mat[i][j].p=INF;  
            }//初始化矩阵  
        for(i=1; i<=m; i++)  
        {  
            cin >> a >> b >> x >> y;//注意，把重复的边去掉，在这里WA两次  
            if(x < mat[a][b].d || (x == mat[a][b].d && y < mat[a][b].p))  
            {  
                mat[a][b].d = mat[b][a].d = x;  
                mat[a][b].p = mat[b][a].p = y;  
            }  
        }  
        cin >> s >> t;  
        visited[s]=1,d[s]=0;  
        for(i=1; i<=n; i++)  
        {  
            d[i]=mat[s][i].d;  
            p[i]=mat[s][i].p;  
        }//距离的初始化  
        for(i=1; i<n; i++)  
        {  
            minsp=minsd=INF;  
            for(j=1; j<=n; j++)  
                if(!visited[j]&&minsd>d[j])  
                {  
                    minsd=d[j];  
                    minsp=p[j];  
                    k=j;  
                }//找出最小的边到达的顶点，和prim一样，贪心  
            visited[k]=1;  
            for(j=1; j<=n; j++)  
                if(!visited[j] && mat[k][j].d!=INF)  
                {  
                    if(d[k]+mat[k][j].d<d[j])  
                    {  
                        d[j]= d[k]+mat[k][j].d;  
                        p[j]= p[k]+mat[k][j].p;  
                    }  
                    else if(d[k]+mat[k][j].d==d[j]&&p[k]+mat[k][j].p<p[j])  
                        p[j]= p[k]+mat[k][j].p;  
                    else ;  
                }//更新到达的距离，由于不止要选择距离小，要选择话费小的，所以要判断两次  
        }  
        cout << d[t] << " " << p[t] << endl;  
    }  
    return 0;  
}  
