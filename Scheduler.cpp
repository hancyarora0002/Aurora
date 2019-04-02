#include<stdio.h>

void input()
{
	int p;
	printf("Enter number of processes\n");
	scanf("%d",&p);
	
	int p1[p][2]; 
	printf("Enter Arrival-Time and Burst-Time respectively for all %d processes\n",p);
	for(int i=0;i<p;i++)
		for(int j=0;j<2;j++)
		{
			scanf("%d",&p)
		}	
}

int main()
{	
	input();
}
