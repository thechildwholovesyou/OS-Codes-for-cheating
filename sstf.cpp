#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
#include<string.h>
int findClosestCylinder(int initial_pos,int request_queue[], bool vis[], int n)
{
    int mini=INT_MAX;
    int minIdx=-1;

    for(int i=0;i<n;i++)
    {
        if(vis[i]==false && abs(initial_pos-request_queue[i])<mini)
        {
            mini=abs(initial_pos-request_queue[i]);
            minIdx=i;
        }
    }
    return minIdx;
}

int applySSTF(int request_queue[], int initial_pos, int seek_sequence[], bool vis[], int n)
{
    int i=0;
    int completed=0; 
    int total_head_movement=0;
    while(completed!=n)
    {
        int minIdx=findClosestCylinder(initial_pos, request_queue, vis, n);
        total_head_movement+=abs(initial_pos-request_queue[minIdx]);
        initial_pos=request_queue[minIdx];
        seek_sequence[i++]=request_queue[minIdx];
        vis[minIdx]=true;
        completed++;
    }
    return total_head_movement;
}

int main()
{
    int total_cylinders;
    scanf("%d",&total_cylinders);

    int n; 
    scanf("%d",&n);

    int request_queue[n];
    int seek_sequence[n];

   
    for(int i=0;i<n;i++)
    {
        scanf("%d",&request_queue[i]);
    }
    
    int initial_pos;
    scanf("%d",&initial_pos);

    bool vis[n]; 
    memset(vis, false,n*sizeof(bool));

    if(initial_pos<0 || initial_pos>total_cylinders-1) return 0;

    int total_head_movement=0;
    total_head_movement=applySSTF(request_queue, initial_pos, seek_sequence, vis,n);

    
    for(int i=0;i<n;i++)
    {
        printf("%d ",seek_sequence[i]);
    }
    printf("\nTotal head movements %d", total_head_movement);

}