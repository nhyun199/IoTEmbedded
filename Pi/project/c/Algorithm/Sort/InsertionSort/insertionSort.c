#include <stdio.h>
#include <string.h>
#include "insertionSort.h"

void InsertionSort(int *arr, int length)
{
    for(int i = 1; i < length; i++)
    {
        int temp = 0;

        if(arr[i-1] <= arr[i])
            continue;

        temp = arr[i];

        for(int j = 0; j < i; j++)
        {
            if(arr[j] > temp)
            {
                memmove(&arr[j+1], &arr[j], sizeof(arr[0])*(i-j));
                arr[j] = temp;
                break;
            }
        }
    }
}