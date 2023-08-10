#include<stdio.h>
#include<stdlib.h>

int main()
{
    int RQ[100],i,n,TotalHeadMoment=0,initial;
    printf("Enter the number of Requests\n");
    scanf("%d",&n); 
    printf("Enter the Requests sequence\n");
    for(i=0;i<n;i++)
        scanf("%d",&RQ[i]);
    printf("Enter the initial head position\n");
    scanf("%d",&initial);

    //logic for fcfs disk scheduling

    printf("Sequence of request acess:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",RQ[i]);
        TotalHeadMoment = TotalHeadMoment + abs(RQ[i]-initial);
        initial = RQ[i];
    }
    printf("\nTotal head moment is %d\n",TotalHeadMoment);
    return 0;
}

/*Enter the number of Requests
7
Enter the Requests sequence
82 170 43 140 24 16 190
Enter the initial head position
50
Sequence of request acess:
82 170 43 140 24 16 190 
Total head moment is 642
*/
