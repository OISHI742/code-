#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    struct timespec starts,ends;

    int n1;
    scanf("%d",&n1);
    int i,j;
    int *arr1[n1];
    int *inarr,*outarr;
    int in_degree=0,out_degree=0;

    long long time1=0;

    in_degree=0,out_degree=0;
    inarr = (int *)malloc(n1 * sizeof(int));
    outarr = (int *)malloc(n1 * sizeof(int));

    for (i=0; i<n1; i++)
    {
        arr1[i] = (int *)malloc(n1 * sizeof(int));
    }

    for(i=0; i<n1; i++)
    {
        inarr[i]=0;
        outarr[i]=0;
        for(j=0; j<n1; j++)
        {
            arr1[i][j]=rand()%2;
        }
    }

    clock_gettime( CLOCK_REALTIME, &starts) ;

    for(i=0; i<n1; i++)
    {
        for(j=0; j<n1; j++)
        {
            if(arr1[i][j]==1)
            {
                inarr[i]++;
            }
        }
    }


    for(i=0; i<n1; i++)
    {
        for(j=0; j<n1; j++)
        {
            if(arr1[i][j]==1)
            {
                outarr[j]++;
            }
        }
    }

    clock_gettime( CLOCK_REALTIME, &ends);

    for(i=0; i<n1; i++)
    {
        for(j=0; j<n1; j++)
        {
            printf("%d",arr1[i][j]);
        }
    }

    for(i=0; i<n1; i++)
    {
        in_degree+=inarr[i];
        out_degree+=outarr[i];
    }


    time1=(ends.tv_sec-starts.tv_sec)*1000000+(ends.tv_nsec-starts.tv_nsec);

    printf("\nTotal In-degree: %6d \tTotal Out-degree: %6d\t for input n=%d\n",in_degree,out_degree,n1);
    printf("Total time : %ld ms\n",time1);

}
