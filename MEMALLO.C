#include<stdio.h>
#include<conio.h>
#include<math.h>

int min(int avail[10],int b[10])
{
  int i,j,min;
  min=avail[0];
  for(i=0;i<sizeof(avail);i++)
  {
    if(avail[i]<=min)
    {
      min=avail[i];
    }
  }
    for(j=0;j<5;j++)
    {
      if(b[j]==min)
       return j;
    }
  return -1;
}
int max(int b[10])
{
  int i,pos,max;
  max=b[0];
  for(i=0;i<5;i++)
  {
    if(b[i]>=max)
    {
      max=b[i];
      pos=i;
    }
  }
  return pos;
}

void main()
{
  int i,j,ch,k,pos,avail[10];
  int flag[10]={0};
  int b[10]={100,500,200,300,600};
  int p[10]={212,417,112,426};
  clrscr();
  printf("Enter choice\n1.First Fit\t2.Best Fit\t3.Worst Fit\n");
  scanf("%d",&ch);
  switch (ch) {
  case 1:
  printf("Pid\tP.size\tBlock no.\n");
	for(i=0;i<4;i++)
	 {
	    for(j=0;j<5;j++)
	     {
			      if(p[i]<=b[j])
			  {
			      flag[i]=1;
			      printf("%d\t%d\t%d\n",i+1,p[i],j+1);
			      b[j]=b[j]-p[i];
			      break;
			  }
	      }
	 }
	 for(i=0;i<4;i++)
	  if(flag[i]==0)
	   printf("%d\t%d\tN.A.\n",i+1,p[i]);
	 break;
   case 2:
   printf("Pid\tP.size\tBlock no.\n");
	 for(i=0;i<4;i++)
	 {
	    k=0;
	    for(j=0;j<5;j++)
	    {
		      if(p[i]<=b[j])
		      {
			  avail[k]=b[j];
	      k++;
	  }
      }
	    pos=min(avail,b);
      if(p[i]<=b[pos])
      {
	flag[i]=1;
	printf("%d\t%d\t%d\n",i+1,p[i],pos+1);
	b[pos]=b[pos]-p[i];
      }
    }
    for(i=0;i<4;i++)
      if(flag[i]==0)
	printf("%d\t%d\tN.A.\n",i+1,p[i]);
    break;
    case 3:
    printf("Pid\tP.size\tBlock no.\n");
	 for(i=0;i<4;i++)
	 {
	 pos=max(b);
	 if(p[i]<=b[pos])
	 {
	   flag[i]=1;
	   printf("%d\t%d\t%d\n",i+1,p[i],pos+1);
	   b[pos]=b[pos]-p[i];
       }
     }
     for(i=0;i<4;i++)
       if(flag[i]==0)
	 printf("%d\t%d\tN.A.\n",i+1,p[i]);
     break;
}
  getch();
}
