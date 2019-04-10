 #include<stdio.h>

struct process{
	int pid;
	int arrival_time;
	int burst_time;
	int rem_burst_time;
	int priority_queue;
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
	printf("Enter Process ID, Arrival Time, Burst time and Priority Queue respectively for all processes\n");
	for(int i=0;i<p;i++)
	{
		scanf("%d",&pr[i].pid);
		scanf("%d",&pr[i].arrival_time);
		scanf("%d",&pr[i].burst_time);
		scanf("%d",&pr[i].priority_queue);
		if(pr[i].burst_time<0||pr[i].arrival_time<0||pr[i].priority_queue<1||pr[i].priority_queue>2)
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
   
	
		
	// processing 
	
	int RQ1[p],RQ2[p],k1=0,k2=0,index;
	for(int i=min_arr_time;i<min_arr_time+tbt;i++)
	{
		//managing ready queue
		
		for(int j=0;j<p;j++)
		{
			if(pr[j].arrival_time==i&&pr[j].priority_queue==1) //SRTF
			{
				RQ1[k1]=j;k1++;
			}
			else if(pr[j].arrival_time==i&&pr[j].priority_queue==2) //Round Robin
			{
				RQ2[k2]=j;k2++;
			}
		}
	
		
		if(k1==0&&k2==0)
		{
		continue;
		}
		else if(k1!=0) // SRTF
		{
			//finding process with minimum remaining burst time
		    int minimum = pr[RQ1[0]].rem_burst_time;
		   	index = 0;
		    for (int z = 1; z < k1; z++)
		    {
		        if (pr[RQ1[z]].rem_burst_time < minimum)
		        {
		           minimum = pr[RQ1[z]].rem_burst_time;
				index = z;
		        }
		    }	
			
			
			//executing process
			
			 pr[RQ1[index]].rem_burst_time =  pr[RQ1[index]].rem_burst_time-1;
			 //remaing burst time decremented
			 
			 if(pr[RQ1[index]].rem_burst_time<=0)
			 {
				  pr[RQ1[index]].completition_time = i+1;
			 	 for(int z=index;z<k1;z++)
			 	 {
			 	 	RQ1[z]=RQ1[z+1];
				 }
				 k1--;
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
	printf("Process ID \t Arrival Time \t Burst Time \t Completion time \t Turnaround time \t Waiting time\n");
	for(int i=0;i<p;i++)
	{
		printf("%d \t\t %d \t\t %d \t\t %d \t\t\t %d \t\t\t %d \n",pr[i].pid,pr[i].arrival_time,pr[i].burst_time,pr[i].completition_time,pr[i].turnaround_time,pr[i].waiting_time);
	}
	
	
	return 0;
}
