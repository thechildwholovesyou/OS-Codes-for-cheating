#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int minelement(int n,int arr[])
{
    int res = arr[0];
    for (int i = 1; i < n; i++)
        {
            if(arr[i]<res)
                res=arr[i];
        }
    return res;
}
int maxelement(int n,int arr[])
{
    int res = arr[0];
    for (int i = 1; i < n; i++)
        {
            if(arr[i]>res)
                res=arr[i];
        }
    return res;
}
int main()
{
    int total_disk_size;
    scanf("%d",&total_disk_size);

    int n;
    scanf("%d",&n);

    int request_queue[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&request_queue[i]);
    }
    int initial_pos;
    scanf("%d",&initial_pos);

    int dir;
    scanf("%d",&dir);

    int total_head_movement=0;
    if(dir==1) 
    {
        total_head_movement=((total_disk_size-1)-(initial_pos))+((total_disk_size-1)-(minelement(n,request_queue)));
    }
    else if(dir==0)
    {
        total_head_movement=(initial_pos-0)+maxelement(n,request_queue);
    }
    printf("%d",total_head_movement);
}