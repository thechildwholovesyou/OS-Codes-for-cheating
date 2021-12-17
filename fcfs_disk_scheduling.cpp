#include<stdio.h>
#include<stdlib.h>
int main()
{
    int total_head_movement=0;
    int initial_pos;
    int n;
    scanf("%d",&n);
    int request_queue[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&request_queue[i]);
    }
    scanf("%d",&initial_pos);

    for(int i=0;i<n;i++)
    {
        total_head_movement+=abs(initial_pos-request_queue[i]);
        initial_pos=request_queue[i];
    }
    printf("Total head Movements %d\n",total_head_movement);
    printf("Average Head movements %.2f\n",(float)total_head_movement/n);

    return 0;
}