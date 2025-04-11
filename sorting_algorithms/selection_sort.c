/*
selection sort : select first element as min/max, traverse the array, swap if any other min element found
time complexity : O()
space complexity : O()
*/
#include <stdio.h>

void ascendingSelectionSort(int* arr, int size)
{
    for(int i = 0 ; i < size - 1 ; ++i) // to trace the sorted list ending index
    {
        int minIndex = i; // consider first element as the least element

        for(int j = i+1 ; j < size ; ++j)
        {
            if(arr[j] < arr[minIndex]) // traversing array, replace min index if you find any other least element
            {
                minIndex = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    for(int i = 0 ; i < size ; ++i)
        printf("%d\t", arr[i]);
    printf("\n");
}

void descendingSelectionSort(int* arr, int size)
{
    for(int i = 0 ; i < size - 1 ; ++i)
    {
        int maxIndex = i;
        for(int j = i+1 ; j < size; ++j)
        {
            if(arr[j] > arr[maxIndex])
            {
                maxIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[maxIndex];
        arr[maxIndex] = temp;
    }

    for(int i = 0 ; i < size ; ++i)
        printf("%d\t", arr[i]);
    printf("\n");
}



int main()
{
    int arr[10] = {1,3,2,5,8,6,9,7,4,10};

    int arrSize = sizeof(arr) / sizeof(arr[0]);

    ascendingSelectionSort(arr, arrSize);

    descendingSelectionSort(arr, arrSize);

    return 0;
}