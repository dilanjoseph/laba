#include <stdio.h>

int main()
{
    int a[10][3],n,f,i,j,x,y;
    printf("Enter the no of states:");
    scanf("%d",&n);
    printf("\nEnter the final state:");
    scanf("%d",&f);
    printf("\n Enter the transitions for a & b");
    for(i=0;i<n;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<3;j++)
        {
            if(j!=f)
            {
                if(a[i][1]==a[j][1]&&a[i][2]==a[j][2])
                {
                    a[j][0]=-1;
                    for(x=0;x<n;x++)
                    {
                        for(y=0;y<3;y++)
                        {
                            if(a[x][y]==j)
                            {
                                a[x][y]=i;
                            }
                        }
                    }
                }
            }
        }
    }
    printf("\nMinimized DFA\n");
    printf("State\ta\tb\n");
    for(i=0;i<n;i++)
    {
        if(a[i][0]!=-1)
        {
            for(j=0;j<3;j++)
            {
                printf("%d\t",a[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}