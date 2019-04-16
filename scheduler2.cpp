 #include<stdio.h>
 #include<string.h>

struct process{
	char pid[10];
	int arrival_time;
	int burst_time;
	int rem_burst_time;
	int turnaround_time;
	int waiting_time;
	int completition_time;
};

int main()
{	
	int p;
	printf("Enter number of processes\n");
	scanf("%d",&p);
	struct process pr[p];
	printf("Enter Process ID, Arrival Time and Burst time respectively for all processes\n");
	for(int i=0;i<p;i++)
	{
		scanf("%s",&pr[i].pid);
		scanf("%d",&pr[i].arrival_time);
		scanf("%d",&pr[i].burst_time);
		for(int x=0;x<i;x++)
			if(strcmp(pr[i].pid,pr[x].pid)==0)
			{
				printf("Process IDs cannot be same!!! Enter this process's data again'\n");
				i--;
				
			}
		if(pr[i].burst_time<0||pr[i].arrival_time<0)
		{
			printf("!!!!!Invalid process entry/entries\n Enter this process data again\n");
			i--;
		}
		else
		{
		pr[i].rem_burst_time=pr[i].burst_time;
		}
		
	}
	struct process temp;
	
	for(int i=0;i<p;i++)
	{
	
        for (int j = i + 1; j < p; ++j)
        {
 
        	if (pr[i].arrival_time > pr[j].arrival_time) 
            {
 
                    temp =  pr[i];
                    pr[i] = pr[j];
                    pr[j] = temp;

            }
 
        }
 
	}
	

	
	// finding total burst time
	
	int tbt = 0;
	for(int i=0;i<p;i++)
		tbt = tbt + pr[i].burst_time;
		
	
	// finding minimum arrrival time
	
	
    int min_arr_time = pr[0].arrival_time;
   
    for (int i = 1; i < p; i++)
    {
        if (pr[i].arrival_time < min_arr_time)
        {
           min_arr_time = pr[i].arrival_time;
        }
    }
   
	printf("\n\nTime index \t\t Execution remark\n---------\t\t---------------------\n");

		// processing 
		int s=min_arr_time;
	int RQ1[p],k1=-1,index=0,tempx,minimum,e=0;
	char ppid[10];
	for(int i=min_arr_time;i<min_arr_time+tbt;i++)
	{	
	
		//managing ready queue
		
		for(int j=0;j<p;j++)
		{
			if(pr[j].arrival_time==i) //SRTF
			{
				k1++;
				RQ1[k1]=j;
			}
		}
		
			
		if(k1<0)
		{
			if(e!=0){
				
				printf("%d-%d\t\t\t",s,i);
							s=i;
						printf("(SRTF) Executing : %s\n",ppid);
			printf("----------Empty Ready Queue, IDLE CPU!!-----------\n");
			}
			e=0;
			s++;
			tbt++;
		continue;
		}
		else if(k1>=0) // SRTF
		{		
		
			//finding process with minimum remaining burst time
			
			if(i==min_arr_time)
			{
		    minimum = pr[RQ1[0]].rem_burst_time;
		   	index = 0;
		   	}
		   	
		    for (int z = 1; z <=k1; z++)
		    {
		        if (pr[RQ1[z]].rem_burst_time < minimum)
		        {
		           minimum = pr[RQ1[z]].rem_burst_time;
				index = z;
		        }
		    }	
		    
			if(e==0)
			{
		    strcpy(ppid,pr[RQ1[index]].pid);
		    e++;
		   	}
			
		
		
			//executing process
				if(strcmp(ppid,pr[RQ1[index]].pid)!=0)
				{
							printf("%d-%d\t\t\t",s,i);
							s=i;
						printf("(SRTF) Executing : %s\n",ppid);
						strcpy(ppid,pr[RQ1[index]].pid);
				}
				else if(i==min_arr_time+tbt-1)
				{
						printf("%d-%d\t\t\t",s,i+1);
						printf("(SRTF) Executing : %s\n",ppid);
				}
				
				
				 pr[RQ1[index]].rem_burst_time =  pr[RQ1[index]].rem_burst_time-1;
				 minimum = pr[RQ1[index]].rem_burst_time;
			 //remaing burst time decremented
			 
			 
			 	
			 if(pr[RQ1[index]].rem_burst_time<=0)
			 {
				  pr[RQ1[index]].completition_time = i+1;
			 	 for(int z=index;z<k1;z++)
			 	 {
			 	 	RQ1[z]=RQ1[z+1];
				 }
				 k1--;
				minimum = pr[RQ1[0]].rem_burst_time;
		   		index = 0;
			 }	
		
		
		}
		
	}
			//finding turnaround time
	for(int i=0;i<p;i++)
	pr[i].turnaround_time = pr[i].completition_time - pr[i].arrival_time;
	
	//finding waiting time
	for(int i=0;i<p;i++)
	pr[i].waiting_time = pr[i].turnaround_time - pr[i].burst_time;
	
	//displaying data
	printf("\n\nProcess ID \t Arrival Time \t Burst Time \t Completion time \t Turnaround time \t Waiting time\n----------- \t ----------- \t ---------- \t --------------- \t ---------------- \t -------------\n");
	for(int i=0;i<p;i++)
	{
		printf("%s \t\t %d \t\t %d \t\t %d \t\t\t %d \t\t\t %d \n",pr[i].pid,pr[i].arrival_time,pr[i].burst_time,pr[i].completition_time,pr[i].turnaround_time,pr[i].waiting_time);
	}
	
	int sum=0;
	float avg_wt,avg_tat;
	//calculating average waiting time
	for(int x=0;x<p;x++)
	{
		sum=sum + pr[x].waiting_time;
	}
	avg_wt = (float)sum/p;
	sum = 0;
	
		//calculating average turn around time
	for(int x=0;x<p;x++)
	{
		sum=sum + pr[x].turnaround_time;
	}
	avg_tat = (float)sum/p;
	
	printf("\n\n Average waiting time : %.2f \n Average Turnaround time : %.2f",avg_wt,avg_tat);
	return 0;
}
