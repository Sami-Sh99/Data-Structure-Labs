#include "function.h"

void main()
{
	systemQ t;
	process p;
	element e,n;
	int choice,i;
	create_system(t);
	
	printf("\n**Automatically Filling %d process having %d priorities**\n",M,N);
	srand((unsigned ) time (NULL));
	for(i=0;i<M;i++)
	{
		n=rand()%N;
		p=rand();
		EnQueue(&t[n],p);
	}
		
	while(1)
	{
printf("\nGive\tfor\n  1\tdisplay the content of the system\n  2\tadd a process\n  3\tdelete the process havng the greatest priority\n  4\tGive the number of processes with priority i \n  5\tExhcnage processes of priority i and j\n  0\tquit\n");
		scanf("%d",&choice);
		
		if(choice==0) 
			break;
		switch(choice)
		{
			case 1:printf("\n**Displaying the processes**\n");
				display(t);
				break;
			case 2:printf("\n**Add a process**\n");
				printf("Give a process number: ");
				scanf("%d",&p);
				printf("Give a priority: ");
				scanf("%d",&e);				
				if(add(t, p, e))
					printf("**Add succeeded**\n");
				else
					printf("**!!Add Failed **\n**ERROR: Verify the priority**\n");
				break;
			case 3:printf("\n**Delete the process with the highest priority**\n");
				if(deletePri(t))
					printf("**Delete succeeded**\n");
				else
					printf("**!!Delete Failed**\n**ERROR: Empty System**\n");
				break;
			case 4:printf("\n**Processes having priority i**\n");
				printf("Give a priority: ");
				scanf("%d",&e);
				printf("Number of processes having priority %d is %d\n",e,nb_elements(t[e]));
				break;
			case 5:printf("\n**Exchange proceesses i and j**\n");
				printf("Give priority i: ");
				scanf("%d",&e);
				printf("Give priority j: ");
				scanf("%d",&n);
				exchange(e,n,t);
				printf("**Exchange terminated\n");
				break;			
		}
	}
}