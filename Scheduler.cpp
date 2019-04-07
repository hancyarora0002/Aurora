#include<stdio.h>


int main()
{	
	int p;
	printf("Enter number of processes\n");
	scanf("%d",&p);
	fflush(stdin);
	
	int p1[p][3]; 
	printf("Enter Arrival-Time,Burst-Time and Queue no. respectively for all %d processes\n",p);
	for(int i=0;i<p;i++)
		for(int j=0;j<3;j++)
		{
			//fflush(stdin);
			scanf("%d",&p1[i][j]);
			
		}	
		
		
	int t=0,tn=0;
	for(int i=0;i<p;i++)
	tn=tn+a[i][1];
	int rq[p],rbt[p];
	int x=0;
	for(t=0;t<tn;t++)
	{
		for(int i=0;i<p;i++)
		if(p1[i][0]==t)
		{
		rq[x]=i;x++;
		}
		
		for(int i=0;i<x;i++)
			
	}	
	return 0;
}
