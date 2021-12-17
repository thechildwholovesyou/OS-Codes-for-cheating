#include<stdio.h>
int main()
{
    int n ;// ref string size;
    scanf("%d",&n);
    int ref_string[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d", &ref_string[i]);
    }
    int fSize; // frame size
    scanf("%d",&fSize);

    int frames[fSize];
    for(int i=0;i<fSize;i++)
    {
        frames[i]=-1;
    }

    int pageFault=0;
    int flag=0;
    int pos=0;
    for(int i=0;i<n;i++)
    {
        flag=0;
        for(int j=0;j<fSize;j++)
        {
            if(frames[j]==ref_string[i])
            {
                flag=1;
                break;
            }
        }
            if(flag==0)
            {
                frames[pos]=ref_string[i];
                pos++;
                pageFault++;
                if(pos>=fSize) pos=0;
            }
        
    }
    printf("Number of page fault %d\n",pageFault);
    printf("Hits %d\n",n-pageFault);
      printf("hit ratio %.2f\n",(float)(n-pageFault)/n);
    printf("miss ratio %.2f\n",(float)pageFault/n);

}