 #include<stdio.h>

struct process{
	int pid;
	int arrival_time;
	int burst_time;
	int rem_burst_time;
	int priority_queue;
	int turnaround_time;
	int waiting_time;
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
	
	/*printf("Process ID \t Arrival Time \t Burst Time \n");
	for(int i=0;i<p;i++)
	{
		printf("%d \t\t %d \t\t %d \n",pr[i].pid,pr[i].arrival_time,pr[i].burst_time);
	}
	*/

	
	return 0;
}
