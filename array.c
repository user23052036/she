#include"array.h"

void insert(int *arr, int pos, int num, int size)
{
    int i;
    for(i=size-1; i>=pos; i--)
        arr[i]=arr[i-1];
    arr[i]=num;
}

void del(int *arr, int pos, int size)
{
    int i;
    for(i=pos; i<size; i++)
        arr[i-1]=arr[i];
    arr[i-1]=0;
}

int l_search(int *arr, int num, int size)
{
    for(int i=0; i<size; i++)
    {
        if(arr[i]==num)
            return i;
    }
    return -1;
}

int if_pallindrome(int *arr, int size)
{
    for(int i=0; i<size/2; i++)
    {
        if(arr[i] != arr[size-1-i])
            return -1;
    }
    return 1;
}

int* merge(int *t_arr, int *arr1, int *arr2, int size1, int size2)
{
    int i;
    t_arr = malloc((size1+size2)*sizeof(int));

    for(i=0; i<size1; i++)
        t_arr[i]=arr1[i];
    for(i; i<size1+size2; i++)
        t_arr[i]=arr2[i];
    
    return t_arr;
} 