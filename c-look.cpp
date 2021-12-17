#include<stdio.h>

int endValueR(int n, int arr[],int initial_pos)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        if(arr[i]>initial_pos)
            break;
    }
    return arr[i-1];
}
int endValueL(int n, int arr[],int initial_pos)
{
    int i=0;
    for(i=n-1;i>=0;i--)
    {
        if(arr[i]<initial_pos)
            break;
    }
    return arr[i+1];
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
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(request_queue[j]>request_queue[j+1])
            {
                int temp=request_queue[j];
                request_queue[j]=request_queue[j+1];
                request_queue[j+1]=temp;
            }
        }
    }
    int total_head_movement=0;
    int mini = request_queue[0];
    int maxi= request_queue[n-1];

    if(dir==1)
    {
         total_head_movement=(maxi-initial_pos) + (maxi-mini)+(endValueR(n,request_queue,initial_pos)-mini);
    }
    else 
    {
        total_head_movement=(initial_pos-mini)+(maxi-mini)+(maxi-endValueL(n,request_queue,initial_pos));
    }
   
    printf("%d",total_head_movement);
}