#include"shorting.h"

void bubble_a(int *arr, int limit)
{
    int flag=0;
    for(int round=0; round<limit; round++)
    {
        for(int i=0; i<limit-round-1; i++)
        {
            if(arr[i]>arr[i+1])
            {
                flag=1;
                arr[i]=arr[i]+arr[i+1];
                arr[i+1]=arr[i]-arr[i+1];
                arr[i]=arr[i]-arr[i+1];
            }
        }
        if(flag==0)
            break;
        flag=0;
    }
}

void bubble_d(int *arr, int limit)
{
    int flag=0;
    for(int round=0; round<limit; round++)
    {
        for(int i=0; i<limit-round-1; i++)
        {
            if(arr[i]<arr[i+1])
            {
                flag=1;
                arr[i]=arr[i]+arr[i+1];
                arr[i+1]=arr[i]-arr[i+1];
                arr[i]=arr[i]-arr[i+1];
            }
        }
        if(flag==0)
            break;
        flag=0;
    }
}

void insertion_a(int *arr, int length)
{
    int temp,j;
    for(int i=1; i<length; i++)
    {
        temp=arr[i];
        for(j=i-1; j>=0&&arr[j]>temp; j--)  
        {
            arr[j+1]=arr[j];
        }
        arr[j+1]=temp;
    }
}

void insertion_d(int *arr, int length)
{
    int temp,j;
    for(int i=1; i<length; i++)
    {
        temp=arr[i];
        for(j=i-1; j>=0&&arr[j]<temp; j--)  
        {
            arr[j+1]=arr[j];
        }
        arr[j+1]=temp;
    }
}