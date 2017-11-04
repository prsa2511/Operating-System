#include<conio.h>
#include<stdio.h>
void main()
{
    int i,ct,p[50][50],n;
    clrscr();
    printf("Enter the no. of processes\n");
    scanf("%d",&n);
    printf("Enter arrival time and burst time for each process\n");
    for(i=1;i<=n;i++)
    {
      p[i][0]=i;
      scanf("%d%d",&p[i][1],&p[i][2]);
    }
    printf("Entered processes are:\nPid\tAT\tBT\n");
    for (i=1;i<=n; i++)
	printf("%d\t%d\t%d\n",p[i][0],p[i][1],p[i][2] );
    ct=0;
    for(i=1;i<=n;i++)
    {
      ct=ct+p[i][2]; //Completion time
      p[i][3]=ct;
    }
    for(i=1;i<=n;i++)
      p[i][4]=p[i][3]-p[i][1];//TAT=CT-AT
    for(i=1;i<=n;i++)
      p[i][5]=p[i][4]-p[i][2];//WT=TAT-BT
    printf("The scheduled processes are:\nPid\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=1;i<=n;i++)
      printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i][0],p[i][1],p[i][2],p[i][3],p[i][4],p[i][5]);
    getch();
}
