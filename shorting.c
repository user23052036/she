#include"shorting.h"

void bubble_a(int *arr, int limit)
{
    for(int round=0; round<limit; round++)
    {
        for(int i=0; i<limit-round-1; i++)
        {
            if(arr[i]>arr[i+1])
            {
                arr[i]=arr[i]+arr[i+1];
                arr[i+1]=arr[i]-arr[i+1];
                arr[i]=arr[i]-arr[i+1];
            }
        }
    }
}

void bubble_d(int *arr, int limit)
{
    for(int round=0; round<limit; round++)
    {
        for(int i=0; i<limit-round-1; i++)
        {
            if(arr[i]<arr[i+1])
            {
                arr[i]=arr[i]+arr[i+1];
                arr[i+1]=arr[i]-arr[i+1];
                arr[i]=arr[i]-arr[i+1];
            }
        }
    }
}