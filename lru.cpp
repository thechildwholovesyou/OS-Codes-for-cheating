#include<stdio.h>


int findLRU(int arr[],int n)
{
	int mini=arr[0], pos=0;
	for(int i=1;i<n;i++)
	{
		if(arr[i]<mini)
		{
			mini=arr[i];
			pos=i;
		}
	}
	return pos;
}

int main()
{
	int n;
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

    int flag1=0, flag2=0;
    int pageFault=0;
    int count=0;
    int times[fSize];

    for(int i=0;i<n;i++)
    {
    	flag1=flag2=0;
    	for(int j=0;j<fSize;j++)
    	{
    		if(frames[j]==ref_string[i])
    		{
    			count++;
    			times[j]=count;
    			flag1=flag2=1;
    			break;
    		}
    	}
    	if(flag1==0)
    	{
    		for(int j=0;j<fSize;j++)
    		{
    			if(frames[j]==-1)
    			{
    				count++;
    				pageFault++;
    				frames[j]=ref_string[i];
    				times[j]=count;
    				flag2=1;
    				break;
    			}
    		}
    	}
    	if(flag2==0)
    	{
    		int pos=findLRU(times,fSize);
    		count++;
    		pageFault++;
    		frames[pos]=ref_string[i];
    		times[pos]=count;
    	}
    }
    printf("\n\nTotal Page Faults = %d", pageFault);
    return 0;

}