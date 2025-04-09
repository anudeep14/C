/*
insertion sort - 
in-place comparision based sorting algrorithm
a sub sorted list is maintaied
new element trying to enter this array has to find a suitable place and be inserted there hence the name "insertion" sort.
time complexity : O()
space complexity : O()
*/


#include <stdio.h>

void ascendingInsertionSort(int arr[], int size)
{
    for(int i = 1 ; i < size ; ++i) //start with second element
    {
        int target = arr[i]; // the target element that we want to insert
        int j = i - 1;
        while(j >= 0 && arr[j] > target) // to shift bigger elements to right
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = target; // insert our target element
    }

    for(int i = 0 ; i < size ; ++i)
        printf("%d\t", arr[i]);
    printf("\n");
}

void descendingInsertionSort(int arr[], int size)
{
    for(int i = 1 ; i < size ; ++i) //start with second element
    {
        int target = arr[i]; // the target element that we want to insert
        int j = i - 1;
        while(j >= 0 && arr[j] < target) // to shift bigger elements to right
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = target; // insert our target element
    }

    for(int i = 0 ; i < size ; ++i)
        printf("%d\t", arr[i]);
    printf("\n");
}

int main()
{
    int arr[10] = {1, 3, 2, 5, 8, 6, 9, 7, 4, 10};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    ascendingInsertionSort(arr, arrSize);

    descendingInsertionSort(arr, arrSize);
}