#include"sosa.h"

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

void selection_a(int *arr,int size)
{
    for(int i=0; i<size-1; i++)
    {
        int loc = min_num(arr,i,size,0);
        arr[i] = arr[loc] + arr[i];
        arr[loc] = arr[i] - arr[loc];
        arr[i] = arr[i] - arr[loc];
    }
}

void selection_d(int *arr,int size)
{
    for(int i=0; i<size-1; i++)
    {
        int loc = min_num(arr,i,size,1);
        arr[i] = arr[loc] + arr[i];
        arr[loc] = arr[i] - arr[loc];
        arr[i] = arr[i] - arr[loc];
    }
}

int min_max_num(int *arr, int i, int size, int flag)
{
    int loc=i;
    for(int j=i+1; j<size; j++)
    {
        if(arr[loc]>arr[j] && flag==0)
            loc=j;
        if(arr[loc]<arr[j] && flag==1)
            loc=j;
    }
    return loc;
}

void merge_sort_a(int *arr, int low, int high)
{
    if(low>=high) return;
    int mid = (low+high)/2;

    merge_sort_a(arr,low,mid);
    merge_sort_a(arr,mid+1,high);
    merge(arr,low,mid,high,0);
}

void merge_sort_d(int *arr, int low, int high)
{
    if(low>=high) return;
    int mid = (low+high)/2;

    merge_sort_a(arr,low,mid);
    merge_sort_a(arr,mid+1,high);
    merge(arr,low,mid,high,1);
}

void merge(int *arr, int low, int mid, int high, int flag)
{
    int *temp = (int*)malloc((high-low+1)*sizeof(int));
    int *ptr1=&arr[low], *ptr2=&arr[mid+1];
    int count=0;

    while(ptr1<=&arr[mid] && ptr2<=&arr[high] && flag==0)
    {
        if(*ptr1>=*ptr2)
        {
            temp[count++]=*ptr2;
            ptr2++;
        }
        else
        {
            temp[count++]=*ptr1;
            ptr1++;
        }
    }
    while(ptr1<=&arr[mid] && ptr2<=&arr[high] && flag==1)
    {
        if(*ptr1<=*ptr2)
        {
            temp[count++]=*ptr2;
            ptr2++;
        }
        else
        {
            temp[count++]=*ptr1;
            ptr1++;
        }
    }
    while(ptr1<=&arr[mid])
    {
        temp[count++]=*ptr1;
        ptr1++;
    }
    while(ptr2<=&arr[high])
    {
        temp[count++]=*ptr2;
        ptr2++;
    }

    for(int i=low; i<=high; i++)
        arr[i]=temp[i-low];
    free(temp);
}

void quick_sort_a(int *arr, int low, int high)
{
    if(low>=high)
        return;

    int choice = arr[low],r8_indx;
    r8_indx = correct_pos(arr,choice,low,high);
    quick_sort_a(arr,low,r8_indx-1);
    quick_sort_a(arr,r8_indx+1,high);
}

void quick_sort_d(int *arr, int low, int high)
{
    if(low>=high)
        return;

    int choice = arr[low],r8_indx;
    r8_indx = correct_pos(arr,choice,low,high);
    quick_sort_d(arr,low,r8_indx-1);
    quick_sort_d(arr,r8_indx+1,high);
}

int correct_pos_a(int *arr, int choice, int low, int high)
{
    int i=low, j=high;

    while(i<j)
    {
        while(arr[i]<=choice && i<high)i++;
        while(arr[j]>choice && j>low)j--;
        if(i<j)switch_num(&arr[i],&arr[j]);
    }
    switch_num(&arr[choice],&arr[j]);
}

int correct_pos_d(int *arr, int choice, int low, int high)
{
    int i=low, j=high;

    while(i<j)
    {
        while(arr[i]>=choice && i<high)i++;
        while(arr[j]<choice && j>low)j--;
        if(i<j)switch_num(&arr[i],&arr[j]);
    }
    switch_num(&arr[choice],&arr[j]);
}

void switch_num(int *p, int *q) // i dont know why but this function is wrong
{
    *p = *p + *q;
    *q = *p - *q;
    *p = *p - *q;
}

int binary_search(int *arr, int num, int low, int high)    // sort first before calling
{
    int mid = (low+high)/2;
    if(num==arr[mid])       //base case 1
        return mid;
    if(low>high)           //base case 2
        return -1;

    if(num>arr[mid])
        binary_search(arr,num,low,mid-1);
    else
        binary_search(arr,num,mid+1,high);
}