
#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
    int n,k,a,b;
    char op2,op1;
    const double PI=acos(-1.0);
    double x[25],y[25],l,X,Y=0,yy;
    printf("选择函数：\n若f(x)=1/(1+x*x),输入a;\n若f(x)=e^x,输入b;\n若f(x)=x^0,5,输入c.\n");
    printf("选择插值方式：\n若等距插值，输入a;\n若非等距插值，输入b;\n若特定值，输入c\n输入n\n");
    scanf("%c %c %d",&op2,&op1,&n);
    if(op1=='a')
    {
        printf("输入x区间[a,b]\n");
        scanf("%d%d",&a,&b);
    }
    for(k=0;k<=n;k++)
    {
        if(op1=='a')x[k]=a+k*1.0/n*(b-a);
        if(op1=='b')x[k]=cos((2*k+1)*PI/(2*(n+1)));
        if(op1=='c')scanf("%lf",&x[k]);
        switch(op2)
        {
            case'a':
                y[k]=1/(1+x[k]*x[k]);
                break;
            case'b':
                y[k]=exp(x[k]);
                break;
            case'c':
                y[k]=sqrt(x[k]);
                break;
        }
    }
    printf("输入要计算的x,输入-1结束\n");
    do
    {
        Y=0;
        scanf("%lf",&X);
        for(k=0;k<=n;k++)
        {
            l=1.0;
            for(int j=0;j<=n;j++)
            {
                if(j!=k)
                {
                    l=l*(X-x[j])/(x[k]-x[j]);
                }
            }
            Y=Y+l*y[k];
        }
        switch(op2)
        {
            case'a':
                yy=1/(1+X*X);
                break;
            case'b':
                yy=exp(X);
                break;
            case'c':
                yy=sqrt(X);
                break;
        }
    printf("X=%.4f Pn(x)=%.4f F(x)=%.4f\n",X,Y,yy);
    }while(X!=-1);
    return 0;
}
